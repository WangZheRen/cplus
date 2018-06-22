//
// Created by Zhou,Baochuan on 18/6/7.
//

#ifndef WORK_STRING_UTIL_H
#define WORK_STRING_UTIL_H

#include "common.h"

namespace work{
    class StringUtil {
    public:
        StringUtil();
        ~StringUtil();
        static wstring string2wstring(const string str);
        static string wstring2string(const wstring str);
        static string strip_tag(const string str);
    };
}


#endif //WORK_STRING_UTIL_H
