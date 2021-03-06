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
            push(s[i], stack);  //为左元素或栈空，入栈
        else if (IsMatch(s[i-1], s[i]))
            pop(stack);  //与栈顶匹配则栈顶元素出栈
        else
            push(s[i], stack); //与栈顶不匹配则入栈
    }
    if (IsEmpty(stack))
    {
        return 1;  //栈为空，说明完全匹配
    }   
    return 0;  //栈不空则说明有无法匹配之处
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