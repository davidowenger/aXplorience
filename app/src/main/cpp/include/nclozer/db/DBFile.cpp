#include "DBCommon.h"

namespace NSNATIVE
{

DBFile::DBFile(NWrapper* vNWrapper, const String& fileName)
    : mNWrapper(vNWrapper), msFileName(fileName), mFileStream(new fstream()), maData(new map<nulong,String>()), mcValid(0xFFFFFFFFFFFFFFFF)
{
    mFileStream->open(mNWrapper->mFileDir + "/" + msFileName + ".persist", ios_base::binary | ios_base::out | ios_base::app );
    mFileStream->clear();
    mFileStream->close();
    mFileStream->clear();
    mFileStream->open(mNWrapper->mFileDir + "/" + msFileName, ios_base::binary | ios_base::out | ios_base::app );
    mFileStream->clear();
    mFileStream->close();
}

DBFile::~DBFile()
{
    // Any open file is automatically closed when the fstream object is destroyed
    delete mFileStream;
}

int DBFile::init()
{
    String value;
    map<nulong,String>::iterator it;

    nulong key = 0;
    int ret = 1;
    bool vIsValid = false;

    if (open() == 0) {
        while (!vIsValid && mFileStream->good()) {
            value.assign("");
            mFileStream->read((char*)&key, sizeof(nulong));
            getline(*mFileStream, value);

            if (key != mcValid) {
                value = regex_replace(value, regex("n#"), String("\n"));
                value = regex_replace(value, regex("@(@|#)"), String("$1"));
                (*maData)[key] = value;
            } else {
                vIsValid = true;
            }
        }
        ret = !vIsValid;
    }
    close();

    if (!vIsValid) {
        delete maData;
        maData = new map<nulong,String>();

        if (open(".persist") == 0) {
            while (!vIsValid && mFileStream->good()) {
                value.assign("");
                mFileStream->read((char*)&key, sizeof(nulong));
                getline(*mFileStream, value);

                if (key != mcValid) {
                    value = regex_replace(value, regex("n#"), String("\n"));
                    value = regex_replace(value, regex("@(@|#)"), String("$1"));
                    (*maData)[key] = value;
                } else {
                    vIsValid = true;
                }
            }
            if (!vIsValid) {
                delete maData;
                maData = new map<nulong,String>();
            }
            close();

            if (open() == 0) {
                for ( it = maData->begin() ; it != maData->end() ; ++it ) {
                    value = regex_replace(it->second, regex("(@|#)"), String("@$1"));
                    value = regex_replace(value, regex("\n"), String("n#"));
                    mFileStream->write((char*)&it->first, sizeof(nulong));
                    *mFileStream << value << '\n';
                }
                mFileStream->write((char*)&mcValid, sizeof(nulong));
                *mFileStream << '\n';
                ret = 0;
            }
        }
        close();
    }
    return ret;
}

void DBFile::state(const String& mode)
{
    LOGE(String(
        "File [" + msFileName +
        "] stream@[" + to_string(mFileStream) +
        "] path[" + mNWrapper->mFileDir  + "/"
        "] mode[" + mode +
        "] eof[" + to_string(mFileStream->eof()) +
        "] fail[" + to_string(mFileStream->fail()) +
        "] bad[" + to_string(mFileStream->bad()) +
        "] %c").c_str()
    );
}

int DBFile::open(const String& vSuffix)
{
    mFileStream->clear();
    mFileStream->open(mNWrapper->mFileDir + "/" + msFileName + vSuffix, ios_base::binary| ios_base::out | ios_base::in );
    return !mFileStream->good();
}

int DBFile::close()
{
    mFileStream->clear();
    mFileStream->close();
    return !mFileStream->good();
}

String DBFile::get(nulong key)
{
    return (*maData)[key];
}

void DBFile::set(nulong key, const String& value)
{
    (*maData)[key] = value;
}

void DBFile::erase(nulong key)
{
    maData->erase(key);
}

int DBFile::commit()
{
    map<nulong,String>::iterator it;
    String value;

    int ret = 2;

    if (open(".persist") == 0) {
        for ( it = maData->begin() ; it != maData->end() ; ++it ) {
            value = regex_replace(it->second, regex("(@|#)"), String("@$1"));
            value = regex_replace(value, regex("\n"), String("n#"));
            mFileStream->write((char*)&it->first, sizeof(nulong));
            *mFileStream << value << '\n';
        }
        mFileStream->write((char*)&mcValid, sizeof(nulong));
        *mFileStream << '\n';
        ret = 1;
        close();
        if (open() == 0) {
            for ( it = maData->begin() ; it != maData->end() ; ++it ) {
                value = regex_replace(it->second, regex("(@|#)"), String("@$1"));
                value = regex_replace(value, regex("\n"), String("n#"));
                mFileStream->write((char*)&it->first, sizeof(nulong));
                *mFileStream << value << '\n';
            }
            mFileStream->write((char*)&mcValid, sizeof(nulong));
            *mFileStream << '\n';
            ret = 0;
        }
    }
    close();
    return ret;
}

void DBFile::clear()
{
    maData->clear();
}

} // End namespace
