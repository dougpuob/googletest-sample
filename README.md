googletest-sample
=================

Build
-----
``` bash
git submodule init
git submodule update

# Windows with MSVC 2019
cmake -G "Visual Studio 16 2019" -B "build" .
cmake --build build --config Release

# Linux
cmake -G "Ninja" -B "build" .
cmake --build build --config Release
```

Samples
-------
- [Test derived function by interface](https://github.com/dougpuob/googletest-sample/blob/master/source/test-derived-func-by-interface/Main.cpp) ([img](https://i.imgur.com/NuduigD.png))
