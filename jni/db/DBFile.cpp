#include "Common.h"

namespace NSDEVICE
{

DBFile::DBFile(Wrapper* w, const String& fileName)
	: w(w), msFileName(fileName), maData()
{
	mFileStream = new fstream();
}

DBFile::~DBFile()
{
	// Any open file is automatically closed when the fstream object is destroyed
	//delete mFileStream;
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

			if (!key.empty()) {
			    value = regex_replace(value, regex("n#"), String("\n"));
			    value = regex_replace(value, regex("@(@|#)"), String("$1"));
			    maData[to_long(key)] = value;
			}
		}
		close();
		ret = 0;
	}
	return ret;
}

void DBFile::state(const String& mode)
{
	LOGE(String(
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
    mFileStream->clear();
    mFileStream->open(w->sFileDir + "/" + msFileName, ios_base::binary | ios_base::out | ios_base::app );

    if (!mFileStream->good()) {
        state("w+");
        close();
        mFileStream = nullptr;
        ret = 1;
    }
    if (mFileStream) {
        close();
        mFileStream->clear();
        mFileStream->open(w->sFileDir + "/" + msFileName, ios_base::binary| ios_base::out | ios_base::in );
    }
    if (mFileStream && !mFileStream->good()) {
        state("rw");
        close();
        mFileStream = nullptr;
        ret = 2;
    }
    return ret;
}

int DBFile::close()
{
    nint ret = 1;
    if (mFileStream) {
        mFileStream->clear();
        mFileStream->close();
        ret = !mFileStream->good();
    }
    return ret;
}

String DBFile::get(nulong key)
{
	return maData[key];
}

void DBFile::set(nulong key, const String& value)
{
	maData[key] = value;
}

int DBFile::commit()
{
	int ret = 1;
    map<nulong,String>::iterator it;
    String vStringLine;

	if (open() == 0) {
		for ( it = maData.begin() ; it != maData.end() ; ++it ) {
		    vStringLine = regex_replace(it->second , regex("(@|#)"), String("@$1"));
            vStringLine = regex_replace(it->second, regex("\n"), String("n#"));
			*mFileStream << to_string(it->first) << endl;
			*mFileStream << vStringLine << endl;
		}
		close();
		ret = 0;
	}
	return ret;
}

void DBFile::clear()
{
	maData.clear();
}

} // End namespace
