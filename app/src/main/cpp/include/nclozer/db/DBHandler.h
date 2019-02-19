#ifndef __DBHandler_H__
#define __DBHandler_H__

#define kTrue "1"
#define kFalse "0"

namespace NSNATIVE
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
    DBHandler(NWrapper* vWrappe);
   ~DBHandler();

    template<typename T> void add(const String& sTable)
    {
        if (!maTable.count(sTable)) {
            maTable[sTable] = function<DBTable*()>([]()->DBTable*{return new T;});
        }
    }

    void init();
    DBTableHandler* get(const String& table);

    NWrapper* mNWrapper;
    map<String,DBTableHandler*> maTableHandler;
    map<String,function<DBTable*()>> maTable;
};

class DBTableHandler
{
public:
    DBTableHandler(NWrapper* vWrappe, DBTable* dbTable);
   ~DBTableHandler();

    nint load();
    void drop();
    DBObject* getInstance();
    DBObject* getInstance(nuint id);
    DBCollection* getCollection();

    NWrapper* mNWrapper;
    DBTable* mDBTable;
    DBFile* mDBFile;
    unordered_map<string,nuint>* maFieldIndex;

    const String mPrefix;
};

class DBObject
{
public:
    DBObject(NWrapper* vWrappe, DBTableHandler* dbTableHandler, nuint id);
   ~DBObject();

    bool apply(DBFilter* filtre, bool selected);
    DBObject* commit();
    nlong count(const String& field);
    void drop();
    String* get();
    String get(const String& field);
    nuint getFieldIndex(const String& field);
    bool is(const String& field);
    DBObject* set(String* aValue, nuint count);
    DBObject* set(const String& field, const String& value);
    DBObject* set(const String& field, nlong value);
    DBObject* set(nint index, const String& value);

    bool mIsCache;
    nuint mcField;
    nuint mId;

    NWrapper* mNWrapper;
    DBTableHandler* mDBTableHandler;
    map<nulong,String>* maData;
    unordered_map<string,nuint>* maFieldIndex;
    String* maValue;
};

class Sort
{
public:
    Sort(const String& vField, bool vIsAscending = true)
        : mField(vField), mIsAscending(vIsAscending)
    {
    };

    String mField;
    bool mIsAscending;
};

class DBCollection
{
public:
    typedef function<bool(const String&,const String&)> Compare;

    DBCollection(NWrapper* vWrappe, DBTableHandler* dbTableHandler);
   ~DBCollection();

    DBCollection* load();
    DBObject* get(nuint index);
    DBCollection* sort(const String& field, bool ascending = true);
    DBCollection* sort(list<Sort> vaSort);
    DBCollection* filter(const String& field, const String& value, const String& op);
    DBCollection* filter(const String& field, nlong value, const String& op);
    DBCollection* filter(DBFilter* left, DBFilter* right, const String& op);
    nuint count();

    bool isLoaded;
    nuint mcField;

    NWrapper* mNWrapper;
    DBTableHandler* mDBTableHandler;
    map<nulong,String>* maData;
    DBFilter* mDBFiltre;
    multimap<String,DBObject*,Compare>* maDBObjectSorted;

    vector<DBObject*> maDBObject;
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
