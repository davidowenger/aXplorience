#include "NCommon.h"

namespace NSNATIVE
{

long long int to_long(const string& vsLong, int* vcError)
{
    long long int vcRet = 0;
    istringstream vistringstream(vsLong);
    vistringstream >> vcRet;
#ifdef DEBUG
    int vcErrorInternal = vsLong.empty() || vistringstream.fail();

    if (vcError) {
        *vcError = vcErrorInternal;
    }
    if (vcErrorInternal) {
        vcRet = 0;
    }
#endif
    return vcRet;
}

vector<string> split(const string& str, const string& delimiter)
{
    //FIXME: UTF8 compatibility
    int i = 0;
    int j = 0;
    const char* sString = str.c_str();
    int cString = str.size();
    int cDelimiter = delimiter.size();
    vector<string> result;
    string token("");
    string current("");

    while (i < cString && cDelimiter) {
        current = "";

        for ( j = i ; j < cString && j < i + cDelimiter ; ++j ) {
            current += sString[j];
        }
        if (current == delimiter) {
            result.push_back(token);
            token = "";
            i += cDelimiter;
        } else {
            token += sString[i];
            i += 1;
        }
    }
    result.push_back(token);
    return result;
}

int utf8len(const string& vString)
{
    int ret = 0;
    const char* c = vString.c_str();
    while (*c) ret += (*c++ & 0xc0) != 0x80;
    return ret;
}

} // End namespace
