# 最小版本，可以通过cmake --version查看
cmake_minimum_required(VERSION 3.5.1)
 
# 项目名称，建议大写
project(cpp_data_type)
 

# -------------------------------------------编译选项------------------------------------------------

# 支持c++11
# 第一种方式:(根据camke版本调整)
set(CMAKE_CXX_STANDARD 11)  # CMake 3.1或者更高版本支持使用这个
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # CMake更低版本使用
# 第二种方式:
# add_compile_options(-std=c++11)


# 指定生成可执行文件的输出目录
# EXECUTABLE_OUTPUT_PATH:目标二进制可执行文件存放的位置
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)  
# ${CMAKE_CURRENT_SOURCE_DIR}最好，如果是大项目有多层CMakeLists.txt，${PROJECT_SOURCE_DIR}可能会出问题

# 或者set(EXECUTABLE_OUTPUT_PATH "../out")     # 需要注意当前CMakeLists.txt和out相对路径关系, 此时必须是在同一个目录下


# 设置编译时的选项，如O2优化，开启警告,使用的C++标准等
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")  # -Wall选项告诉编译器 编译后显示所有警告。
 
# 调试时使用该项
set(CMAKE_BUILD_TYPE Debug)


# -------------------------------------------CMake预定义的内建变量------------------------------------------------

# CMAKE_CURRENT_SOURCE_DIR:当前正在处理的CMakeLists.txt路径 
# CMAKE_SOURCE_DIR： 最外层CMakeLists.txt所在目录
# PROJECT_SOURCE_DIR:代表的工程路径，是不是和CMAKE_SOURCE_DIR相同？
# PROJECT_BINARY_DIR:代表编译的是编译路径

# 编译时打印以下信息
message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
message("CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR})
message("PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})
message("PROJECT_BINARY_DIR: " ${PROJECT_BINARY_DIR})
message("EXECUTABLE_OUTPUT_PATH: " ${EXECUTABLE_OUTPUT_PATH})

if (${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    message(FATAL_ERROR "Please into another dir to build!")
endif()




# -------------------------------------------添加头文件路径------------------------------------------------

# 搜索自定义的头文件目录
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)  
# ${CMAKE_CURRENT_SOURCE_DIR}当前CMakeLists.txt最好，如果是大项目有多层CMakeLists.txt，${CMAKE_SOURCE_DIR}可能会出问题

# 或者include_directories(./include)  # 需要注意当前CMakeLists.txt和include相对路径关系, 此时必须是在同一个目录下
# 或者include_directories(include)    # 需要注意当前CMakeLists.txt和include相对路径关系, 此时必须是在同一个目录下


include_directories(
    # include   # 或者${CMAKE_CURRENT_SOURCE_DIR}/include

    # 若想要包含当前CMakeLists.txt的上级目录，需要下面这样
    # ${CMAKE_CURRENT_SOURCE_DIR}/../../cpp_learn/include
)


# 添加了头文件路径/include,就可以#include "swap.h" 而不需要 #include "include/swap.h"


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
# aux_source_directory(./src SRC_LIST)
# add_executable(main main.cpp ${SRC_LIST}) 
# 如果main.cpp在src中，则add_executable(main ${SRC_LIST})


# 方法四：在Bosch学到的
# add_library(swap_lib ./src/swap.cpp)

add_executable(
  Main
  main.cpp
)

# target_link_libraries(
#   # 可执行文件
#   Main
#   # 库
#   swap_lib
# )

# ---------------------------------------------------------------------------------------------------------------

