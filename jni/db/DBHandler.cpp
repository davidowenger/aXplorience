#include "Common.h"

namespace NSDEVICE
{

DBHandler::DBHandler(Wrapper* w)
	: PREFIX("TABLE"), SEP("_"), TRUE("TRUE"), FALSE("FALSE"), w(w), maTableHandler(), maTable()
{
}

DBHandler::~DBHandler()
{
    for (map<String, DBTableHandler*>::value_type vDBTableHandler : maTableHandler) {
        if (vDBTableHandler.second) {
            delete vDBTableHandler.second;
        }
    }
}

DBTableHandler* DBHandler::get(const String& sTable)
{
	if (!maTableHandler.count(sTable)) {
		DBTable* dbTable = maTable[sTable]();
		dbTable->table = sTable;
		DBTableHandler* dbTableHandler = new DBTableHandler(w, dbTable);

		if (dbTableHandler->load()) {
			delete dbTableHandler;
			dbTableHandler = nullptr;
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
}

int DBTableHandler::load()
{
	int i = 0;
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
	: w(w)
{
	mDBTableHandler = dbTableHandler;
	mId = id;
	maValue = nullptr;
	mIsCache = false;
}

DBObject::~DBObject()
{
}

DBObject* DBObject::load()
{
	if (!maValue || !mIsCache) {
		int i;
		String value = "";
		maValue = new String[mDBTableHandler->mDBTable->cField];

		for ( i = 0 ; i < mDBTableHandler->mDBTable->cField ; ++i ) {
			maValue[i] = ( mId != "" ? mDBTableHandler->mDBFile->get(mId + w->dbh->SEP + to_string(i)) : value );
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
	return load()->maValue[mDBTableHandler->maFieldIndex[field]];
}

DBObject* DBObject::set(String* aValue, int count)
{
	load();
	int i;

	for ( i = 0 ; i < mDBTableHandler->mDBTable->cField - 1 && i < count ; ++i ) {
		set(i + 1, aValue[i]);
	}
	return this;
}

DBObject* DBObject::set(const String& field, const String& value)
{
	return load()->set(mDBTableHandler->maFieldIndex[field], value);
}

DBObject* DBObject::set(int index, const String& value)
{
	mIsCache = true;
	maValue[index] = value;
	return this;
}

DBObject* DBObject::commit()
{
		load();
		int i = 0;

		if (mId == "" && mDBTableHandler->mDBFile->maData.size() > 0) {
			//FIXME
			map<String,String>::iterator it = mDBTableHandler->mDBFile->maData.end();
			it--;
			String str = it->first;
			int prev = atoi(str.c_str());
			mId = to_string(prev + 1);
			//mId = to_string(atoi((mDBTableHandler->mDBFile->maData.end()--)->second.c_str()) + 1);
		}
		if (mId == "") {
			mId = "1";
		}
		maValue[0] = mId;

		for ( i = 0 ; i < mDBTableHandler->mDBTable->cField ; ++i ) {
			mDBTableHandler->mDBFile->set(mId + w->dbh->SEP + to_string(i), maValue[i]);
		}
		mDBTableHandler->mDBFile->commit();
		mIsCache = false;
		return this;
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
	: w(w), maDBObject(), isLoaded(false)
{
	mDBTableHandler = dbTableHandler;
	mDBFiltre = new DBFilter("", "", w->dbh->TRUE);
}

DBCollection::~DBCollection()
{
}

DBCollection* DBCollection::load()
{
	if (!isLoaded) {
		int i = 0;
		map<String,String>::iterator it = mDBTableHandler->mDBFile->maData.begin();

		for ( i = 0 ; i < (int)mDBTableHandler->mDBFile->maData.size()/mDBTableHandler->mDBTable->cField && it != mDBTableHandler->mDBFile->maData.end() ; ++i ) {
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

DBObject* DBCollection::get(int index)
{
	return load()->maDBObject[index];
}

DBCollection* DBCollection::filter(const String& field, const String& value, const String& op)
{
	mDBFiltre = new DBFilter(mDBFiltre, new DBFilter(field, value, op), "AND");
	return this;
}

DBCollection* DBCollection::filter(DBFilter* left, DBFilter* right, const String& op)
{
	mDBFiltre = new DBFilter(mDBFiltre, new DBFilter(left, right, op), "AND");
	return this;
}

int DBCollection::count()
{
	return load()->maDBObject.size();
}

} // End namespace