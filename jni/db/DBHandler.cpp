#include "Common.h"

namespace NSDEVICE
{

DBHandler::DBHandler(Wrapper* w)
	: PREFIX("TABLE"), TRUE("1"), FALSE("0"), w(w), maTableHandler(), maTable()
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
            dbTableHandler = new DBTableHandler(w, dbTable);

            if (dbTableHandler->load()) {
                delete dbTableHandler;
                dbTableHandler = nullptr;
            }
	    }
		maTableHandler[sTable] = dbTableHandler;
	}
	return maTableHandler[sTable];
}

DBTableHandler::DBTableHandler(Wrapper* w, DBTable* dbTable)
	: w(w), mDBTable(dbTable), mDBFile(nullptr), maFieldIndex()
{
}

DBTableHandler::~DBTableHandler()
{
	if (mDBFile) {
		delete mDBFile;
	}
}

nint DBTableHandler::load()
{
	nuint i = 0;
	mDBTable->load();

	for (i = 0 ; i < mDBTable->cField ; ++i ) {
		maFieldIndex[mDBTable->aField[i]] = i;
	}
	mDBFile = new DBFile(w, w->dbh->PREFIX + mDBTable->table);
	return mDBFile->init();
}

DBObject* DBTableHandler::getInstance()
{
	return getInstance("");
}

DBObject* DBTableHandler::getInstance(const String& id)
{
	return new DBObject(w, this, id);
}

DBCollection* DBTableHandler::getCollection()
{
	return new DBCollection(w, this);
}

void DBTableHandler::drop()
{
	mDBFile->clear();
	mDBFile->commit();
}

DBObject::DBObject(Wrapper* w, DBTableHandler* dbTableHandler, const String& id)
	: w(w), mDBTableHandler(dbTableHandler), mId(id), maValue(nullptr), mIsCache(false)
{
}

DBObject::~DBObject()
{
	if (maValue) {
		delete[] maValue;
	}
}

DBObject* DBObject::load()
{
	if (!maValue || !mIsCache) {
		nuint i;
		String value = "";
		maValue = new String[mDBTableHandler->mDBTable->cField];

		for ( i = 0 ; i < mDBTableHandler->mDBTable->cField ; ++i ) {
			maValue[i] = ( mId != "" ? mDBTableHandler->mDBFile->get((to_long(mId)<<32) + i) : value );
		}
	}
	return this;
}

String* DBObject::get()
{
	return load()->maValue;
}

String DBObject::get(const String& field)
{
    return load()->maValue[getFieldIndex(field)];
}

nuint DBObject::getFieldIndex(const String& field)
{
    nuint ret = 0;

    if (mDBTableHandler->maFieldIndex.count(field)) {
        ret = mDBTableHandler->maFieldIndex.at(field);
    } else {
        LOGE(("Error: field does not exists: #" + field).c_str());
    }
    return ret;
}

nlong DBObject::count(const String& field)
{
    return to_long(load()->maValue[getFieldIndex(field)]);
}

bool DBObject::is(const String& field)
{
    return load()->maValue[getFieldIndex(field)] == w->dbh->TRUE;
}

DBObject* DBObject::set(String* aValue, nuint count)
{
	load();
	nuint i;

	for ( i = 0 ; i < mDBTableHandler->mDBTable->cField - 1 && i < count ; ++i ) {
		set(i + 1, aValue[i]);
	}
	return this;
}

DBObject* DBObject::set(const String& field, const String& value)
{
    return load()->set(getFieldIndex(field), value);
}

DBObject* DBObject::set(const String& field, nlong value)
{
    return load()->set(getFieldIndex(field), to_string(value));
}

DBObject* DBObject::set(nint index, const String& value)
{
	mIsCache = true;
	maValue[index] = value;
	return this;
}

DBObject* DBObject::commit()
{
    load();
    DBObject* vDBObject = this;
    nuint i = 0;

    if (mId == "" && mDBTableHandler->mDBFile->maData.size() > 0) {
        nulong vId = mDBTableHandler->mDBFile->maData.rbegin()->first>>32;
        if (vId < 0xFFFFFFFF) {
            mId = to_string(vId + 1);
        } else {
            LOGE("Error: index overflow on DBObject commit");
            mId = "overflow";
            vDBObject = nullptr;
        }
    }
    if (mId == "") {
        mId = "1";
    }
    if (mId != "overflow") {
        maValue[0] = mId;

        for ( i = 0 ; i < mDBTableHandler->mDBTable->cField ; ++i ) {
            mDBTableHandler->mDBFile->set((to_long(mId)<<32) + i, maValue[i]);
        }
        mDBTableHandler->mDBFile->commit();
        mIsCache = false;
    }
    return vDBObject;
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
	} else if (filtre->mOp == w->dbh->TRUE) {
		selected &= true;
	} else if (filtre->mOp == w->dbh->FALSE) {
		selected &= false;
	}
	return selected;
}

DBCollection::DBCollection(Wrapper* w, DBTableHandler* dbTableHandler)
    : w(w), mDBTableHandler(dbTableHandler), mDBFiltre(new DBFilter("", "", w->dbh->TRUE)), maDBObjectSorted(nullptr),
      maDBObject(), isLoaded(false)
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
		nuint i = 0;
		map<nulong,String>::iterator it = mDBTableHandler->mDBFile->maData.begin();

		for ( i = 0 ; i < (nuint)mDBTableHandler->mDBFile->maData.size()/mDBTableHandler->mDBTable->cField && it != mDBTableHandler->mDBFile->maData.end() ; ++i ) {
			DBObject* o = new DBObject(w, mDBTableHandler, it->second);

			if (o->apply(mDBFiltre, true)) {
				maDBObject.push_back(o);
			}
            advance(it, mDBTableHandler->mDBTable->cField);
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

DBObject* DBCollection::get(nint index)
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

nint DBCollection::count()
{
	return load()->maDBObject.size();
}

} // End namespace
