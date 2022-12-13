# C++ CMake Template

## Build Instructions

### Command Line

```bash
cmake --preset linux-debug
cmake --build --preset linux-debug
```

The debug build of `hello_world` can be found in: `./out/build/linux-debug/src/hello_world/hello_world`.
The `math` tests are also built as a part of this preset, the test executable can run from `./out/build/linux-debug/src/math/test_math`

### VSCode

Using the `cmake-tools` extension, a toolbar along the bottom can be used to configure which presets are run.
This toolbar also enables running the program in debug mode, allowing the developer to step through the code and add breakpoints.

Finally, the `vscode-catch2-test-adapter` extension can be used to enable the use of VSCodes Testing view.
The tests can be run individually and in debug mode from here.
Unfortunately, when changing the code, the test executable is not automatically rebuilt, so a new build will be needed before re-running the tests.

## Testing

Once the `linux-debug` configure preset has been built, we can run the tests as follows.

### Command Line

`ctest` can be used to discover and execute the test programs we want to run.

```bash
$ ctest --test-dir ./out/build/linux-debug --preset=linux-test -T test
Internal ctest changing into directory: /home/max/Git/GitHub/cpp_cmake_template/out/build/linux-debug
   Site: pop-os
   Build name: Linux-c++
Test project /home/max/Git/GitHub/cpp_cmake_template/out/build/linux-debug
    Start 1: Additions are computed
1/2 Test #1: Additions are computed ...........   Passed    0.01 sec
    Start 2: Multiplications are computed
2/2 Test #2: Multiplications are computed .....   Passed    0.01 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```

### VSCode

Using the `cmake-tools` extension again, along the bottom toolbar will be an option to choose the test preset and a button to execute the tests.

