#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100

typedef int QElemType;

typedef struct {
	int data[MAXSIZE];
	int front;		//ͷָ�� 
	int rear;		//βָ�� 
}SqQueue;

void InitQueue(SqQueue*& Q)	//��ʼ�� 
{
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	Q->front = Q->rear = NULL;
}

bool QueueEmpty(SqQueue* Q)	//�ж϶ӿ� 
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

bool QueueFull(SqQueue* Q)	//�ж϶��� 
{
	if (Q->front == (Q->rear + 1) % MAXSIZE)
		return true;
	else
		return false;
}

bool EnQueue(SqQueue*& Q, QElemType e) 	//������ 
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return false;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return true;
}

bool DeQueue(SqQueue*& Q, QElemType& e)	//������ 
{
	if (Q->front == Q->rear)
		return false;
	e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return true;
}
bool GetHead(SqQueue* Q, QElemType& e)	//ȡ����Ԫ�� 
{
	if (Q->front == Q->rear)
	{
		return false;
	}
	e = Q->data[Q->front];
	return true;
}
void DestroyQueue(SqQueue*& Q)	//�ͷſռ� 
{
	free(Q);
}
