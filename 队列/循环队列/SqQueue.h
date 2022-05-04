#ifndef __SqQueuE_H__
#define __SqQueue_H__

#define MAXSIZE 100

typedef int QElemType;

typedef struct {
	int data[MAXSIZE];
	int front;		//Õ∑÷∏’Î 
	int rear;		//Œ≤÷∏’Î 
}SqQueue;

void InitQueue(SqQueue*& Q);
bool QueueEmpty(SqQueue* Q);
bool QueueFull(SqQueue* Q);
bool EnQueue(SqQueue*& Q, QElemType e);
bool DeQueue(SqQueue*& Q, QElemType& e);
bool GetHead(SqQueue* Q, QElemType& e);	 
void DestroyQueue(SqQueue*& Q);	
#endif
