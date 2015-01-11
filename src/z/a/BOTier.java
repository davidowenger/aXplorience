package z.a;

import java.util.ArrayList;
import java.util.Date;

public class BOTier
{
	public TWrapper w;
	public DBTableHandler h;
	public DBObject mDBObject;

	public DBFilter f(DBFilter left, DBFilter right, String op)
	{
		return new DBFilter(left, right, op);
	}

	public DBFilter f(String left, String right, String op)
	{
		return new DBFilter(left, right, op);
	}
}

class BO_Seed extends BOTier
{
	public BO_Seed(TWrapper w)
	{
		this.w = w;
		this.h = w.dbh.get("Drop");;
		//h.delete("yes");
	}

	public ArrayList<BO_Drop> getSeeds()
	{
		int i;
		DBCollection c = h.getCollection().filter(f("mac", w.mac, "="), f("archived", w.dbh.FALSE, "="), "AND");
		ArrayList<BO_Drop> aBODrop = new ArrayList<BO_Drop>();

		for (i = 0 ; i < c.count() ; ++i) {
			aBODrop.add(new BO_Drop(w, c.get(i)));
		}
		return aBODrop;
	}

	public BO_Drop addSeed(String id_cat, String title, String text)
	{
		Date date = new Date();
		DBObject o = h.getInstance().set(new String[] {
		    w.mac,
		    "",
		    id_cat,
		    "" + date.getTime(),
		    title,
		    text,
		    w.dbh.FALSE,
		}).commit();
		return new BO_Drop(w, o.set("id_drop", o.get("id")).commit());
	}

	public ArrayList<BO_Drop> getDrops()
	{
		int i;
		DBCollection c = h.getCollection().filter(f("mac", w.mac, "!="), f("archived", w.dbh.FALSE, "="), "AND");
		ArrayList<BO_Drop> aBODrop = new ArrayList<BO_Drop>();

		for (i = 0 ; i < c.count() ; ++i) {
			aBODrop.add(new BO_Drop(w, c.get(i)));
		}
		return aBODrop;
	}

	public BO_Drop getDrop(String id_drop)
	{
		int i;
		DBCollection c = h.getCollection().filter(f("id_drop", id_drop, "="), f(f("mac", w.mac, "!="), f("archived", w.dbh.FALSE, "="), "AND"), "AND");
    	DBObject o = h.getInstance();
    	if (c.count() > 0) {
    		o = c.get(0);
    	};
		return new BO_Drop(w, o);
	}

	public BO_Drop unpack(String packed)
	{
		int i;
    	String[] aValue = packed.split("##");

    	for (i = 0 ; i < aValue.length ; ++i) {
    		aValue[i] = aValue[i].replaceAll("@(@|#)", "\1");
    	}
    	DBObject o = h.getInstance().set(aValue);
    	DBCollection c = h.getCollection().filter(f("mac", o.get("mac"), "="), f("id_drop", o.get("id_drop"), "="), "AND");

    	if (c.count() > 0) {
    		o = c.get(0).set(aValue);
    	};
		return new BO_Drop(w, o.set("archived", w.dbh.FALSE).commit());
	}
}

class BO_Drop extends BOTier
{
	public BO_Drop(TWrapper w, DBObject dbDrop)
	{
		this.w = w;
		h = w.dbh.get("Drop");
		mDBObject = dbDrop;
	}

	public String pack()
	{
		int i;
		String packed = "";
		String first = "";
		String[] aValue = mDBObject.get();

		for (i = 1 ; i < aValue.length ; ++i) {
			packed += first + aValue[i].replaceAll("(@|#)", "@\1");
			first = "##";
		}
		return packed;
	}
}
