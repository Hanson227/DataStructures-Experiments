#include <stdio.h>
#include <malloc.h>


typedef int QElemType;
typedef struct Qnode {
	QElemType data;
	struct Qnode* next;
}QNode, * QueuePtr;
typedef struct {
	QNode* front;	//队首指针
	QNode* rear;	//队尾指针 
}LinkQueue;

void InitQueue(LinkQueue*& Q)		//初始化队列 
{
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	Q->front = Q->rear = NULL;
}
void DestroyQueue(LinkQueue*& Q)	//销毁队列 
{
	QNode* p = Q->front, * q;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(Q);	//释放头结点 
}
bool QueueEmpty(LinkQueue* Q)	//判断队空 
{
	if (Q->rear == NULL)
		return true;
	else
		return false;
}
bool EnQueue(LinkQueue*& Q, QElemType e)		//元素入队 
{
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	if (Q->rear == NULL)
	{
		Q->front = Q->rear = p;
	}
	else
	{
		Q->rear->next = p;
		Q->rear = p;
	}
	return true;
}
bool DeQueue(LinkQueue*& Q, QElemType& e)	//出队 
{
	QNode* p;
	if (Q->rear == NULL)
	{
		return false;
	}
	p = Q->front;
	if (Q->front == Q->rear)
	{
		Q->front = Q->rear = NULL;
	}
	else
	{
		Q->front = p->next;
	}
	e = p->data;
	free(p);
	return true;
}
bool GetHead(LinkQueue*& Q, QElemType& e)	///取队首元素 
{
	if (Q->rear == NULL)
		return false;
	e = Q->front->data;
	return true;
}
