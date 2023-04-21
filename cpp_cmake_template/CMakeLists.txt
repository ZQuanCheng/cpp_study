# 最小版本，可以通过cmake --version查看
cmake_minimum_required(VERSION 3.5.1)
 
# 项目名称，建议大写
project(SWAP)
 
# 搜索自定义的头文件目录，可以使用绝对路径 ${CMAKE_SOURCE_DIR}/include
include_directories(${PROJECT_SOURCE_DIR}/include)  # 使用绝对路径最好  # PROJECT_SOURCE_DIR:代表的工程的路径 
# 或者include_directories(./include)  # 需要注意当前CMakeLists.txt和include相对路径关系, 此时必须是在同一个目录下
# 或者include_directories(include)    # 需要注意当前CMakeLists.txt和include相对路径关系, 此时必须是在同一个目录下

# -------------------生成可执行文件------------------------
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
aux_source_directory(./src SRC_LIST)
add_executable(main main.cpp ${SRC_LIST}) 
# 如果main.cpp在src中，则add_executable(main ${SRC_LIST})
# --------------------------------------------------------

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
