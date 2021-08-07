googletest-sample
=================

Build
-----
``` bash
git submodule init
git submodule update

# Windows with MSVC 2019
cmake -G "Visual Studio 16 2019" -B "build" .
camke --build build --config Release

# Linux
cmake -G "Ninja" -B "build" .
camke --build build --config Release
```