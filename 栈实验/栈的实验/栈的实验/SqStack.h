#ifndef __SqStack_H__
#define __SqStack_H__

typedef struct Stack {
    int capacity;  //栈的容积
    int top;  //栈顶位置
    int* array;  //数组，存放数据
} *STACK, stack;

STACK CreatStack(int num);
int IsEmpty(STACK s);
void push(int x, STACK s);
int top(STACK s);
void pop(STACK s);

#endif
