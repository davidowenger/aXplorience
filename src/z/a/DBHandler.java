package z.a;

import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.concurrent.ConcurrentSkipListMap;

import android.content.Context;
import android.content.SharedPreferences;

public class DBHandler
{
	public final String PREFIX = "TABLE_";
	public final String SEP = "_";
	public final String TRUE = "TRUE";
	public final String FALSE = "FALSE";

	public TWrapper w;
	public ConcurrentSkipListMap<String, DBTableHandler> maCacheTable;

	public DBHandler(TWrapper w)
	{
		this.w = w;
		maCacheTable = new ConcurrentSkipListMap<String, DBTableHandler>();
	}

	public DBTableHandler get(String table)
	{
		if (!maCacheTable.containsKey(table)) {
			DBTable dbTable = null;

			try {
				Class<?> c = Class.forName("z.a.Table" + w.dbh.SEP + table);
				Constructor<?> m = c.getConstructor();
				dbTable = (DBTable)m.newInstance();
			}
	        catch (Exception e) {
				e.printStackTrace();
	        }
			maCacheTable.put(table, new DBTableHandler(w, dbTable));
		}
		return maCacheTable.get(table);
	}
}

class DBTableHandler
{
	public TWrapper w;
	public DBTable mDBTable;
	public SharedPreferences mData;
	public SharedPreferences.Editor mDataEditor;
	public ConcurrentSkipListMap<String, Integer> maFieldIndex;
	public int mcField;
	public int mLastID;

	public DBTableHandler(TWrapper w, DBTable dbTable)
	{
		int i;

		this.w = w;
		mDBTable = dbTable;
		mData = w.context.getSharedPreferences(w.dbh.PREFIX + mDBTable.table, Context.MODE_PRIVATE);
		mDataEditor = mData.edit();
		mcField = mDBTable.aField.length;
		maFieldIndex = new ConcurrentSkipListMap<String, Integer>();

		for (i = 0 ; i < mcField ; ++i ) {
			maFieldIndex.put(mDBTable.aField[i], i);
		}
	}

	public DBObject getInstance()
	{
		return getInstance(null);
	}

	public DBObject getInstance(String id)
	{
		return new DBObject(w, this, id);
	}

	public DBCollection getCollection()
	{
		return new DBCollection(w, this);
	}

	public boolean delete(String confirm)
	{
		boolean ret = false;

		if (confirm.equals("yes")) {
			mDataEditor.clear();
			mDataEditor.commit();
			ret = true;
		}
		return ret;
	}
}

class DBObject
{
	public TWrapper w;
	public DBTableHandler mDBTableHandler;
	public String mId;
	public ArrayList<String> maValue;

	public DBObject(TWrapper w, DBTableHandler dbTableHandler, String id)
	{
		this.w = w;
		mDBTableHandler = dbTableHandler;
		mId = id;
		maValue = null;
	}

	public DBObject load()
	{
		if (maValue == null) {
			int i;
			String value = "";
			maValue = new ArrayList<String>();

			for ( i = 0 ; i < mDBTableHandler.mcField ; ++i ) {
				if (mId != null) {
					value = mDBTableHandler.mData.getString(mId + w.dbh.SEP + mDBTableHandler.mDBTable.aField[i], "");
				}
				maValue.add(value);
			}
		}
		return this;
	}

	public String[] get()
	{
		return load().maValue.toArray(new String[0]);
	}

	public String get(String field)
	{
		return load().maValue.get(mDBTableHandler.maFieldIndex.get(field));
	}

	public DBObject set(String[] aValue)
	{
		load();
		int i;

		for ( i = 0 ; i < mDBTableHandler.mcField - 1 && i < aValue.length ; ++i ) {
			set(i + 1, aValue[i]);
		}
		return this;
	}

	public DBObject set(String field, String value)
	{
		return load().set(mDBTableHandler.maFieldIndex.get(field), value);
	}

	protected DBObject set(int index, String value)
	{
		String formatted = "";

		if (value != null) {
			formatted = value;
		}
		maValue.set(index, formatted);
		return this;
	}

