#include <stdio.h>
#include <string.h>
#include "SqStack.h"


int IsMatch(char c1, char c2) {
    switch (c1) 
    {
    case '(':
        if (c2 == '(')
        {
            return 1;
        }
        break;
        
    case '[':
        if(c2 == ']')
            return 1;
        break;
    case '{':
        if (c2 == '}')
        {
            return 1;
        }
        break;
    }
}

int Judge(char s[]) {
    int len = strlen(s);
    STACK stack = CreatStack(len);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' || !IsEmpty(stack))
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
    gets_s(s);
    if (Judge(s))
        printf("ƥ����\n");
    else
        printf("û��ƥ��.\n");

    return 0;
}