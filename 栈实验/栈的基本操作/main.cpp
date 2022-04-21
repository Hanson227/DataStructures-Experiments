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
		puts("�����빦��ѡ��");
		scanf_s("%d", &choose);
		if (choose == 0) break;
		if (choose < 0 || choose>9)
		{
			puts("�Բ�������������������룡");
			continue;
		}
		switch (choose)
		{
		case 1:
			if (InitStack(S))
				printf("�ɹ�����ջ\n\n");
			else
				printf("ջ����ʧ��\n\n");
			break;
		case 2:
			printf("������ջ�ĸ߶�(С��100)��");
			scanf_s("%d", &n);
			for (int i = 1; i <= n; i++)
			{
				printf("�������%d����Ϣ:", i);
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
			printf("ջ�ĳ���Ϊ %d.\n", LengthStack(S));
			break;
		case 5:
			printf("ջ����Ԫ����%d.\n", GetTopStack(S, &e));
		case 6:
			printf("����������Ҫ�������Ϣ��");
			scanf_s("%d", &e);
			if (PushStack(S, e))
			{
				printf("����ɹ�\n\n");
			}
			else
			{
				printf("����ʧ��\n\n");
			}
			break;
		case 7:
			if (PopStack(S, &e))
			{
				printf("ɾ���ɹ�\n\n");
			}
			else
			{
				printf("ɾ��ʧ��\n\n");
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
	printf("\n\nлл����ʹ�ã��밴������˳�\n\n\n");
	system("pause");
}