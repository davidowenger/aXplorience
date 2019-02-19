#ifndef __DBFile_H__
#define __DBFile_H__

namespace NSNATIVE
{

class DBFile
{
public:
    DBFile(NWrapper* vWrapper, const String& fileName);
   ~DBFile();

    void clear();
    int close();
    int commit();
    void erase(nulong key);
    String get(nulong key);
    int init();
    int open(const String& vSuffix = "");
    void set(nulong, const String& value);
    void state(const String& mode);

    NWrapper* mNWrapper;
    String msFileName;
    fstream* mFileStream;
    map<nulong,String>* maData;
    nulong mcValid;
};

} // End namespace

#endif
