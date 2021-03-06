# utilcpp-math

[![Build Status](https://travis-ci.org/camieac/utilcpp-math.svg?branch=master)](https://travis-ci.org/camieac/utilcpp-math)
[![codecov](https://codecov.io/gh/camieac/utilcpp-math/branch/master/graph/badge.svg)](https://codecov.io/gh/camieac/utilcpp-math)

## Introduction

`utilcpp-math` a C++ maths library, originally designed for use in computer graphics for games programming.
Currently, only vectors are implemented, but support for matrices and other useful mathematic constructs and operations may be added in the future.
This library is graphics library agnostic, meaning it can be used with OpenGL, or any other graphics library. This library can also me use for any other application requiring vector maths.

## Purpose
The purpose of this library is to provide more advanced mathematical constructs, for any application.

## Code Example
A full example, making use of the full `utilcpp-math` API is available in [example](https://github.com/camieac/utilcpp-math/blob/master/example/utilcpp-math-example.c). A 3-dimentional vector example is given below:
```
#include <utilcpp-math.h>
#include <iostream>
using namespace std;

vec3 v1(1.0f, 1.0f, 3.0f);
vec3 v2(1.0f, 1.0f, 3.0f);
vec3 v3;

//Vector arithmetic
v3 = v1 + v2;
v3 = v1 - v2;

v3 = v1.dot(v2);
v3 = v1.cross(v2);

//Scalar arithmetic
v3 = v1 + 10.0f;
v3 = v1 - 24.0f;
v3 = v1 * 32.0f;
v3 = v1 / 16.0f;

//Shorthand operators
v3 += 9.0f;
v3 -= 9.0f;
v3 *= 9.0f;
v3 /= 9.0f;

v3 += v1;
v3 -= v1;

//length
float len = v1.length();

//Accessing individual elements
float ax = a[0];
float ay = a[1];
float az = a[2];

ax = a.x;
ay = a.y;
az = a.z;

ax = a.r;
ay = a.g;
az = a.b;

//Print
cout << v1.toString() << endl;
```

## Installation
This project uses [CMake](https://cmake.org/) to build, test, and install `utilcpp-math`. Installation instructions are contained within [INSTALL.md](https://github.com/camieac/utilcpp-math/blob/master/INSTALL.md), and summarised below:

```
git clone https://github.com/camieac/utilcpp-math.git
cd utilcpp-math
cmake .
make
sudo make install
```

You are also free to add the source files to your own project, and build yourself. Subject the GPL-3.0 license.

## License
This project is released under the [General Public License 3.0 (GPL-3.0)](https://github.com/camieac/utilcpp-math/blob/master/LICENSE).

## Contributing
Any contribution is welcome. The best way to do this is through Pull Requests. See [CONTRIBUTING.md](https://github.com/camieac/utilcpp-math/blob/master/CONTRIBUTING.md) for more info. In summary: fork, commit changes to fork, pull request. See the [Github Help](https://help.github.com/articles/creating-a-pull-request-from-a-fork/) pages for further information.

## Authors
Cameron A. Craig (@camieac)
