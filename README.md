# qtcsv-example

[![Build Status](https://travis-ci.org/iamantony/qtcsv-example.svg?branch=master)](https://travis-ci.org/iamantony/qtcsv-example) [![Build status](https://ci.appveyor.com/api/projects/status/s1q16r12r2m4wk5k/branch/master?svg=true)](https://ci.appveyor.com/project/iamantony/qtcsv-example/branch/master)

This is an example project that shows how to use [qtcsv][qtcsv] library.

In [main.cpp][main-file] file you will see code that write and read csv-file.

Tested on:
- Ubuntu 14.04 with gcc 4.8.4, Qt 4.8 and higher
- Windows with MinGW, Qt 5.3 and higher
- macOS with clang, Qt 4.8, 5.5, 5.7 and higher

## How to download project

- Download zip-archive with project files from GitHub
- Or clone this repository using _**git clone**_ command:

  ``` bash
  git clone https://github.com/iamantony/qtcsv-example.git
  cd qtcsv-example
  git submodule update --init --recursive
  ```

## Build and run

- Open this project in QtCreator and start build and run operations in it
- Or run this commands in console:

### Linux, macOS
  
#### Using qmake
  
``` bash
cd /path/to/folder/with/qtcsv-example

# Create build directory
mkdir ./build
cd ./build

# Build qtcsv library and qtcsv-example binary. You can choose build type: release or debug
qmake ../qtcsv-example.pro CONFIG+=[release|debug] LIBS+=-L../qtcsv
make

# Execute qtcsv-example
cd ./example

# On macOS use DYLD_LIBRARY_PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/../qtcsv

./example
```

#### Using cmake

``` bash
cd /path/to/folder/with/qtcsv-example

# Create build directory
mkdir ./build
cd ./build

# Build qtcsv library and qtcsv-example binary. You can choose build type: release or debug
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=OFF ..
make

# Execute qtcsv-example
cd ./example

# On macOS use DYLD_LIBRARY_PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/../qtcsv

./example
```

### Windows

#### Using qmake

``` bash
cd C:\path\to\folder\with\qtcsv-example

# Create build directory
mkdir .\build
cd .\build

# Build qtcsv library. You can choose build type: release or debug.
# Set DESTDIR to current directory.
qmake ..\qtcsv\qtcsv.pro CONFIG+=[release|debug] DESTDIR=%cd%
mingw32-make

# Build example binary.
qmake ..\example\example.pro CONFIG+=release DESTDIR=%cd%
mingw32-make

example.exe
```

#### Using cmake

``` bash
cd C:\path\to\folder\with\qtcsv-example

# Create build directory
mkdir .\build
cd .\build

# Build qtcsv library and example binary. You can choose build type: release or debug.
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=OFF ..
mingw32-make

copy ..\qtcsv\*qtcsv.dll .\example
cd .\example

example.exe
```

[qtcsv]: https://github.com/iamantony/qtcsv
[main-file]: https://github.com/iamantony/qtcsv-example/blob/master/example/main.cpp
