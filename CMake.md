## 1. CMake 概念  

1.1定义：CMake 是一个跨平台的构建系统生成器。它不直接构建项目，而是根据一个名为 CMakeLists.txt 的配置文件，生成标准的构建文件。

    解决的问题：生成 Makefile,开发者无需为每个平台编写不同的构建脚本。

**1.2 CMake 的工作机制**  
    A[源代码] --> B(CMakeLists.txt 配置文件)；  
    B --> C[CMake 命令]；  
    C --> D{生成}；  
    D --> E[原生构建系统Makefile, .sln, .xcodeproj]；  
    E --> F[make, msbuild, xcodebuild]；  
    F --> G[最终目标<br>可执行文件， 库文件]；  
1.编写 CMakeLists.txt：在项目根目录，用 CMake 语法描述如何构建项目。

2.执行 cmake：在构建目录（通常是 build）下运行 cmake <源码路径>。CMake 会解析 CMakeLists.txt，检查编译器、依赖库等，并生成对应平台的构建文件。

3.执行原生构建命令：使用生成的构建文件进行实际编译链接，如 make（Linux）、ninja 或 Visual Studio 的构建工具。

## 2.编写 CMakeLists.txt 核心指令
  
**2.1 基础指令**

cmake_minimum_required(VERSION ...)

作用：指定 CMake 的最低（和可选的最高）版本要求

---

project( [LANGUAGES])

作用：定义项目名称，并可以指定编程语言（如 C， CXX）。它会设置一些关键变量，如 PROJECT_NAME, PROJECT_SOURCE_DIR, _SOURCE_DIR。

示例：project(MyAwesomeApp LANGUAGES CXX)

---

add_executable( [source1] [source2] ...)

作用：告诉 CMake 从指定的源文件生成一个可执行文件。

示例：add_executable(my_app main.cpp helper.cpp)

---

add_library( [STATIC | SHARED | MODULE] [source1] [source2] ...)

作用：从源文件生成一个库。

STATIC：静态库（.a / .lib）

SHARED：动态库/共享库（.so / .dll）

MODULE：模块库（插件）

示例：add_library(my_lib STATIC lib.cpp)

---

**2.2 链接与包含**

target_link_libraries( <PRIVATE|PUBLIC|INTERFACE> <item>...)

作用：将一个目标（可执行文件或库）与另一个库链接起来。这是现代 CMake 推荐的链接方式。

可见性说明：

PUBLIC： <target>需要使用 item，并且 item 是<font style="background-color:#FFFFFF;"> </font><font style="background-color:#FFFFFF;"><target>  </font>接口的一部分（头文件包含了 item 的头文件）。依赖会传递。

PRIVATE： <target>需要使用 item，但 item 只是实现细节，不暴露给使用者。

INTERFACE： <target>本身不使用 item，但使用 <target> 的其他目标需要使用 item（常用于头文件库）。

示例：target_link_libraries(my_app PRIVATE my_lib)

---

include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])

作用：将指定目录添加到所有目标的头文件搜索路径中。这是一个全局设置。

---

target_include_directories( [SYSTEM] [BEFORE] <INTERFACE|PUBLIC|PRIVATE> [items...])

作用：为特定目标 target 添加头文件搜索路径。可以精细控制可见性（PRIVATE/PUBLIC/INTERFACE），与 target_link_libraries 的概念一致。



## 3. 管理多模块工程
  
**3.1 add_subdirectory()**

作用：让 CMake 处理子目录中的 CMakeLists.txt 文件。

项目结构：

text  
MyProject/  
├── CMakeLists.txt  
├── app/  
│       ├── CMakeLists.txt  
│       └── main.cpp  
└── lib/  
    ├── CMakeLists.txt  
    ├── include/my_lib.h  
    └── src/my_lib.cpp

---

  
**根目录 CMakeLists.txt:**

cmake_minimum_required(VERSION 3.16)  
project(MyProject)  
add_subdirectory(lib) # 先构建库  
add_subdirectory(app) # 再构建应用，它依赖库

l**ib/CMakeLists.txt:**

add_library(my_lib STATIC src/my_lib.cpp)  
target_include_directories(my_lib PUBLIC include) # 公开头文件目录

**app/CMakeLists.txt:**

add_executable(my_app main.cpp)  
target_link_libraries(my_app PRIVATE my_lib) # 链接库，自动获取其头文件路径

## 4. 查找并链接第三方库
**4.1 find_package()**

作用：查找并加载外部项目的设置。它会提供导入的目标、宏和变量。

find_package(OpenCV REQUIRED)

OpenCV：要查找的包名。

REQUIRED：可选，如果找不到该包，则停止配置并报错。

---

1.CMake 会在模块路径（如 /usr/share/cmake-3.x/Modules/）中查找 FindOpenCV.cmake 脚本。

2.该脚本会搜索系统的头文件、库文件路径，并设置一系列变量，如 OpenCV_FOUND, OpenCV_INCLUDE_DIRS, OpenCV_LIBS。在现代 CMake 中，它通常还会定义一个导入的目标 OpenCV::OpenCV。

**4.2 使用找到的包**(现代方式)：  
find_package(OpenCV REQUIRED)  
target_link_libraries(my_app PRIVATE OpenCV::OpenCV)  


## 5.源码外构建


#在项目根目录下

mkdir build && cd build    # 1. 创建并进入构建目录  
cmake ..                              # 2. 配置项目，生成构建系统（'..' 表示上一级目录，即源码位置）  
make                                  # 3. 执行实际构建（如果是Makefile）  
./my_app                             # 4. 运行生成的可执行文件

##   
6. 安装与配置
  
**install() 指令**

作用：指定项目在 make install 时应被安装的规则。

安装目标：

#安装可执行文件

install(TARGETS my_app DESTINATION bin)

#安装静态/动态库

install(TARGETS my_lib DESTINATION lib)

#安装头文件

install(FILES include/my_lib.h DESTINATION include)

#安装整个目录

install(DIRECTORY docs/ DESTINATION share/doc/my_project)

**指定安装路径：**

在执行 cmake 时使用 -DCMAKE_INSTALL_PREFIX=/path/to/install。

