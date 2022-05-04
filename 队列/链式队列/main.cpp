#include <stdio.h>
#include "SqQueue.h"

int main(void)
{
	LinkQueue* Q;
	QElemType e;

	InitQueue(Q);
	printf("依次输入入队元素(输入-1时停止):\n");
	while (e != -1)
	{
		EnQueue(Q, e);
		scanf_s("%d", &e);
	}
	GetHead(Q, e);
	printf("当前队首为%d\n", e);
	printf("依次出队列\n");
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, e);
		printf("出队列元素为%d\n", e);
		if (!QueueEmpty(Q))
		{
			GetHead(Q, e);
			printf("当前队首为%d\n", e);
		}
	}
	printf("当前队列为空！");
	DestroyQueue(Q);
}
