#ifndef __SqStack_H__
#define __SqStack_H__

typedef struct Stack {
    int capacity;  //ջ���ݻ�
    int top;  //ջ��λ��
    int* array;  //���飬�������
} *STACK, stack;

STACK CreatStack(int num);
int IsEmpty(STACK s);
void push(int x, STACK s);
int top(STACK s);
void pop(STACK s);

#endif
