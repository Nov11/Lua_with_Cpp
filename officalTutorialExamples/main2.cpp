//run sudo apt-get install lua5.2 liblua5.2-dev before compiling
extern "C" {
#include <lua5.2/lua.h>
#include <lua5.2/lualib.h>
#include <lua5.2/lauxlib.h>
}
 
int main()
{
    printf("headers with lua5.2\n");
 
    lua_State *L = luaL_newstate();
 
    // load the libs
    luaL_openlibs(L);
 
    //run a Lua scrip here
    luaL_dofile(L,"scripts/foo.lua");
 
    printf("\nI am done with Lua in C++.\n");
 
    lua_close(L);
 
    return 0;
}
