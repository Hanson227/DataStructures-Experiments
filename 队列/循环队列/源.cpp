#include "SqQueue.h"
#include <stdio.h>

int main(void)
{
	SqQueue* Q;
	static int e, i;
	InitQueue(Q);
	printf("�������Ԫ��(����-1ʱֹͣ)\n");
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
		printf("��ǰ����������\n");
	GetHead(Q, e);
	printf("��ǰ����Ϊ%d\n", e);
	printf("���γ�����\n");
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, e);
		printf("�����е�Ԫ��Ϊ%d\n", e);
		if (!QueueEmpty(Q))
		{
			GetHead(Q, i);
			printf("��ǰ����Ϊ%d\n", i);
		}
	}
	printf("��ǰ����Ϊ��");
	DestroyQueue(Q);
}
