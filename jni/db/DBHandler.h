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
  	    : cField(0)
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
	int cField;
};

class DBHandler
{
public:
	const String PREFIX;
	const String SEP;
	const String TRUE;
	const String FALSE;

	DBHandler(Wrapper* w);
   ~DBHandler();

    template<typename T> void add(const String& sTable)
    {
    	if (maTable.count(sTable)) {
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

    DBTableHandler* load();
	void drop();
	DBObject* getInstance();
	DBObject* getInstance(const String& id);
	DBCollection* getCollection();

	Wrapper* w;
	DBTable* mDBTable;
	DBFile* mDBFile;
	unordered_map<string,int> maFieldIndex;
	int mLastID;
};

class DBObject
{
public:
	DBObject(Wrapper* w, DBTableHandler* dbTableHandler, const String& id);
   ~DBObject();

	DBObject* load();
	String* get();
	String get(const String& field);
	DBObject* set(String* aValue, int count);
	DBObject* set(const String& field, const String& value);
	DBObject* set(int index, const String& value);
	DBObject* commit();
	bool apply(DBFilter* filtre, bool selected);

	Wrapper* w;
	DBTableHandler* mDBTableHandler;
	String mId;
	String* maValue;
};

class DBCollection
{
public:
	DBCollection(Wrapper* w, DBTableHandler* dbTableHandler);
   ~DBCollection();

	DBCollection* load();
	DBObject* get(int index);
	DBCollection* filter(const String& field, const String& value, const String& op);
	DBCollection* filter(DBFilter* left, DBFilter* right, const String& op);
	int count();

	Wrapper* w;
	DBTableHandler* mDBTableHandler;
	vector<DBObject*> maDBObject;
	DBFilter* mDBFiltre;
	bool isLoaded;
};

class DBFilter
{
public:
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

	DBFilter(const String& string)
	{
		mLeft = nullptr;
		mRight = nullptr;
		mOp = string;
	}

	DBFilter* mLeft;
	DBFilter* mRight;
	String mOp;
};

} // End namespace

#endif
