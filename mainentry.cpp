
#include "mainLua.hpp"
#include <iostream>
#include <string.h>
using namespace std;
#include "lua.hpp"

int main(void)
{
    aa onetime;
    onetime.sayhello();
    // 1 create a new state
    lua_State *L = luaL_newstate();
    if (L == NULL)
    {
        return 0;
    }
    // 2 load lua file
    int bRet = luaL_loadfile(L, "hello.lua");
    if (bRet)
    {
        cout << "load file error" << endl;
        return 0;
    }
    // 3 run lua file
    bRet = lua_pcall(L, 0, 0, 0);
    if (bRet)
    {
        cout << "pcall error" << endl;
        return 0;
    }
    // 4 read variable
    lua_getglobal(L, "str");
    string str = lua_tostring(L, -1);
    cout << "str=" << str.c_str() << endl;
    // 5 read table
    lua_getglobal(L, "tbl");
    lua_getfield(L, -1, "name");
    str = lua_tostring(L, -1);
    cout << "tbl:name=" << str.c_str() << endl;
    // 6 read function
    lua_getglobal(L, "add");
    lua_pushnumber(L, 10);
    lua_pushnumber(L, 20);
    int iRet = lua_pcall(L, 2, 1, 0);
    if (iRet)
    {
        const char *pErrorMsg = lua_tostring(L, -1);
        cout << pErrorMsg << endl;
        lua_close(L);
        return 0;
    }
    if (lua_isnumber(L, -1))
    {
        double fValue = lua_tonumber(L, -1);
        cout << "Result is " << fValue << endl;
    }
    // close state
    lua_close(L);

    return 0;
}