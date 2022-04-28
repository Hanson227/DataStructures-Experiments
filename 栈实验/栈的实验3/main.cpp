#include "SqStack.h"
#include <stdio.h>
#include <Windows.h>

int Transform(STACK & S, int n)
{
	if (n == -1)
	{
		printf("退出程序！");
		system("pause");
		exit(0);
	}
	while (n)
	{
		push(n%2,S);
		n = n / 2;
	}
	printf("转换后的二进制数字是：");
	while (!IsEmpty(S))
	{
		pop(S);
	}
	printf("\n\n");
	return 0;
}

int main()
{
	int n;
	STACK S=CreatStack(10);
	while (1)
	{
		printf("请输入要转换的十进制数字(输入-1退出)\n");
		scanf_s("%d",&n);
		Transform(S, n);
	}
}