//
// Created by c6s on 17-6-2.
//

//http://www.lua.org/pil/24.2.3.html


//lua_typename is not reliable


#include <lua5.2/lua.hpp>
#include <iostream>
#include <string>

using namespace std;

void stackDump(lua_State *L) {
    int len = lua_gettop(L);
    int ret = 0;
    for (int i = 1; i <= len; i++) {
        int t = lua_type(L, i);
        switch (t) {
            case LUA_TBOOLEAN:
                ret = lua_toboolean(L, i);
                cout << (ret ? "true" : "false'");
                break;
            case LUA_TNUMBER: {
                double d = lua_tonumber(L, i);
                cout << d;
                break;
            }

            case LUA_TSTRING: {
                string s(lua_tostring(L, i));
                cout << s;
                break;
            }
            case LUA_TNIL:{
                cout << "nil";
                break;
            }
            default:
                cout << lua_typename(L, i);
        }
//        cout << lua_typename(L, i) <<"|"<<lua_type(L, i);
        cout << " ";
    }
    cout << endl;
}

int main(void) {
    lua_State *L = luaL_newstate();
    lua_pushboolean(L, 1);
    lua_pushnumber(L, 10);
    lua_pushnil(L);
    lua_pushstring(L, "hello");
    stackDump(L);
    /* true  10  nil  `hello'  */

    lua_pushvalue(L, -4);
    stackDump(L);
    /* true  10  nil  `hello'  true  */

    lua_replace(L, 3);
    stackDump(L);
    /* true  10  true  `hello'  */

    lua_settop(L, 6);
    stackDump(L);
    /* true  10  true  `hello'  nil  nil  */

    lua_remove(L, -3);
    stackDump(L);
    /* true  10  true  nil  nil  */

    lua_settop(L, -5);
    stackDump(L);
    /* true  */

    lua_close(L);
    return 0;
}

