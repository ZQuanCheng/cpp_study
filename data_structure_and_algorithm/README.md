# data_structure_and_algorithm

代码随想录
https://programmercarl.com/

Linux---C++  数据结构与算法

## 功能介绍


## 编译、运行

```sh
# 赋予脚本所有者执行权限，允许该用户执行该脚本
# r、w、x 分别表示读、写、执行权限 
$ chmod +x build.sh 
# 执行脚本
$ ./build
``` 


## 注意
如果你在改变了文件结构, 例如添加了一个新的.c文件，makefile构建系统是不能感知这个文件的，所以必须手动重新生成cmake工程.先 $ cmake .. 后 $ make 才能生成可执行文件

如果不改变文件结构,即不新增或删减文件,只是修改内容,文件结构不变,则只需要重复 $ make 命令 即可生成可执行文件


## main.cpp包含内容

* 代码随想录--------算法性能分析 
  * 算法为什么会超时。              
    *  不同时间复杂度的算法，运行多少次需要1s。一般超过1s，leetcode判定超时

  * 递归算法的时间复杂度





## 文件结构

## 简介
* ./include/：（存放.h头文件）；
* ./src/：（存放.cpp源文件）
* ./bulid/：（存放Cmake产生的中间文件）
* ./out/：（存放输出的可执行文件）
* ./main.cpp 
* ./CMakeLists.txt
* ./README.md 
* ./note/： (存放笔记)
  * ./images 文件夹： （存放图片，用于note.md）
  * ./markdown_demo.md ： （markdown基本语法总结）
  * ./note.md：  （数据结构与算法（笔记））

## 详细介绍

### ./include/
* Algorithm_Performance_Analysis/
  * compare_time_complexity.h
    1. 三个函数，实现不同时间复杂度的循环，包括O(n)、O(n^2)、O(nlog n)。 
    2. 用于main.cpp中试验每种时间复杂度，运行多少次需要1s。
    3. 一般超过1s，leetcode判定超时。
  * recursion_algorithm.h 
    *  讨论递归算法的时间复杂度（不同实现方式，时间复杂度不同） 
  * fibonacci.h
    *  递归求斐波那契数列的性能分析

* Array/
    

### ./src/
* Algorithm_Performance_Analysis/
  * compare_time_complexity.cpp 
  * recursion_algorithm.h
  * fibonacci.h<

* Array/




