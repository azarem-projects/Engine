## C++ Game Engine

### External dependencies:

* <a href="https://github.com/assimp/assimp/releases/tag/v5.0.0">Assimp-5.0.0</a>
* <a href="https://github.com/nigels-com/glew/releases/tag/glew-2.1.0">GLEW-2.1.0</a>
* <a href="https://github.com/glfw/glfw/releases/tag/3.3.2">GLFW-3.3.2</a>


### Build:

To build the solution, you need to download all the dependencies and extract them into the "external" folder.

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

Open the generated solution in Visual Studio (make sure you use the latest version) and build the entire solution. Make sure you set "engine" as Startup Project.

External dependencies:
* GLEW-2.1.0
* GLFW-3.3.2
* Assimp-5.0.0
