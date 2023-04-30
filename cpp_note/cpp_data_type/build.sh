#!/bin/bash
#这一行是表示使用 /bin/bash 作为脚本的解释器
#这行要放在脚本的行首并且不要省略。

# 删除之前的./build文件夹 (./build/存放编译中间文件,./build/bin/存放可执行文件) 
rm -rf build
# CMakeLists.txt中记得设置可执行文件的输出目录, 具体如下
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin) 

# 新建build文件夹
mkdir build

# 进入build文件夹
cd build

# 根据../CMakeLists.txt, 生成makefile文件
cmake ../

# 根据makefile文件, 生成可执行文件
make

