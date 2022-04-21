#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define Stack_Init_Size 10 // ��ʼ��ջ����󳤶�
#define StackIncrement 10 // ��ջ���ռ䲻��ʱ����Ҫ���ӵĳ���
typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType* base; // ջ��ָ��
    ElemType* top; // ջ��ָ��
    int stack_size; // ջ����󳤶�
} SqStack;

// ��ʼ��ջ
Status InitStack(SqStack* S) {
    // �����ʼ�ռ�
    S->base = (ElemType*)malloc(Stack_Init_Size * sizeof(ElemType));
    if (!S->base) {
        exit(0);
    }
    S->top = S->base; /// ջ����ջ����ͬ
    S->stack_size = Stack_Init_Size; // ջ����󳤶ȵ��ڳ�ʼ����
    return 1;
}

// �ж�ջ�Ƿ�Ϊ�գ�ֻ��Ҫ�ж�ջ��ָ����ջ��ָ���Ƿ���ͬ����
Status EmptyStack(SqStack* S) {
    return S->base == S->top;
}

// ��ȡջ��ʵ�ʳ��ȣ�ջ����ȥջ��ָ�뼴Ϊջ�ĳ���
Status LengthStack(SqStack* S) {
    if (S->top == S->base) {
        return 0;
    }
    return (Status)(S->top - S->base);
}

// ��ȡջ����Ԫ�أ�����e�������ջ����Ԫ��
Status GetTopStack(SqStack* S, ElemType* e) {
    if (S->top == S->base) {
        return 0;
    }
    *e = *(S->top - 1);
    return 1;
}

// ��ջ������e��Ҫ��ջ��Ԫ��
Status PushStack(SqStack* S, ElemType e) {
    // ��ջ����󳤶Ȳ��ṻ��ʱ�����¿��٣����󳤶�
    if (S->top - S->base >= S->stack_size) {
        S->base = (ElemType*)realloc(S->base, (S->stack_size + StackIncrement) * sizeof(ElemType));
        if (!S->base) {
            return 0;
        }
        // ջ��ָ��Ϊջ��ָ�����ջ֮ǰ����󳤶�
        S->top = S->base + S->stack_size;
        // ջ��ǰ����󳤶ȵ���ջ֮ǰ����󳤶������ӵĳ���֮��
        S->stack_size += StackIncrement;
    }
    *S->top++ = e; // �ȸ�ֵ����ջ��ָ������
    return 1;
}

// ��ջ������e������ų�ջ��Ԫ��
Status PopStack(SqStack* S, ElemType* e) {
    if (S->base == S->top) {
        return 0;
    }
    *e = *--S->top; // ջ��ָ�������ƣ���ֵ
    return 1;
}

// ����ջ���ͷ�ջ�ռ䣬ջ��ջ��ָ����ΪNULL��������Ϊ0
Status DestroyStack(SqStack* S) {
    free(S->base);
    S->base = S->top = NULL;
    S->stack_size = 0;
    return 1;
}

// ����ջ�����δ�ӡÿ��Ԫ��
Status StackTraverse(SqStack* S) {
    ElemType* p;

    if (S->top == S->base) {
        printf("Stack is NULL.\n");
        return 0;
    }
    p = S->top;
    // ��ջ���������±���
    while (p > S->base) {
        p--;
        printf("%d ", *p);
    }
    printf("\n");
    return 1;
}

void menu()//���˵�
{
    printf("\n********************************\n\n");
    puts("1. ��ʼ��ջ");
    puts("2. ¼����Ϣ");
    puts("3. �ж�ջ�Ƿ�Ϊ��");
    puts("4. ��ȡջ��ʵ�ʳ���");
    puts("5. ��ȡջ��Ԫ��");
    puts("6. ��ջ�����Ԫ��");
    puts("7. ��ɾ��ջ��Ԫ��");
    puts("8. ����ջ");
    puts("9. ���ջ������Ԫ��");
    puts("0. �˳�");
    printf("\n********************************\n\n");
}

