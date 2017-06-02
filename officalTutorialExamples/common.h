//
// Created by c6s on 17-6-2.
//

#ifndef EMBEDLUA_COMMON_H
#define EMBEDLUA_COMMON_H

#include <lua5.2/lua.h>

//as files in this directory is so simple, I will not wrap this in namespace
void error (lua_State* L, const char* fmt, ...);
#endif //EMBEDLUA_COMMON_H
