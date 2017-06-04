//
// Created by c6s on 17-6-4.
//
#include <lua5.2/lua.hpp>
#include <cmath>
#include <dirent.h>
#include <errno.h>
#include <cstring>
#include "common.h"
using namespace std;


static int l_sin (lua_State *L) {
    double d = luaL_checknumber(L, 1);  /* get argument */
    lua_pushnumber(L, sin(d));  /* push result */
    return 1;  /* number of results */
}



static int l_dir (lua_State *L) {
    DIR *dir;
    struct dirent *entry;
    int i;
    const char *path = luaL_checkstring(L, 1);

    /* open directory */
    dir = opendir(path);
    if (dir == NULL) {  /* error opening the directory? */
        lua_pushnil(L);  /* return nil and ... */
        lua_pushstring(L, strerror(errno));  /* error message */
        return 2;  /* number of results */
    }

    /* create result table */
    lua_newtable(L);
    i = 1;
    while ((entry = readdir(dir)) != NULL) {
        lua_pushnumber(L, i++);  /* push key */
        lua_pushstring(L, entry->d_name);  /* push value */
        lua_settable(L, -3);
    }

    closedir(dir);
    return 1;  /* table is already on top */
}

int main(){
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    lua_pushcfunction(L, l_dir);
    lua_setglobal(L, "l_dir");
    lua_register(L, "l_sin", l_sin);

    if (luaL_loadfile(L, "scripts/calledinlua.lua") || lua_pcall(L, 0, 0, 0)) {
        error(L, "loading files:%s", lua_tostring(L, -1));
    }

    lua_close(L);
    return 0;
}