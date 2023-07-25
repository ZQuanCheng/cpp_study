#ifndef BOOK_STRUCT_H    // 防止头文件的重复包含和编译
#define BOOK_STRUCT_H


#include <iostream>
using namespace std; 



// 声明一个结构体类型 Books 
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
}; 
/*
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book00, book11;  //book00, book11 只是变量，不是别名
// 这里不能紧跟定义对象。因为是单独的头文件，不进行具体的对象声明。
// 若将结构体定义放在单独的.h头文件，而不是main.cpp中，就不能在.h头文件中定义具体的结构体对象。若定义了一些对象，则编译会报错 multiple definition of 'book00' 'book11'
// 因为.c源文件和main.cpp同时包含.h头文件，导致具体定义的对象重复定义，编译器报错。
*/


void printBook_1( struct Books book );
void printBook_2( Books book );              // 前面不加struct关键词，g++编译器也可以识别到结构体类型

void printBook_ptr_1( struct Books *book ); 
void printBook_ptr_2( Books *book );    
 

// 可以使用typedef起别名
typedef struct Papers
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   paper_id;
}paper, papers;  //paper, papers 是结构体类型，即spaper, papers都是Papers的别名，而不是声明结构体的对象。

void printPaper_1( struct Papers paper );
void printPaper_2( Papers paper );
// void printPaper_3( struct paper *paper );  // 如果typedef起了别名，那么别名前不能加struct关键词，否则g++编译器会报错
void printPaper_3( paper paper );   
// void printPaper_3( struct papers *paper );  // 如果typedef起了别名，那么别名前不能加struct关键词，否则g++编译器会报错
void printPaper_4( papers paper ); 


void printPaper_ptr_1( struct Papers *paper );
void printPaper_ptr_2( Papers *paper );
// void printPaper_3( struct paper *paper );  // 如果typedef起了别名，那么别名之前不能加struct关键词，否则g++编译器会报错
void printPaper_ptr_3( paper *paper );   
// void printPaper_4( struct papers *paper );  // 如果typedef起了别名，那么别名之前不能加struct关键词，否则g++编译器会报错
void printPaper_ptr_4( papers *paper ); 


// 综上，
// 定义结构体时，必须使用struct关键词。
// 但是对于后续的使用，无论是作为函数参数，还是声明对象等，都不需要用struct关键词。 
// 特别注意，如果使用typedef给的别名，一定不要在别名前用struct关键词。否则g++编译器会报错



#endif