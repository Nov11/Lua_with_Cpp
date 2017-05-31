//run sudo apt-get install lua5.2 liblua5.2-dev before compiling
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
 
int main()
{
    int s=0;
 
    lua_State *L = luaL_newstate();
 
    // load the libs
    luaL_openlibs(L);
 
    //run a Lua scrip here
    luaL_dofile(L,"foo.lua");
 
    printf("\nI am done with Lua in C++.\n");
 
    lua_close(L);
 
    return 0;
}
