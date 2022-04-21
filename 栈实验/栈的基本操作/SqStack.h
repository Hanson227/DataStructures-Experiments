#ifndef __SqStack_H__
#define __SqStack_H__

#define Stack_Init_Size 10 // 初始化栈的最大长度
#define StackIncrement 10 // 若栈最大空间不够时，需要增加的长度
typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType* base; // 栈底指针
    ElemType* top; // 栈顶指针
    int stack_size; // 栈的最大长度
} SqStack;

Status InitStack(SqStack* S);// 初始化栈
Status EmptyStack(SqStack* S);// 判断栈是否为空，只需要判断栈顶指针与栈底指针是否相同即可
Status LengthStack(SqStack* S);// 获取栈的实际长度，栈顶减去栈底指针即为栈的长度
Status GetTopStack(SqStack* S, ElemType* e);// 获取栈顶的元素，参数e用来存放栈顶的元素
Status PushStack(SqStack* S, ElemType e);// 进栈，参数e是要进栈的元素
Status PopStack(SqStack* S, ElemType* e);// 出栈，参数e用来存放出栈的元素
Status DestroyStack(SqStack* S);// 销毁栈，释放栈空间，栈顶栈底指针置为NULL，长度置为0
Status StackTraverse(SqStack* S);// 遍历栈，依次打印每个元素
void menu();

#endif
