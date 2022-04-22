#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Stack {
    int capacity;  //栈的容积
    int top;  //栈顶位置
    char* array;  //数组，存放数据
} *STACK, stack;

STACK CreatStack(int num) {
    STACK s = (STACK)malloc(sizeof(stack));
    s->array =(char*)(malloc(num * sizeof(int)));   //动态申请数组

    s->capacity = num;
    s->top = -1; //栈顶位置为-1，即空
    return s;
}
//判断是否为空
int IsEmpty(STACK s) {
    return s->top == -1;
}

//入栈
void push(int x, STACK s) {
    if (s->top < s->capacity)  //栈未满
        s->array[++s->top] = x;
}
//获取栈顶元素
int top(STACK s) {
    if (!IsEmpty(s))
        return s->array[s->top];
    return 0;
}
//出栈
void pop(STACK s) {
    if (!IsEmpty(s))
        s->top--;
}
