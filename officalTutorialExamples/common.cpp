//
// Created by c6s on 17-6-2.
//

#include <cstdio>
#include <cstdlib>
#include "common.h"
void error (lua_State* L, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    lua_close(L);
    exit(EXIT_FAILURE);
}