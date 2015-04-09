#ifndef __DBHandler_H__
#define __DBHandler_H__

namespace NSDEVICE
{
class DBTableHandler;
class DBObject;
class DBCollection;
class DBFilter;

class DBTable
{
public:
	DBTable()
  	    : table(), aField(), cField(0)
	{
	}

	virtual ~DBTable()
	{
	}

	DBTable* load()
	{
		init();
		cField = aField.size();
		return this;
	}

	virtual void init() = 0;

	String table;
	vector<String> aField;
	nuint cField;
};

class DBHandler
{
public:
	const String PREFIX;
	const String TRUE;
	const String FALSE;

	DBHandler(Wrapper* w);
   ~DBHandler();

    template<typename T> void add(const String& sTable)
    {
    	if (!maTable.count(sTable)) {
    		maTable[sTable] = function<DBTable*()>([]()->DBTable*{return new T;});
    	}
    }

    void init();
    DBTableHandler* get(const String& table);

	Wrapper* w;
	map<String,DBTableHandler*> maTableHandler;
	map<String,function<DBTable*()>> maTable;
};

class DBTableHandler
{
public:
	DBTableHandler(Wrapper* w, DBTable* dbTable);
   ~DBTableHandler();

    nint load();
	void drop();
	DBObject* getInstance();
	DBObject* getInstance(const String& id);
	DBCollection* getCollection();

	Wrapper* w;
	DBTable* mDBTable;
	DBFile* mDBFile;
	unordered_map<string,nint> maFieldIndex;
};

class DBObject
{
public:
	DBObject(Wrapper* w, DBTableHandler* dbTableHandler, const String& id);
   ~DBObject();

	DBObject* load();
	String* get();
	String get(const String& field);
    nlong count(const String& field);
    bool is(const String& field);
	DBObject* set(String* aValue, nuint count);
	DBObject* set(const String& field, const String& value);
    DBObject* set(const String& field, nlong value);
	DBObject* set(nint index, const String& value);
	DBObject* commit();
	bool apply(DBFilter* filtre, bool selected);

	Wrapper* w;
	DBTableHandler* mDBTableHandler;
	String mId;
	String* maValue;
	bool mIsCache;
};

class DBCollection
{
public:
	DBCollection(Wrapper* w, DBTableHandler* dbTableHandler);
   ~DBCollection();

	DBCollection* load();
	DBObject* get(nint index);
	DBCollection* sort(const String& field, bool ascending = true);
    DBCollection* filter(const String& field, const String& value, const String& op);
    DBCollection* filter(const String& field, nlong value, const String& op);
	DBCollection* filter(DBFilter* left, DBFilter* right, const String& op);
	nint count();

	Wrapper* w;
	DBTableHandler* mDBTableHandler;
	vector<DBObject*> maDBObject;
	DBFilter* mDBFiltre;
	bool isLoaded;
};

class DBFilter
{
public:
    DBFilter()
    {
        mLeft = nullptr;
        mRight = nullptr;
        mOp = "";
    }

    DBFilter(DBFilter* left, DBFilter* right, const String& op)
    {
        mLeft = left;
        mRight = right;
        mOp = op;
    }

    DBFilter(const String& left, const String& right, const String& op)
    {
        mLeft = new DBFilter(left);
        mRight = new DBFilter(right);
        mOp = op;
    }

    DBFilter(const String& left, nlong right, const String& op)
    {
        mLeft = new DBFilter(left);
        mRight = new DBFilter(right);
        mOp = op;
    }

    DBFilter(const String& string)
    {
        mLeft = nullptr;
        mRight = nullptr;
        mOp = string;
    }

    DBFilter(nlong value)
    {
        mLeft = nullptr;
        mRight = nullptr;
        mOp = to_string(value);
    }

    virtual ~DBFilter()
    {
    	if (mLeft) {
    		delete mLeft;
    	}
    	if (mRight) {
    		delete mRight;
    	}
    }

    DBFilter* mLeft;
    DBFilter* mRight;
    String mOp;
};

class DBHelper
{
public:
    DBFilter* f(DBFilter* left, DBFilter* right, const String& op)
    {
        return new DBFilter(left, right, op);
    }

    DBFilter* f(const String& left, const String& right, const String& op)
    {
        return new DBFilter(left, right, op);
    }

    DBFilter* f(const String& left, nlong right, const String& op)
    {
        return new DBFilter(left, right, op);
    }
};

} // End namespace

#endif
