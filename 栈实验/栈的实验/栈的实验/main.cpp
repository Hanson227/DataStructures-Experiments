#include <stdio.h>
#include <string.h>
#include "SqStack.h"


int IsMatch(char c1, char c2) {
    switch (c1) 
    {
    case '(':
        if (c2 == ')')
        {
            return 1;
        }
        else
        {
            return 0;
        }
        break;
        
    case '[':
        if(c2 == ']')
            return 1;
        else
        {
            return 0;
        }
        break;
    case '{':
        if (c2 == '}')
        {
            return 1;
        }
        else
        {
            return 0;
        }
        break;
    default:return 0;
    }
}

int Judge(char s[]) {
    int len = strlen(s);
    STACK stack = CreatStack(len);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' || IsEmpty(stack))
            push(s[i], stack);  //Ϊ��Ԫ�ػ�ջ�գ���ջ
        else if (IsMatch(s[i-1], s[i]))
            pop(stack);  //��ջ��ƥ����ջ��Ԫ�س�ջ
        else
            push(s[i], stack); //��ջ����ƥ������ջ
    }
    if (IsEmpty(stack))
    {
        return 1;  //ջΪ�գ�˵����ȫƥ��
    }   
    return 0;  //ջ������˵�����޷�ƥ��֮��
}

int main() {
    char s[100];
    while (scanf_s("%s",s,6) != EOF) 
    {
        if (Judge(s)== 0) {
            printf("no\n");
        }
        else {
            printf("yes\n");
        }
    }

    return 0;
}