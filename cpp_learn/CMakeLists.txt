# 最小版本，可以通过cmake --version查看
cmake_minimum_required(VERSION 3.5.1)
 
# 项目名称，建议大写
project(cpp_learn)
 

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
    include                                   # 或者${CMAKE_CURRENT_SOURCE_DIR}/include
    include/class_inherit_depart              # 或者${CMAKE_CURRENT_SOURCE_DIR}/include/Algorithm_Performance_Analysis
    include/template                          # 或者${CMAKE_CURRENT_SOURCE_DIR}/include/template

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
# 1、把./src目录下的所有源文件都添加到SRC_LIST源列表变量里面去
#    aux_source_directory(./src SRC_LIST)         
# 
#    把./src/class_inherit_depart目录下的所有源文件都添加到SRC_LIST_1源列表变量里面去
#    aux_source_directory(./src/class_inherit_depart SRC_LIST_1)     
# 
#    把./src/template目录下的所有源文件都添加到SRC_LIST_2源列表变量里面去
#    aux_source_directory(./src/template SRC_LIST_2)  
# 
# 2、生成可执行文件命令，第一个参数是生成可执行文件的名称main，后面的参数是源文件/源文件列表 main.cpp ${SRC_LIST} ${SRC_LIST_1} ${SRC_LIST_2}
#    add_executable(main main.cpp ${SRC_LIST} ${SRC_LIST_1} ${SRC_LIST_2}) 


# 方法四：在Bosch学到的
add_library(book_struct_lib               ./src/book_struct.cpp)
add_library(box_class_lib                 ./src/box_class.cpp)
add_library(class_inherit_lib             ./src/class_inherit.cpp)
add_library(overload_lib                  ./src/overload.cpp)
add_library(swap_lib                      ./src/swap.cpp)

add_library(ab_class_lib                  ./src/class_inherit_depart/ab_class.cpp)
add_library(paintcost_class_lib           ./src/class_inherit_depart/paintcost_class.cpp)
add_library(print_by_base_pointer_lib     ./src/class_inherit_depart/print_by_base_pointer.cpp)
add_library(rectangle_class_lib           ./src/class_inherit_depart/rectangle_class.cpp)
add_library(shape_class_lib               ./src/class_inherit_depart/shape_class.cpp)
add_library(triangle_class_lib            ./src/class_inherit_depart/triangle_class.cpp)

add_library(template_class_array_lib      ./src/template/template_class_array.cpp)
add_library(template_class_stack_lib      ./src/template/template_class_stack.cpp)
add_library(template_func_max_lib         ./src/template/template_func_max.cpp)


add_executable(  
  Main
  main.cpp
)


target_link_libraries(
  # 可执行文件    
  Main
  # 库
  book_struct_lib               
  box_class_lib                 
  class_inherit_lib                     
  overload_lib                  
  swap_lib                      

  ab_class_lib                  
  paintcost_class_lib           
  print_by_base_pointer_lib     
  rectangle_class_lib           
  shape_class_lib               
  triangle_class_lib            

  template_class_array_lib      
  template_class_stack_lib      
  template_func_max_lib         
)


# ---------------------------------------------------------------------------------------------------------------

