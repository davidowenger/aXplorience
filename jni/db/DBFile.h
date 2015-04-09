#ifndef __DBFile_H__
#define __DBFile_H__

namespace NSDEVICE
{

class DBFile
{
public:
	DBFile(Wrapper* w, const String& fileName);
   ~DBFile();

    void clear();
    int close();
    int commit();
    String get(nulong key);
    int init();
    int open();
    void set(nulong, const String& value);
    void state(const String& mode);

    Wrapper* w;
    String msFileName;
    fstream* mFileStream;
	map<nulong,String> maData;
};

} // End namespace

#endif
