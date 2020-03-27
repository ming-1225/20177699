#include<iostream>
#include<stdlib.h>
#pragma warning(disable:4996)
using namespace std;
#ifndef SUDOKU_H_
#define SUDOKU_H_


/*数独二维数组*/
extern int shudu[9][9], s, t, block, block_line, block_column;

/*声明Check函数，用以检查所填的数是否合法*/
bool Check(int num, int now_line, int now_column);

/*输入函数*/
void Input();

/*工作函数*/
bool Work(int now_line, int now_column);

/*输出函数*/
void Output();

#endif

