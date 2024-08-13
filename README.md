# Transform

[Transform](https://github.com/Ediu3095/transform) is a header only C++ mathematics library for graphics software based on [GLM](https://github.com/g-truc/glm) and [Real-Time Rendering](https://www.realtimerendering.com/).

*Transform* provides classes and functions to operate on vectors and matrices so that anyone who has read *Real-Time Rendering* can apply the concepts explained in the book to their code.

This project is written in C++20. It is a platform independent library supporting the following compilers:

- [Clang](https://llvm.org/) 14.0 and higher
- [GCC](https://gcc.gnu.org/) 11.4 and higher
- [MSVC](https://visualstudio.microsoft.com/) 2022 and higher

## Project Health

![Clang](https://github.com/Ediu3095/transform/actions/workflows/clang.yml/badge.svg) ![GCC](https://github.com/Ediu3095/transform/actions/workflows/gcc.yml/badge.svg) ![MSVC](https://github.com/Ediu3095/transform/actions/workflows/msvc.yml/badge.svg)

## CMake using git submodule

You can add *Transform* to your CMake project to be built together. Add the project as a submodule with:

```bash
git submodule add -- https://github.com/Ediu3095/transform.git path/to/transform
```

Then compile it along with the rest of your project by adding the following to your `CMakeLists.txt`:

```cmake
add_subdirectory(path/to/transform)
target_link_libraries(main PRIVATE transform::transform)
```

## CMake using FetchContent

If your project is not a git repository, another way to add *Transform* so that they are both compiled together is by using `FetchContent`. Add the following to your `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.11) # FetchContent is new in version 3.11.

include(FetchContent)

FetchContent_Declare(
	transform
	GIT_REPOSITORY	https://github.com/Ediu3095/transform.git
	GIT_TAG 	b0c625e2c9793070d3bac9adff54e7544e73252d
)

FetchContent_MakeAvailable(transform)

target_link_libraries(main PRIVATE transform::transform)
```