	public DBObject commit()
	{
		load();
		int i;

		if (mId == null) {
			mId = "1";
			ArrayList<Object> aRecord = new ArrayList<Object>(mDBTableHandler.mData.getAll().values());

			if (aRecord.size() >= 1) {
				mId = (String)aRecord.get((aRecord.size()/mDBTableHandler.mcField - 1)*mDBTableHandler.mcField);
				mId = "" + (Integer.parseInt(mId) + 1);
			}
		}
		maValue.set(0, mId);

		for ( i = 0 ; i < mDBTableHandler.mcField && i < maValue.size() ; ++i ) {
			mDBTableHandler.mDataEditor.putString(mId + w.dbh.SEP + mDBTableHandler.mDBTable.aField[i], maValue.get(i));
		}
		mDBTableHandler.mDataEditor.apply();
		return this;
	}

	public boolean apply(DBFilter filtre, boolean selected)
	{
		if (filtre.mOp.equals("AND")) {
			selected &= apply(filtre.mLeft, true) && apply(filtre.mRight, true);
		} else if (filtre.mOp.equals("OR")) {
			selected &= apply(filtre.mLeft, true) || apply(filtre.mRight, true);
		} else if (filtre.mOp.equals("=")) {
			selected &= get(filtre.mLeft.mOp).equals(filtre.mRight.mOp);
		} else if (filtre.mOp.equals("!=")) {
			selected &= !get(filtre.mLeft.mOp).equals(filtre.mRight.mOp);
		} else if (filtre.mOp.equals("<")) {
			selected &= (get(filtre.mLeft.mOp).compareTo(filtre.mRight.mOp) < 0);
		} else if (filtre.mOp.equals(">")) {
			selected &= (get(filtre.mLeft.mOp).compareTo(filtre.mRight.mOp) > 0);
		} else if (filtre.mOp.equals("<=")) {
			selected &= (get(filtre.mLeft.mOp).compareTo(filtre.mRight.mOp) <= 0);
		} else if (filtre.mOp.equals(">=")) {
			selected &= (get(filtre.mLeft.mOp).compareTo(filtre.mRight.mOp) >= 0);
		} else if (filtre.mOp.equals(w.dbh.TRUE)) {
			selected &= true;
		} else if (filtre.mOp.equals(w.dbh.FALSE)) {
			selected &= false;
		}
		return selected;
	}
}

class DBCollection
{
	public TWrapper w;
	public DBTableHandler mDBTableHandler;
	public ArrayList<DBObject> maDBObject;
	public DBFilter mDBFiltre;

	public DBCollection(TWrapper w, DBTableHandler dbTableHandler)
	{
		this.w = w;
		mDBTableHandler = dbTableHandler;
		maDBObject = null;
		mDBFiltre = new DBFilter("", "", w.dbh.TRUE);
	}

	public DBCollection load()
	{
		if (maDBObject == null) {
			int i;
			ArrayList<Object> arrayList = new ArrayList<Object>(mDBTableHandler.mData.getAll().values());
			maDBObject = new ArrayList<DBObject>();

			for (i = 0 ; i < arrayList.size()/mDBTableHandler.mcField ; ++i ) {
				DBObject o = new DBObject(w, mDBTableHandler, (String)arrayList.get(i*mDBTableHandler.mcField));

				if (o.apply(mDBFiltre, true)) {
					maDBObject.add(o);
				}
			}
		}
		return this;
	}

	public DBObject get(int index)
	{
		return load().maDBObject.get(index);
	}

	public DBCollection filter(String field, String value, String op)
	{
		mDBFiltre = new DBFilter(mDBFiltre, new DBFilter(field, value, op), "AND");
		return this;
	}

	public DBCollection filter(DBFilter left, DBFilter right, String op)
	{
		mDBFiltre = new DBFilter(mDBFiltre, new DBFilter(left, right, op), "AND");
		return this;
	}

	public int count()
	{
		return load().maDBObject.size();
	}
}

class DBFilter
{
	public DBFilter mLeft;
	public DBFilter mRight;
	public String mOp;

	public DBFilter(DBFilter left, DBFilter right, String op)
	{
		mLeft = left;
		mRight = right;
		mOp = op;
	}

	public DBFilter(String left, String right, String op)
	{
		mLeft = new DBFilter(left);
		mRight = new DBFilter(right);
		mOp = op;
	}

	public DBFilter(String string)
	{
		mLeft = null;
		mRight = null;
		mOp = string;
	}
}

