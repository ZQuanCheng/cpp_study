#include "book_struct.h"


void printBook_1( struct Books book )
{
   cout << "书标题 : " << book.title <<endl;
   cout << "书作者 : " << book.author <<endl;
   cout << "书类目 : " << book.subject <<endl;
   cout << "书 ID : " << book.book_id <<endl;
}

void printBook_2( Books book )
{
   cout << "书标题 : " << book.title <<endl;
   cout << "书作者 : " << book.author <<endl;
   cout << "书类目 : " << book.subject <<endl;
   cout << "书 ID : " << book.book_id <<endl;
}

void printBook_ptr_1( struct Books *book )
{
   cout << "书标题 : " << book->title <<endl;
   cout << "书作者 : " << book->author <<endl;
   cout << "书类目 : " << book->subject <<endl;
   cout << "书 ID : " << book->book_id <<endl;
}

void printBook_ptr_2( Books *book )  // 前面不加struct关键词，g++编译器也可以识别到结构体类型
{
   cout << "书标题 : " << book->title <<endl;
   cout << "书作者 : " << book->author <<endl;
   cout << "书类目 : " << book->subject <<endl;
   cout << "书 ID : " << book->book_id <<endl;
}




void printPaper_1( struct Papers paper )
{
   cout << "论文标题 : " << paper.title <<endl;
   cout << "论文作者 : " << paper.author <<endl;
   cout << "论文类目 : " << paper.subject <<endl;
   cout << "论文 ID : " << paper.paper_id <<endl;

}
void printPaper_2( Papers paper )
{
   cout << "论文标题 : " << paper.title <<endl;
   cout << "论文作者 : " << paper.author <<endl;
   cout << "论文类目 : " << paper.subject <<endl;
   cout << "论文 ID : " << paper.paper_id <<endl;

}
void printPaper_3( paper paper )
{
   cout << "论文标题 : " << paper.title <<endl;
   cout << "论文作者 : " << paper.author <<endl;
   cout << "论文类目 : " << paper.subject <<endl;
   cout << "论文 ID : " << paper.paper_id <<endl;

}
void printPaper_4( papers paper )
{
   cout << "论文标题 : " << paper.title <<endl;
   cout << "论文作者 : " << paper.author <<endl;
   cout << "论文类目 : " << paper.subject <<endl;
   cout << "论文 ID : " << paper.paper_id <<endl;

}




void printPaper_ptr_1( struct Papers *paper )
{
   cout << "论文标题 : " << paper->title <<endl;
   cout << "论文作者 : " << paper->author <<endl;
   cout << "论文类目 : " << paper->subject <<endl;
   cout << "论文 ID : " << paper->paper_id <<endl;

}
void printPaper_ptr_2( Papers *paper )
{
   cout << "论文标题 : " << paper->title <<endl;
   cout << "论文作者 : " << paper->author <<endl;
   cout << "论文类目 : " << paper->subject <<endl;
   cout << "论文 ID : " << paper->paper_id <<endl;

}
void printPaper_ptr_3( paper *paper )
{
   cout << "论文标题 : " << paper->title <<endl;
   cout << "论文作者 : " << paper->author <<endl;
   cout << "论文类目 : " << paper->subject <<endl;
   cout << "论文 ID : " << paper->paper_id <<endl;

}
void printPaper_ptr_4( papers *paper )
{
   cout << "论文标题 : " << paper->title <<endl;
   cout << "论文作者 : " << paper->author <<endl;
   cout << "论文类目 : " << paper->subject <<endl;
   cout << "论文 ID : " << paper->paper_id <<endl;

}