#include "SqStack.h"
#include <stdio.h>
#include <Windows.h>


void main() 
{
	SqStack *S,q;
	S = &q;
	int n,e,choose;
	while (1)
	{
		menu();
		puts("请输入功能选项");
		scanf_s("%d", &choose);
		if (choose == 0) break;
		if (choose < 0 || choose>9)
		{
			puts("对不起，输入错误，请重新输入！");
			continue;
		}
		switch (choose)
		{
		case 1:
			if (InitStack(S))
				printf("成功建立栈\n\n");
			else
				printf("栈建立失败\n\n");
			break;
		case 2:
			printf("请输入栈的高度(小于100)：");
			scanf_s("%d", &n);
			for (int i = 1; i <= n; i++)
			{
				printf("请输入第%d个信息:", i);
				scanf_s("%d", &e);
				PushStack(S, e);
			}
			break;
		case 3:
			if (EmptyStack(S)) {
				printf("Yes!\n");
			}
			else {
				printf("No!\n");
			}
			break;
		case 4:
			printf("栈的长度为 %d.\n", LengthStack(S));
			break;
		case 5:
			printf("栈顶的元素是%d.\n", GetTopStack(S, &e));
		case 6:
			printf("请输入你想要插入的信息：");
			scanf_s("%d", &e);
			if (PushStack(S, e))
			{
				printf("插入成功\n\n");
			}
			else
			{
				printf("插入失败\n\n");
			}
			break;
		case 7:
			if (PopStack(S, &e))
			{
				printf("删除成功\n\n");
			}
			else
			{
				printf("删除失败\n\n");
			}
			break;
		case 8:
			PushStack(S, e);
			break;
		case 9:
			StackTraverse(S);
			break;
		}
	}
	printf("\n\n谢谢您的使用，请按任意键退出\n\n\n");
	system("pause");
}