#include <stdio.h>
#include "SqStack.h"
#include <Windows.h>


int main()
{
	SqStack S;
	InitStack(S);
	Push(S, 0, 1);
	Push(S, 0, 2);
	Push(S, 0, 3);
	Push(S, 1, 4);
	Push(S, 1, 5);
	Push(S, 1, 6);
	print(S);
	printf("��ӡǰջ\n");
	print(S);
	printf("��ӡ��ջ\n");
	print(S);
	return 0;
}

