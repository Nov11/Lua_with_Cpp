//
// Created by c6s on 17-6-2.
//
//ref : http://www.cnblogs.com/stephen-liu74/archive/2012/07/20/2460634.html
#include <cstdio>
#include <string>
#include <lua5.2/lua.hpp>
#include "common.h"

using namespace std;
#define MAX_COLOR       255

/* assume that table is on the stack top */
int getfield(lua_State *L, const char *key) {
    int result;
    lua_pushstring(L, key);
    lua_gettable(L, -2);  /* get background[key] */
    if (!lua_isnumber(L, -1))
        error(L, "invalid component in background color");
    result = static_cast<int>( lua_tonumber(L, -1) * MAX_COLOR);
    lua_pop(L, 1);  /* remove number */
    return result;
}

/* assume that table is at the top */
void setfield(lua_State *L, const char *index, double value) {
    lua_pushstring(L, index);
    lua_pushnumber(L, value);
    lua_settable(L, -3);
}

int main() {
    lua_State *L = luaL_newstate();

    if (luaL_loadstring(L, "background = { r = 0.30, g = 0.10, b = 0 }")
        || lua_pcall(L, 0, 0, 0)) {
        error(L, "Error Msg is %s.\n", lua_tostring(L, -1));

    }
    lua_getglobal(L, "background");
    if (!lua_istable(L, -1)) {
        error(L, "'background' is not a table.\n");
    }
//    lua_getfield(L, -1, "r");
//    if (!lua_isnumber(L, -1)) {
//        printf("Invalid component in background color.\n");
//        return;
//    }
//    int r = static_cast<int> (lua_tonumber(L, -1) * 255);
//    lua_pop(L, 1);
    int r = getfield(L, "r");

//    lua_getfield(L, -1, "g");
//    if (!lua_isnumber(L, -1)) {
//        printf("Invalid component in background color.\n");
//        return;
//    }
//    int g = static_cast<int> (lua_tonumber(L, -1) * 255);
//    lua_pop(L, 1);
    int g = getfield(L, "g");

//    lua_pushnumber(L, 0.4);
//    lua_setfield(L, -2, "b");
    setfield(L, "b", 0.4);


//    lua_getfield(L, -1, "b");
//    if (!lua_isnumber(L, -1)) {
//        printf("Invalid component in background color.\n");
//        return;
//    }
//    int b = static_cast<int> (lua_tonumber(L, -1) * 255);
    int b = getfield(L, "b");
    printf("r = %d, g = %d, b = %d\n", r, g, b);

    lua_close(L);
    return 0;
}