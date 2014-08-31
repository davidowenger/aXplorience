#ifndef __BO_H__
#define __BO_H__

namespace NSDEVICE
{

class BO
{
public:
	BO(Wrapper* w)
		: w(w)
	{
	}

   ~BO()
	{
	}

    DBFilter* f(DBFilter* left, DBFilter* right, const String& op)
	{
		return new DBFilter(left, right, op);
	}

	DBFilter* f(const String& left, const String& right, const String& op)
	{
		return new DBFilter(left, right, op);
	}

    Wrapper* w;
	DBTableHandler* h;
	DBObject* o;
};

class BODrop : public BO
{
public:
	BODrop(Wrapper* w, DBObject* dbDrop)
		: BO(w)
	{
		h = w->dbh->get("Drop");
		o = dbDrop;
	}

   ~BODrop()
	{
	}

	String pack()
	{
		int i;
		String packed = "";
		String first = "";
		String* aValue = o->get();

		for ( i = 1 ; i < h->mDBTable->cField ; ++i ) {
			packed += first + regex_replace(aValue[i], regex("(@|#)"), String("@$1"));
			first = "##";
		}
		return packed;
	}
};

class BOHandlerDrop : public BO
{
public:
	BOHandlerDrop(Wrapper* w)
		: BO(w)
	{
		h = w->dbh->get("Drop");
	}

   ~BOHandlerDrop()
	{
	}

    DBCollection* getDrops()
    {
    	return h->getCollection()->filter(f("mac", w->mac, "!="), f("archived", w->dbh->FALSE, "="), "AND");
    }

    DBCollection* getSeeds()
    {
    	return h->getCollection()->filter("mac", w->mac, "=");
    }

    BODrop* addSeed(const String& id_cat, const String& title, const String& text)
    {
    	chrono::seconds stamp = chrono::seconds(time(NULL));
    	String aValue[] = {
			w->mac,
			"",
			id_cat,
			to_string(stamp.count()),
			title,
			text,
			w->dbh->FALSE,
		};
    	DBObject* drop = h->getInstance()->set(aValue, sizeof(aValue)/sizeof(string))->commit();
    	return new BODrop(w, drop->set("id_drop", drop->get("id"))->commit());
    }

    BODrop* unpack(String packed)
    {
    	int i;
    	vector<string> aValue = split(packed, String("##"));

    	for (i = 0 ; i < aValue.size() ; ++i) {
    		aValue[i] = regex_replace(aValue[i], regex("@(@|#)"), String("$1"));
    	}
    	DBObject* drop = h->getInstance()->set(aValue.data(), aValue.size());
    	DBCollection* c = h->getCollection()->filter(f("mac", drop->get("mac"), "="), f("id_drop", drop->get("id_drop"), "="), "AND");

    	if (c->count() > 0) {
    		delete drop;
    		drop = c->get(0)->set(aValue.data(), aValue.size());
    	};
    	return new BODrop(w, drop->set("archived", w->dbh->FALSE)->commit());
    }
};

} // End namespace

#endif
