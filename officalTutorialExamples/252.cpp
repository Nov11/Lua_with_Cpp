//
// Created by c6s on 17-6-2.
//

#include <lua5.2/lua.hpp>
#include <iostream>
#include "common.h"
using namespace std;

double callLuaFun(lua_State* L, double x, double y){
    lua_getglobal(L, "f");
    lua_pushnumber(L, x);
    lua_pushnumber(L, y);
    if(lua_pcall(L, 2, 1, 0)){error(L, "%s", lua_tostring(L, -1));}
    double result = 0;
    getNumber(L, result);
    return result;
}

int main(){
    lua_State* L = luaL_newstate();
    //so that lua scripts can use 'math' lib
    luaL_openlibs(L);
    //do use pcall before calling lua functions, or there will be nil value after getglobal
    if(luaL_loadfile(L, "scripts/f.lua") || lua_pcall(L, 0, 0, 0)){
        error(L, "loading files:%s", lua_tostring(L, -1));
    }
    double x = 10;
    double y = 20;
    cout << callLuaFun(L, x, y) << endl;
    lua_close(L);
    return 0;
}