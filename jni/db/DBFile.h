#ifndef __DBFile_H__
#define __DBFile_H__

namespace NSDEVICE
{

class DBFile
{
public:
	DBFile(Wrapper* w, const String& fileName);
   ~DBFile();

    String get(const String& key);
    void set(const String& key, const String& value);
    void clear();
    int commit();
    int init();
    int open();
    void state(const String& mode);

    Wrapper* w;
    String msFileName;
    fstream* mFileStream;
	map<String,String> maData;
};

} // End namespace

#endif
