#include <stdio.h>
#include "SqQueue.h"

int main(void)
{
	LinkQueue* Q;
	QElemType e;

	InitQueue(Q);
	printf("�����������Ԫ��(����-1ʱֹͣ):\n");
	while (e != -1)
	{
		EnQueue(Q, e);
		scanf_s("%d", &e);
	}
	GetHead(Q, e);
	printf("��ǰ����Ϊ%d\n", e);
	printf("���γ�����\n");
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, e);
		printf("������Ԫ��Ϊ%d\n", e);
		if (!QueueEmpty(Q))
		{
			GetHead(Q, e);
			printf("��ǰ����Ϊ%d\n", e);
		}
	}
	printf("��ǰ����Ϊ�գ�");
	DestroyQueue(Q);
}
