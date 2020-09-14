## C++ Game Engine

### External dependencies:

* <a href="https://github.com/assimp/assimp/releases/tag/v5.0.0">Assimp-5.0.0</a>
* <a href="https://github.com/nigels-com/glew/releases/tag/glew-2.1.0">GLEW-2.1.0</a>
* <a href="https://github.com/glfw/glfw/releases/tag/3.3.2">GLFW-3.3.2</a>

By default, all the dependencies need to be stored in the folder "external" in the root. The path to this folder can be changed in CMakeLists.txt. In order to do so, I provided all the paths as cmake-variables:

```cmake
    GLEW_PATH
    GLEW_INCLUDE_DIR
    
    GLFW_PATH
    GLFW_INCLUDE_DIR
    
    ASSIMP_PATH
    ASSIMP_INCLUDE_DIR
```


### Build:

In order to build the solution, you need to download all the dependencies and extract them into the "external" folder.

```sh
    mkdir build
    cd build
    cmake ..
```

### Linux:

```sh
    make -j4
```

### Windows:

Open the generated .sln file in Visual Studio (make sure you use the latest version) and build the entire solution. Make sure you set "engine" as Startup Project.

### Software used:

#### Build & Compilation & Editing:

* VSCode 1.49.0
* CMake 3.16.3
* clang 10.0.1-1\~oibaf\~f

#### Project:

* Assimp 5.0.0
* GLEW 2.1.0
* GLFW 3.3.2
