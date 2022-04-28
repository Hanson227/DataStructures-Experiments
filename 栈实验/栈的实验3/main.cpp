#include "SqStack.h"
#include <stdio.h>
#include <Windows.h>

int Transform(STACK & S, int n)
{
	if (n == -1)
	{
		printf("�˳�����");
		system("pause");
		exit(0);
	}
	while (n)
	{
		push(n%2,S);
		n = n / 2;
	}
	printf("ת����Ķ����������ǣ�");
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
		printf("������Ҫת����ʮ��������(����-1�˳�)\n");
		scanf_s("%d",&n);
		Transform(S, n);
	}
}