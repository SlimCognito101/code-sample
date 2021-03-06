# code-sample
Sample C++ application using OpenGL, demonstrating texture mapping and vector math

## requirements
- OpenGL version 4.1. 3.x versions are supported, but must change version in driver.cpp and test.cpp.
- CMake version 2.8 or above.

## building and running
### Linux/UNIX systems
- From a terminal window, `cd` into root directory of project and create a build folder with `mkdir build`
- navigate into build folder `cd build`
- create makefile with CMake `cmake -G 'Unix Makefiles' ..`
- build project `make`
- run project `./CodeSample`

### Windows and MacOS
- Consult CMake documentation at https://cmake.org/cmake/help/latest/guide/tutorial/index.html#build-and-test

## running tests
- Change "src" to "test" in lines 12-14 in CMakeLists.txt and build.

## changelog
- Created window class
- Created driver to run application
- Wrote tests for window initialization
- tested and modified driver code
