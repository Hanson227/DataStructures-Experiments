#ifndef __SqQueue_H__
#define __SqQueue_H__

typedef int QElemType;
typedef struct Qnode {
	QElemType data;
	struct Qnode* next;
}QNode, * QueuePtr;

typedef struct {
	QNode* front;	//队首指针
	QNode* rear;	//队尾指针 
}LinkQueue;

void InitQueue(LinkQueue*& Q);		//初始化队列 
void DestroyQueue(LinkQueue*& Q);	//销毁队列 
bool QueueEmpty(LinkQueue* Q);	//判断队空 
bool EnQueue(LinkQueue*& Q, QElemType e);		//元素入队 
bool DeQueue(LinkQueue*& Q, QElemType& e);	//出队 
bool GetHead(LinkQueue*& Q, QElemType& e);	///取队首元素 
#endif // !__SqQueue_H__

