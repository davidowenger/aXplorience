#include "NCommon.h"

namespace NSNATIVE
{

float to_float(const String& vFloatString, int* vError)
{
    float vRet = 0;
    istringstream vIStringStream(vFloatString);
    vIStringStream >> vRet;
#ifdef DEBUG
    int vErrorInternal = vFloatString.empty() || vIStringStream.fail();

    if (vError) {
        *vError = vErrorInternal;
    }
    if (vErrorInternal) {
        vRet = 0;
    }
#endif
    return vRet;
}

long long int to_long(const String& vLongString, int* vError)
{
    long long int vRet = 0;
    istringstream vIStringStream(vLongString);
    vIStringStream >> vRet;
#ifdef DEBUG
    int vErrorInternal = vLongString.empty() || vIStringStream.fail();

    if (vError) {
        *vError = vErrorInternal;
    }
    if (vErrorInternal) {
        vRet = 0;
    }
#endif
    return vRet;
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
