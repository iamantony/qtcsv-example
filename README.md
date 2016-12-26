# qtcsv-example

[![Build Status](https://travis-ci.org/iamantony/qtcsv-example.svg?branch=dev)](https://travis-ci.org/iamantony/qtcsv-example) [![Build status](https://ci.appveyor.com/api/projects/status/s1q16r12r2m4wk5k/branch/master?svg=true)](https://ci.appveyor.com/project/iamantony/qtcsv-example/branch/master)

This is an example project that shows how to use [qtcsv][qtcsv] library.

In [main.cpp][main-file] file you will see code that write and read csv-file.

Tested on:
- Ubuntu 14.04 with gcc 4.8.4, Qt 4.8 and higher
- Windows with MinGW, Qt 5.3 and higher

## How to download project
1. Download zip-archive with project files from GitHub
2. Or clone this repository using _**git clone**_ command:

  ``` bash
  git clone https://github.com/iamantony/qtcsv-example.git
  git submodule update --init --recursive
  ```

## Build and run
1. Open this project in QtCreator and start build and run operations in it 
2. Or run this commands in console:

  ### Linux
  ``` bash
  qmake -r
  make
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/qtcsv
  cd ./example
  ./example
  ```
  
  ### Windows
  ``` bash
  qmake -r
  cd ./qtcsv
  make
  cp ./qtcsv.dll ../example
  cd ../example
  make
  example.exe
  ```

[qtcsv]: https://github.com/iamantony/qtcsv
[main-file]: https://github.com/iamantony/qtcsv-example/blob/master/example/main.cpp
