# 最小版本，可以通过cmake --version查看
cmake_minimum_required(VERSION 3.5.1)
 
# 项目名称，建议大写
project(CPP_LEARN)
 
# 支持c++11
# 第一种方式:(根据camke版本调整)
set(CMAKE_CXX_STANDARD 11)  # CMake 3.1或者更高版本支持使用这个
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # CMake更低版本使用
# 第二种方式:
# add_compile_options(-std=c++11)


# -------------------------------------------添加头文件路径------------------------------------------------
# 搜索自定义的头文件目录，可以使用绝对路径 ${CMAKE_SOURCE_DIR}/include
# include_directories(${PROJECT_SOURCE_DIR}/include)  # 使用绝对路径最好  # PROJECT_SOURCE_DIR:代表的工程的路径 
# 或者include_directories(./include)  # 需要注意当前CMakeLists.txt和include相对路径关系, 此时必须是在同一个目录下
# 或者include_directories(include)    # 需要注意当前CMakeLists.txt和include相对路径关系, 此时必须是在同一个目录下

include_directories(${PROJECT_SOURCE_DIR}/include)                        
# 添加了头文件路径/include,就可以#include "swap.h" 而不需要 #include "include/swap.h"
include_directories(${PROJECT_SOURCE_DIR}/include/class_inherit_depart)   
# 添加了头文件路径/include/class_inherit_depart, 就可以#include "rectangle_class.h" 而不需要 #include "/include/class_inherit_depart/rectangle_class.h"
include_directories(${PROJECT_SOURCE_DIR}/include/template)   
# 添加了头文件路径/include/template, 就可以#include "template_func.h" 而不需要 #include "/include/template/template_func.h"
# -------------------------------------------------------------------------------------------------------------------

# -------------------------------------------生成可执行文件--------------------------------------------------------
# 方法一：直接一个个指定
# 1、如果main.cpp不在src中，则
#    add_executable(main main.cpp src/swap.cpp) # 生成可执行文件命令，第一个参数是生成可执行文件的名称，后面的参数是源文件代码
# 2、如果main.cpp在src中，则
#    add_executable(main src/main.cpp src/swap.cpp)

# 方法二：定义变量，使用${}取出值。
# 1、如果main.cpp不在src中，则
#   set(SRC_LIST src/swap.cpp)  
#   add_executable(main main.cpp ${SRC_LIST})
# 2、如果main.cpp也在src中，则
#   set(SRC_LIST src/main.cpp src/swap.cpp)  
#   add_executable(main ${SRC_LIST})

# 方法三：选择src文件夹下面的所有文件      （# 前两种方法适合源码文件比较少的情况下。如果src文件夹下面有几千几百个源文件，就第三种方法）
#    aux_source_directory(./src SRC_LIST)                         
#    add_executable(main main.cpp ${SRC_LIST} ${SRC_LIST_1})      
# 如果main.cpp在src中，则add_executable(main ${SRC_LIST})

aux_source_directory(./src SRC_LIST)                            
# 把./src目录下的所有源文件都添加到SRC_LIST源列表变量里面去
aux_source_directory(./src/class_inherit_depart SRC_LIST_1)     
# 把./src/class_inherit_depart目录下的所有源文件都添加到SRC_LIST_1源列表变量里面去
aux_source_directory(./src/template SRC_LIST_2)  
# 把./src/template目录下的所有源文件都添加到SRC_LIST_2源列表变量里面去

add_executable(main main.cpp ${SRC_LIST} ${SRC_LIST_1} ${SRC_LIST_2}) 
# 生成可执行文件命令，第一个参数是生成可执行文件的名称main，后面的参数是源文件/源文件列表 main.cpp ${SRC_LIST} ${SRC_LIST_1} ${SRC_LIST_2}

# ----------------------------------------------------------------------------------------


# 指定生成可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out)  # 使用绝对路径最好
# 或者set(EXECUTABLE_OUTPUT_PATH "../out")     # 需要注意当前CMakeLists.txt和out相对路径关系, 此时必须是在同一个目录下
# EXECUTABLE_OUTPUT_PATH:目标二进制可执行文件存放的位置
# PROJECT_SOURCE_DIR:代表的工程的路径
# PROJECT_BINARY_DIR:代表编译的是编译的路径

# 设置编译时的选项，如O2优化，开启警告,使用的C++标准等
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
 
# 调试时使用该项
set(CMAKE_BUILD_TYPE Debug)
