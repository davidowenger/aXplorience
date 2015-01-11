package z.a;

import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Map;
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

	public DBFilter f(DBFilter left, DBFilter right, String op)
	{
		return new DBFilter(left, right, op);
	}

	public DBFilter f(String left, String right, String op)
	{
		return new DBFilter(left, right, op);
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

	public DBObject(TWrapper w, DBTableHandler dbTableHandler, String id, String packed)
	{
		int i;
		this.w = w;
		mDBTableHandler = dbTableHandler;
		maValue = new ArrayList<String>();
		for ( i = 0 ; i < mDBTableHandler.mcField ; ++i ) {
			maValue.add("");
		}
		unpack(packed);
		mId = maValue.get(0);
	}

	public DBObject load()
	{
		if (maValue == null) {
			int i;
			maValue = new ArrayList<String>();
			for ( i = 0 ; i < mDBTableHandler.mcField ; ++i ) {
				maValue.add("");
			}
			if (mId != null) {
				unpack(mDBTableHandler.mData.getString(mId, ""));
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

	public String get(int index)
	{
		return load().maValue.get(index);
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
			ArrayList<String> aRecord = new ArrayList<String>(mDBTableHandler.mData.getAll().keySet());

			if (aRecord.size() > 0) {
				mId = "" + (Integer.parseInt(Collections.max(aRecord, new DBIdComparator())) + 1);
			}
		}
		maValue.set(0, mId);

		mDBTableHandler.mDataEditor.putString(mId, pack());
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
	
	public String pack()
	{
		int i;
		String packed = "";
		String first = "";
		String[] aValue = get();

		for (i = 0 ; i < aValue.length ; ++i) {
			packed += first + aValue[i].replaceAll("(@|#)", "@\1");
			first = "##";
		}
		return packed;
	}
	
	public void unpack(String packed)
	{
		int i;
    	String[] aValue = packed.split("##");

    	for (i = 0 ; i < aValue.length ; ++i) {
    		maValue.set(i, aValue[i].replaceAll("@(@|#)", "\1"));
    	}
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

			for (i = 0 ; i < arrayList.size() ; ++i ) {
				DBObject o = new DBObject(w, mDBTableHandler, "", (String)arrayList.get(i));

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

	public DBCollection sort(String field)
	{
		load();
		int index = mDBTableHandler.maFieldIndex.get(field);
		Collections.sort(maDBObject, new DBFieldComparator(index));
		return this;
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

class DBFieldComparator implements Comparator<DBObject>
{
	public int mIndex;
	
	DBFieldComparator(int index)
	{
		mIndex = index;
	}
	
	public int compare(DBObject o1, DBObject o2)
	{
		return o1.get(mIndex).compareTo(o2.get(mIndex));
	}

	public boolean equals(Object obj)
	{
		return this.equals(obj);
	}
}

class DBIdComparator implements Comparator<String>
{
	public int mIndex;
	
	DBIdComparator()
	{
	}
	
	public int compare(String o1, String o2)
	{
		int ret = 0;
		
		if (Integer.parseInt(o1) < Integer.parseInt(o2)) {
			ret = -1;
		}
		if (Integer.parseInt(o1) > Integer.parseInt(o2)) {
			ret = +1;
		}
		return ret;
	}

	public boolean equals(Object obj)
	{
		return this.equals(obj);
	}
}
