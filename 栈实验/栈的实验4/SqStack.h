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

void InitStack(SqStack& S);//ջ�ĳ�ʼ�� 
int Push(SqStack& S, int num, int a);//ѹջ 
int Pop(SqStack& S, int num, int b);//��ջ 
void print(SqStack S);//��ӡջ

#endif
