# qtcsv-example
This is an example project that shows how to use [qtcsv][qtcsv] library.

In [main.cpp][main-file] file you will see code that write and read csv-file.

## How to download project
1. Download zip-archive with project files from GitHub
2. Clone this repository using _**git clone**_ command:

  ``` bash
  git clone https://github.com/iamantony/qtcsv-example.git
  git submodule update --init --recursive
  ```

## Build and run:
1. Open this project in QtCreator and start build and run operations in it 
2. Run this commands in console:

  ``` bash
  qmake -r
  make
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/qtcsv/src
  cd ./example
  ./example
  ```

Tested on Ubuntu 14.04 64bit with Qt 4.8.6 and higher.

[qtcsv]: https://github.com/iamantony/qtcsv
[main-file]: https://github.com/iamantony/qtcsv-example/blob/master/example/main.cpp
