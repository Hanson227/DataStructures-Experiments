#ifndef __SqQueue_H__
#define __SqQueue_H__

typedef int QElemType;
typedef struct Qnode {
	QElemType data;
	struct Qnode* next;
}QNode, * QueuePtr;

typedef struct {
	QNode* front;	//����ָ��
	QNode* rear;	//��βָ�� 
}LinkQueue;

void InitQueue(LinkQueue*& Q);		//��ʼ������ 
void DestroyQueue(LinkQueue*& Q);	//���ٶ��� 
bool QueueEmpty(LinkQueue* Q);	//�ж϶ӿ� 
bool EnQueue(LinkQueue*& Q, QElemType e);		//Ԫ����� 
bool DeQueue(LinkQueue*& Q, QElemType& e);	//���� 
bool GetHead(LinkQueue*& Q, QElemType& e);	///ȡ����Ԫ�� 
#endif // !__SqQueue_H__

