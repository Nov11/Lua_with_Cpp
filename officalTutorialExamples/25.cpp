//
// Created by c6s on 17-6-2.
//

#include <iostream>
#include <lua5.2/lua.hpp>

#include "common.h"

using namespace std;


int main() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    int ret = luaL_loadfile(L, "scripts/config.lua") || lua_pcall(L, 0, 0, 0);
    if (ret) {
        error(L, "%s", lua_tostring(L, -1));
    }

    lua_getglobal(L, "width");
    lua_getglobal(L, "height");

    if (!lua_isnumber(L, -1)) {
        error(L, "height should be a number");
    }
    if (!lua_isnumber(L, -2)) {
        error(L, "width should be a number");
    }

    int width = static_cast<int>(lua_tonumber(L, -2));
    int height = static_cast<int>(lua_tonumber(L, -1));

    cout << "width:" << width << " height:" << height << endl;
    lua_close(L);
}