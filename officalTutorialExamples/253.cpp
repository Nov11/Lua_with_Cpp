//
// Created by c6s on 17-6-2.
//

#include <lua5.2/lua.hpp>
#include <iostream>
#include "common.h"
#include <stdarg.h>
#include <cstring>

using namespace std;

void call_va(lua_State *L, const char *func, const char *sig, ...) {
    va_list vl;
    int narg, nres;  /* number of arguments and results */

    va_start(vl, sig);
    lua_getglobal(L, func);  /* get function */

    /* push arguments */
    narg = 0;
    while (*sig) {  /* push arguments */
        switch (*sig++) {

            case 'd':  /* double argument */
                lua_pushnumber(L, va_arg(vl, double));
                break;

            case 'i':  /* int argument */
                lua_pushnumber(L, va_arg(vl, int));
                break;

            case 's':  /* string argument */
                lua_pushstring(L, va_arg(vl, char *));
                break;

            case '>':
                goto endwhile;

            default:
                error(L, "invalid option (%c)", *(sig - 1));
        }
        narg++;
        luaL_checkstack(L, 1, "too many arguments");
    }
    endwhile:

    /* do the call */
    nres = static_cast<int>(strlen(sig));  /* number of expected results */
    if (lua_pcall(L, narg, nres, 0) != 0)  /* do the call */
        error(L, "error running function `%s': %s",
              func, lua_tostring(L, -1));

    /* retrieve results */
    nres = -nres;  /* stack index of first result */
    while (*sig) {  /* get results */
        switch (*sig++) {

            case 'd':  /* double result */
                if (!lua_isnumber(L, nres))
                    error(L, "wrong result type");
                *va_arg(vl, double *) = lua_tonumber(L, nres);
                break;

            case 'i':  /* int result */
                if (!lua_isnumber(L, nres))
                    error(L, "wrong result type");
                *va_arg(vl, int *) = (int) lua_tonumber(L, nres);
                break;

            case 's':  /* string result */
                if (!lua_isstring(L, nres))
                    error(L, "wrong result type");
                //this should be a string copy since I added pop operation after switch block
                //or the string may be invalid after pop off from the stack, which said in offical ref
                *va_arg(vl, const char **) = lua_tostring(L, nres);
                break;

            default:
                error(L, "invalid option (%c)", *(sig - 1));
        }
        lua_pop(L, 1);
        nres++;
    }
    va_end(vl);
}

int main() {
    lua_State *L = luaL_newstate();
    //so that lua scripts can use 'math' lib
    luaL_openlibs(L);
    //do use pcall before calling lua functions, or there will be nil value after getglobal
    if (luaL_loadfile(L, "scripts/f.lua") || lua_pcall(L, 0, 0, 0)) {
        error(L, "loading files:%s", lua_tostring(L, -1));
    }
    double x = 10;
    double y = 20;
    double result = 0;
    call_va(L, "f", "dd>d", x, y, &result);
    cout << result << endl;
    lua_close(L);
    return 0;
}
