#include<stdio.h> 
#include<stdlib.h>

#define OK 1
#define NO -1 
#define MAXSIZE 20

typedef struct
{
	int data[MAXSIZE];
	int top[2];

}SqStack;

void InitStack(SqStack& S)//栈的初始化 
{
	S.top[0] = -1;
	S.top[1] = MAXSIZE;
}

int Push(SqStack& S, int num, int a)//压栈 
{
	if (S.top[0] + 1 < S.top[1])
	{
		if (num == 0)
		{
			++(S.top[0]);
			S.data[S.top[0]] = a;
			return OK;
		}
		else if (num == 1)
		{
			--(S.top[1]);
			S.data[S.top[1]] = a;
			return OK;
		}
		else
		{
			return NO;
		}
	}
	else
	{
		return 0;
	}

}

int Pop(SqStack& S, int num, int b)//出栈 
{
	if (num == 0)
	{
		if (S.top[0] != -1)
		{
			b = S.data[S.top[0]];
			--(S.top[0]);
			return OK;
		}
		else
		{
			return 0;
		}
	}
	else if (num == 1)
	{
		if (S.top[1] != MAXSIZE)
		{
			b = S.data[S.top[1]];
			++(S.top[1]);
			return OK;
		}
		else
		{
			return 0;
		}
	}


}

void print(SqStack S)//打印栈
{
	for (int i = 0; i < S.top[0]; i++)
	{
		printf("%2d", S.data[i]);
		printf("\n");
	}
	for (int i = S.top[1]; i <= MAXSIZE; i++)
	{
		printf("%2d", S.data[i]);
	}
	printf("\n");
}
