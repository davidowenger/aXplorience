#include "Common.h"

namespace NSDEVICE
{

DBFile::DBFile(NWrapper* w, const String& fileName)
	: NVisitor(w), msFileName(fileName)
{
	mFileStream = new fstream();
}

DBFile::~DBFile()
{
	// Any open file is automatically closed when the fstream object is destroyed
}

int DBFile::init()
{
	int ret = 1;

	if (open() == 0) {
		String key;
		String value;

		while (mFileStream->good()) {
			key.assign("");
			value.assign("");
			getline(*mFileStream, key);
			getline(*mFileStream, value);
			maData[key] = value;
		}
		mFileStream->close();
		ret = 0;
	}
	return ret;
}

void DBFile::state(const String& mode)
{
	LOGWE(String(
		"File [" + msFileName +
		"] stream@[" + std::to_string(mFileStream) +
		"] path[" + w->sFileDir  + "/"
		"] mode[" + mode +
		"] eof[" + to_string(mFileStream->eof()) +
		"] fail[" + to_string(mFileStream->fail()) +
		"] bad[" + to_string(mFileStream->bad()) +
		"] %c").c_str()
	);
}

int DBFile::open()
{
	int ret = 0;
	mFileStream->open(w->sFileDir + "/" + msFileName, ios_base::out | ios_base::app);

	if (!mFileStream->good()) {
		state("w+");
		mFileStream->clear();
		mFileStream->close();
		mFileStream = nullptr;
		ret = 1;
	}
	if (mFileStream) {
		mFileStream->clear();
		mFileStream->close();
		mFileStream->open(w->sFileDir + "/" + msFileName, ios_base::in | ios_base::out);
	}
	if (mFileStream && !mFileStream->good()) {
		state("rw");
		mFileStream->clear();
		mFileStream->close();
		mFileStream = nullptr;
		ret = 2;
	}
	return ret;
}

String DBFile::get(const String& key)
{
	return maData[key];
}

void DBFile::set(const String& key, const String& value)
{
	maData[key] = value;
}

int DBFile::commit()
{
	int ret = 1;

	if (open() == 0) {
		map<String,String>::iterator it;

		for ( it = maData.begin() ; it != maData.end() ; ++it ) {
			*mFileStream << it->first << endl;
			*mFileStream << it->second << endl;
		}
		mFileStream->close();
		ret = 0;
	}
	return ret;
}

void DBFile::clear()
{
	maData.clear();
}

} // End namespace
