#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100

typedef int QElemType;

typedef struct {
	int data[MAXSIZE];
	int front;		//头指针 
	int rear;		//尾指针 
}SqQueue;

void InitQueue(SqQueue*& Q)	//初始化 
{
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	Q->front = Q->rear = NULL;
}

bool QueueEmpty(SqQueue* Q)	//判断队空 
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

bool QueueFull(SqQueue* Q)	//判断队满 
{
	if (Q->front == (Q->rear + 1) % MAXSIZE)
		return true;
	else
		return false;
}

bool EnQueue(SqQueue*& Q, QElemType e) 	//进队列 
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return false;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return true;
}

bool DeQueue(SqQueue*& Q, QElemType& e)	//出队列 
{
	if (Q->front == Q->rear)
		return false;
	e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return true;
}
bool GetHead(SqQueue* Q, QElemType& e)	//取队首元素 
{
	if (Q->front == Q->rear)
	{
		return false;
	}
	e = Q->data[Q->front];
	return true;
}
void DestroyQueue(SqQueue*& Q)	//释放空间 
{
	free(Q);
}
