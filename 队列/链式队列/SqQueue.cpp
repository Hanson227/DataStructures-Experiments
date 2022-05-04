#include <stdio.h>
#include <malloc.h>


typedef int QElemType;
typedef struct Qnode {
	QElemType data;
	struct Qnode* next;
}QNode, * QueuePtr;
typedef struct {
	QNode* front;	//����ָ��
	QNode* rear;	//��βָ�� 
}LinkQueue;

void InitQueue(LinkQueue*& Q)		//��ʼ������ 
{
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	Q->front = Q->rear = NULL;
}
void DestroyQueue(LinkQueue*& Q)	//���ٶ��� 
{
	QNode* p = Q->front, * q;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(Q);	//�ͷ�ͷ��� 
}
bool QueueEmpty(LinkQueue* Q)	//�ж϶ӿ� 
{
	if (Q->rear == NULL)
		return true;
	else
		return false;
}
bool EnQueue(LinkQueue*& Q, QElemType e)		//Ԫ����� 
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
bool DeQueue(LinkQueue*& Q, QElemType& e)	//���� 
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
bool GetHead(LinkQueue*& Q, QElemType& e)	///ȡ����Ԫ�� 
{
	if (Q->rear == NULL)
		return false;
	e = Q->front->data;
	return true;
}
