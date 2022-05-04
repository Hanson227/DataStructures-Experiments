#include "SqQueue.h"
#include <stdio.h>

int main(void)
{
	SqQueue* Q;
	static int e, i;
	InitQueue(Q);
	printf("输入入队元素(输入-1时停止)\n");
	while ( e!= -1 && !QueueFull(Q))
	{
		scanf_s("%d", &e);
		if (e == -1)
		{
			break;
		}
		EnQueue(Q, e);
	}
	if (QueueFull(Q))
		printf("当前队列以满！\n");
	GetHead(Q, e);
	printf("当前队首为%d\n", e);
	printf("依次出队列\n");
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, e);
		printf("出队列的元素为%d\n", e);
		if (!QueueEmpty(Q))
		{
			GetHead(Q, i);
			printf("当前队首为%d\n", i);
		}
	}
	printf("当前队列为空");
	DestroyQueue(Q);
}
