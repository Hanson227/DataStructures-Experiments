#include <stdio.h>
#include <string.h>
#include "SqStack.h"


int IsMatch(char c1, char c2) {
    switch (c1) {
    case '(':
        return c2 == ')';
    case '[':
        return c2 == ']';
    case '{':
        return c2 == '}';
    }
}

int Judge(char s[]) {
    int len = strlen(s);
    STACK stack = CreatStack(len);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' || !IsEmpty(stack))
            push(s[i], stack);  //为左元素或栈空，入栈
        else if (IsMatch(top(stack), s[i]))
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
    gets_s(s);
    if (Judge(s))
        printf("匹配了\n");
    else
        printf("没有匹配.\n");

    return 0;
}