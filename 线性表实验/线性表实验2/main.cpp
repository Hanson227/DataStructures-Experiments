#include "SqList.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

int  main()
{
	menu();//��ʼ�����˵� 
	slist L;
	int choose, x, cd;
	student sd;
	while (1)
	{
		puts("�����빦��ѡ��");
		scanf_s("%d", &choose);
		if (choose == 0) break;
		if (choose < 0 || choose>8)
		{
			puts("�Բ�������������������룡");
			continue;
		}
		switch (choose)
		{
		case 1:
			if (emlist(&L))
				printf("�ɹ�����˳���\n\n");
			else
				printf("˳�����ʧ��\n\n");
			break;
		case 2:
			printf("��������Ҫ��¼��ѧ������(С��100)��");
			scanf_s("%d", &x);
			for (int i = 1; i <= x; i++)
			{
				printf("�������%d��ѧ������Ϣ:", i);
				input(&L.s[i]);
			}
			L.length = x;
			puts("");
			break;
		case 3:
			for (int i = 1; i <= x; i++)
			{
				student sd = getsd(L, i);
				output(&sd);
			}
			break;
		case 4:
			printf("������Ҫ���ҵ�ѧ����������");
			char names[20];
			scanf_s("%s", names);
			if (search(L, names))
				output(&L.s[search(L, names)]);
			else
				printf("�Բ��𣬲��޴���\n");
			puts("");
			break;
		case 5:
			printf("������Ҫ��ѯ��λ�ã�");
			scanf_s("%d", &cd);
			sd = getsd(L, cd);
			output(&sd);
			puts("");
			break;

		case 6:
			printf("������Ҫ�����λ�ã�");
			scanf_s("%d", &cd);
			printf("����������Ҫ�����ѧ������Ϣ��");
			input(&sd);
			if (listinsert(L, cd, sd))
				printf("����ɹ�\n\n"), x++;
			else
				printf("����ʧ��\n\n");
			break;
		case 7:
			printf("������Ҫɾ����λ�ã�");
			scanf_s("%d", &cd);
			printf("����������Ҫɾ����ѧ������Ϣ��");
			input(&sd);
			if (listdelete(L, cd, sd))
				printf("ɾ���ɹ�\n\n"), x--;
			else
				printf("ɾ��ʧ��\n\n");
			break;
		case 8:
			printf("��¼���ѧ������Ϊ:%d\n\n", L.length);
			break;

		}
	}
	printf("\n\nлл����ʹ�ã��밴������˳�\n\n\n");
	system("pause");
}