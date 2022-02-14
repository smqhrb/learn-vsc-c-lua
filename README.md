# learn-vsc-c-lua
configure vsc to debug c++ and lua
# lua
https://blog.csdn.net/shun_fzll/article/details/39120965
# configure VSC c++
https://blog.csdn.net/qq_33973359/article/details/105720511?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase
# refer github
https://github.com/cslarsen/lua-cpp
# tools
Visual studio code / win10
lua-5.4.3 - https://www.lua.org/download.html
mingw64-8.1.0-release

# compile in src
gcc -c -DLUA_BUILD_AS_DLL *.c
ren lua.o lua.obj
ren luac.o luac.obj
ar rcs lua524-static.lib  *.o
gcc -shared -o lua524.dll -Wl,--out-implib,lua524.lib *.o
gcc lua.obj lua524.lib -o lua524.exe
gcc luac.obj lua524-static.lib -o luac524.exe
del *.o *.obj