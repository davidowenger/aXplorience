#include "DBCommon.h"

namespace NSNATIVE
{

DBHandler::DBHandler(NWrapper* vNWrapper)
    : mNWrapper(vNWrapper), maTableHandler(), maTable()
{
}

DBHandler::~DBHandler()
{
    for (map<String, DBTableHandler*>::value_type vDBTableHandler : maTableHandler) {
        if (vDBTableHandler.second) {
            delete vDBTableHandler.second->mDBTable;
            delete vDBTableHandler.second;
        }
    }
}

DBTableHandler* DBHandler::get(const String& sTable)
{
    if (!maTableHandler.count(sTable)) {
        DBTableHandler* dbTableHandler = nullptr;

        if (maTable.count(sTable)) {
            DBTable* dbTable = maTable[sTable]();
            dbTable->table = sTable;
            dbTableHandler = new DBTableHandler(mNWrapper, dbTable);

            if (dbTableHandler->load()) {
                delete dbTableHandler;
                dbTableHandler = nullptr;
            }
        }
        maTableHandler[sTable] = dbTableHandler;
    }
    return maTableHandler[sTable];
}

DBTableHandler::DBTableHandler(NWrapper* vNWrapper, DBTable* dbTable)
    : mNWrapper(vNWrapper), mDBTable(dbTable), mDBFile(nullptr), maFieldIndex(nullptr), mPrefix("TABLE")
{
}

DBTableHandler::~DBTableHandler()
{
    if (mDBFile) {
        delete mDBFile;
    }
    if (maFieldIndex) {
        delete maFieldIndex;
    }
}

nint DBTableHandler::load()
{
    nuint i = 0;
    mDBTable->load();
    maFieldIndex = new unordered_map<string,nuint>();

    for (i = 0 ; i < mDBTable->cField ; ++i ) {
        (*maFieldIndex)[mDBTable->aField[i]] = i;
    }
    mDBFile = new DBFile(mNWrapper, mPrefix + mDBTable->table);
    return mDBFile->init();
}

DBObject* DBTableHandler::getInstance()
{
    return getInstance(0);
}

DBObject* DBTableHandler::getInstance(nuint id)
{
    return new DBObject(mNWrapper, this, id);
}

DBCollection* DBTableHandler::getCollection()
{
    return new DBCollection(mNWrapper, this);
}

void DBTableHandler::drop()
{
    mDBFile->clear();
    mDBFile->commit();
}

DBObject::DBObject(NWrapper* vNWrapper, DBTableHandler* dbTableHandler, nuint id)
    : mIsCache(false), mcField(dbTableHandler->mDBTable->cField), mId(id),
      mNWrapper(vNWrapper), mDBTableHandler(dbTableHandler), maData(dbTableHandler->mDBFile->maData), maFieldIndex(dbTableHandler->maFieldIndex),
      maValue(new String[dbTableHandler->mDBTable->cField])
{
    nuint i;

    if (mId) {
        for ( i = 0 ; i < mcField ; ++i ) {
            maValue[i] = (*maData)[((nulong)mId<<32) + i];
        }
    } else {
        mId = 1;

        if (maData->size()) {
            mId = (maData->rbegin()->first>>32) + 1;

            if (mId == 0xFFFFFFFF) {
                LOGE("Error: index overflow on DBObject commit");
                mId = 0;
            }
        }
        maValue[0] = to_string(mId);
        (*maData)[((nulong)mId<<32)] = maValue[0];

        for ( i = 1 ; i < mcField ; ++i ) {
            maValue[i] = "";
            (*maData)[((nulong)mId<<32) + i] = "";
        }
    }
}

DBObject::~DBObject()
{
    delete[] maValue;
}

String* DBObject::get()
{
    return maValue;
}

String DBObject::get(const String& field)
{
    return maValue[getFieldIndex(field)];
}

nuint DBObject::getFieldIndex(const String& field)
{
#ifdef DEBUG
    nuint ret = 0;

    if (maFieldIndex->count(field)) {
        ret = (*maFieldIndex)[field];
    } else {
        LOGE(("Error: field does not exists: #" + field).c_str());
    }
    return ret;
#else
    return (*maFieldIndex)[field];
#endif
}

nlong DBObject::count(const String& field)
{
    return to_long(maValue[getFieldIndex(field)]);
}

bool DBObject::is(const String& field)
{
    return maValue[getFieldIndex(field)] == kTrue;
}

DBObject* DBObject::set(String* aValue, nuint count)
{
    nuint i;

    for ( i = 0 ; i < mcField - 1 && i < count ; ++i ) {
        set(i + 1, aValue[i]);
    }
    return this;
}

DBObject* DBObject::set(const String& field, const String& value)
{
    return set(getFieldIndex(field), value);
}

DBObject* DBObject::set(const String& field, nlong value)
{
    return set(getFieldIndex(field), to_string(value));
}

DBObject* DBObject::set(nint index, const String& value)
{
    maValue[index] = value;
    (*maData)[((nulong)mId<<32) + index] = value;
    return this;
}

DBObject* DBObject::commit()
{
    return ( !mDBTableHandler->mDBFile->commit() ? this : nullptr );
}

void DBObject::drop()
{
    nuint i;

    for ( i = 0 ; i < mcField ; ++i ) {
        maData->erase(((nulong)mId<<32) + i);
    }
}

bool DBObject::apply(DBFilter* filtre, bool selected)
{
    if (filtre->mOp == "AND") {
        selected &= apply(filtre->mLeft, true) && apply(filtre->mRight, true);
    } else if (filtre->mOp == "OR") {
        selected &= apply(filtre->mLeft, true) || apply(filtre->mRight, true);
    } else if (filtre->mOp == "=") {
        selected &= get(filtre->mLeft->mOp) == filtre->mRight->mOp;
    } else if (filtre->mOp == "!=") {
        selected &= get(filtre->mLeft->mOp) != filtre->mRight->mOp;
    } else if (filtre->mOp == "<") {
        selected &= get(filtre->mLeft->mOp) < filtre->mRight->mOp;
    } else if (filtre->mOp == ">") {
        selected &= get(filtre->mLeft->mOp) > filtre->mRight->mOp;
    } else if (filtre->mOp == "<=") {
        selected &= get(filtre->mLeft->mOp) <= filtre->mRight->mOp;
    } else if (filtre->mOp == ">=") {
        selected &= get(filtre->mLeft->mOp) >= filtre->mRight->mOp;
    } else if (filtre->mOp == kTrue) {
        selected &= true;
    } else if (filtre->mOp == kFalse) {
        selected &= false;
    }
    return selected;
}

DBCollection::DBCollection(NWrapper* vNWrapper, DBTableHandler* dbTableHandler)
    : isLoaded(false), mcField(dbTableHandler->mDBTable->cField),
      mNWrapper(vNWrapper), mDBTableHandler(dbTableHandler), maData(dbTableHandler->mDBFile->maData), mDBFiltre(new DBFilter("", "", "1")), maDBObjectSorted(nullptr)
{
}

DBCollection::~DBCollection()
{
    for (DBObject* vDBObject : maDBObject) {
        delete vDBObject;
    }
    delete mDBFiltre;
}

DBCollection* DBCollection::load()
{
    if (!isLoaded) {
        map<nulong,String>::iterator it = maData->begin();

        while (it != maData->end()) {
            DBObject* o = new DBObject(mNWrapper, mDBTableHandler, it->first>>32);

            if (o->apply(mDBFiltre, true)) {
                maDBObject.push_back(o);
            }
            advance(it, mcField);
        }
        isLoaded = true;
    }
    return this;
}

DBCollection* DBCollection::sort(const String& field, bool ascending)
{
    load();

    if (ascending) {
         maDBObjectSorted = new multimap<String,DBObject*,Compare>(Compare([](const String& a, const String& b)->bool{return a < b;}));
    } else {
         maDBObjectSorted = new multimap<String,DBObject*,Compare>(Compare([](const String& a, const String& b)->bool{return a > b;}));
    }
    for (DBObject* vDBObject : maDBObject) {
        maDBObjectSorted->emplace(vDBObject->get(field), vDBObject);
    }
    maDBObject.clear();

    for (multimap<String,DBObject*,Compare>::value_type vPairSorted : *maDBObjectSorted) {
        maDBObject.push_back(vPairSorted.second);
    }
    delete maDBObjectSorted;
    return this;
}

DBCollection* DBCollection::sort(list<Sort> vaSort)
{
    load();

    for (Sort vSort : vaSort) {
        sort(vSort.mField, vSort.mIsAscending);
    }
    return this;
}

DBObject* DBCollection::get(nuint index)
{
    return load()->maDBObject[index];
}

DBCollection* DBCollection::filter(const String& field, const String& value, const String& op)
{
    mDBFiltre = new DBFilter(mDBFiltre, new DBFilter(field, value, op), "AND");
    return this;
}

DBCollection* DBCollection::filter(const String& field, nlong value, const String& op)
{
    mDBFiltre = new DBFilter(mDBFiltre, new DBFilter(field, value, op), "AND");
    return this;
}

DBCollection* DBCollection::filter(DBFilter* left, DBFilter* right, const String& op)
{
    mDBFiltre = new DBFilter(mDBFiltre, new DBFilter(left, right, op), "AND");
    return this;
}

nuint DBCollection::count()
{
    return load()->maDBObject.size();
}

} // End namespace
