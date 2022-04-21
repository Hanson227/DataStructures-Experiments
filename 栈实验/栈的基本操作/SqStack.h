#ifndef __SqStack_H__
#define __SqStack_H__

#define Stack_Init_Size 10 // ��ʼ��ջ����󳤶�
#define StackIncrement 10 // ��ջ���ռ䲻��ʱ����Ҫ���ӵĳ���
typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType* base; // ջ��ָ��
    ElemType* top; // ջ��ָ��
    int stack_size; // ջ����󳤶�
} SqStack;

Status InitStack(SqStack* S);// ��ʼ��ջ
Status EmptyStack(SqStack* S);// �ж�ջ�Ƿ�Ϊ�գ�ֻ��Ҫ�ж�ջ��ָ����ջ��ָ���Ƿ���ͬ����
Status LengthStack(SqStack* S);// ��ȡջ��ʵ�ʳ��ȣ�ջ����ȥջ��ָ�뼴Ϊջ�ĳ���
Status GetTopStack(SqStack* S, ElemType* e);// ��ȡջ����Ԫ�أ�����e�������ջ����Ԫ��
Status PushStack(SqStack* S, ElemType e);// ��ջ������e��Ҫ��ջ��Ԫ��
Status PopStack(SqStack* S, ElemType* e);// ��ջ������e������ų�ջ��Ԫ��
Status DestroyStack(SqStack* S);// ����ջ���ͷ�ջ�ռ䣬ջ��ջ��ָ����ΪNULL��������Ϊ0
Status StackTraverse(SqStack* S);// ����ջ�����δ�ӡÿ��Ԫ��
void menu();

#endif
