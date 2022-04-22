#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Stack {
    int capacity;  //ջ���ݻ�
    int top;  //ջ��λ��
    char* array;  //���飬�������
} *STACK, stack;

STACK CreatStack(int num) {
    STACK s = (STACK)malloc(sizeof(stack));
    s->array =(char*)(malloc(num * sizeof(int)));   //��̬��������

    s->capacity = num;
    s->top = -1; //ջ��λ��Ϊ-1������
    return s;
}

int IsEmpty(STACK s) {
    return s->top == -1;
}

void push(int x, STACK s) {
    if (s->top < s->capacity)  //ջδ��
        s->array[++s->top] = x;
}

int top(STACK s) {
    if (!IsEmpty(s))
        return s->array[s->top];
    return 0;
}

void pop(STACK s) {
    if (!IsEmpty(s))
        s->top--;
}
