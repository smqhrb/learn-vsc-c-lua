
#include "mainLua.hpp"
#include <iostream>
#include <string.h>
using namespace std;
extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
int main(void)
{
    aa onetime;
    onetime.sayhello();
    //1 create a new state
    lua_state *L = luaL_newstate();
    if (L == NULL)
    {
        return;
    }
    //2 push to stack
    lua_pushstring(L, "I am so cool~");
    lua_pushnumber(L, 20)

        //3 get
        if (lua_isstring(L, 1))
    {
        cout << lua_tostring(L, 1) << endl;
    }
    if (lua_isnumber(L, 2))
    {
        cout << lua_tonumber(L, 2) << endl;
    }
    //4 close state
    lua_close(L);

    return 0;
}