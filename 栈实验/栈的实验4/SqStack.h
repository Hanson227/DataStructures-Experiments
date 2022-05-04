#ifndef __SqStack_H__
#define __SqStack_H__


#define OK 1
#define NO -1 
#define MAXSIZE 20

typedef struct
{
	int data[MAXSIZE];
	int top[2];

}SqStack;

void InitStack(SqStack& S);//栈的初始化 
int Push(SqStack& S, int num, int a);//压栈 
int Pop(SqStack& S, int num, int b);//出栈 
void print(SqStack S);//打印栈

#endif
