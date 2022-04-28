#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Stack {
    int capacity;  //ջ���ݻ�
    int top;  //ջ��λ��
    int* array;  //���飬�������
} *STACK, stack;

STACK CreatStack(int num) {
    STACK s = (STACK)malloc(sizeof(stack));
    s->array =(int*)(malloc(num * sizeof(int)));   //��̬��������

    s->capacity = num;
    s->top = -1; //ջ��λ��Ϊ-1������
    return s;
}
//�ж��Ƿ�Ϊ��
int IsEmpty(STACK s) {
    return s->top == -1;
}

//��ջ
void push(int x, STACK s) {
    if (s->top < s->capacity)  //ջδ��
        s->array[++s->top] = x;
}
//��ȡջ��Ԫ��
int top(STACK s) {
    if (!IsEmpty(s))
        return s->array[s->top];
    return 0;
}
//��ջ
void pop(STACK s) {
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d", s->array[i]);
        s->top--;
    }
}
