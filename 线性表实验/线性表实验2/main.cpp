#include "SqList.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

int  main()
{
	menu();//初始化主菜单 
	slist L;
	int choose, x, cd;
	student sd;
	while (1)
	{
		puts("请输入功能选项");
		scanf_s("%d", &choose);
		if (choose == 0) break;
		if (choose < 0 || choose>8)
		{
			puts("对不起，输入错误，请重新输入！");
			continue;
		}
		switch (choose)
		{
		case 1:
			if (emlist(&L))
				printf("成功建立顺序表\n\n");
			else
				printf("顺序表建立失败\n\n");
			break;
		case 2:
			printf("请输入需要记录的学生人数(小于100)：");
			scanf_s("%d", &x);
			for (int i = 1; i <= x; i++)
			{
				printf("请输入第%d个学生的信息:", i);
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
			printf("请输入要查找的学生的姓名：");
			char names[20];
			scanf_s("%s", names);
			if (search(L, names))
				output(&L.s[search(L, names)]);
			else
				printf("对不起，查无此人\n");
			puts("");
			break;
		case 5:
			printf("请输入要查询的位置：");
			scanf_s("%d", &cd);
			sd = getsd(L, cd);
			output(&sd);
			puts("");
			break;

		case 6:
			printf("请输入要插入的位置：");
			scanf_s("%d", &cd);
			printf("请输入你想要插入的学生的信息：");
			input(&sd);
			if (listinsert(L, cd, sd))
				printf("插入成功\n\n"), x++;
			else
				printf("插入失败\n\n");
			break;
		case 7:
			printf("请输入要删除的位置：");
			scanf_s("%d", &cd);
			printf("请输入你想要删除的学生的信息：");
			input(&sd);
			if (listdelete(L, cd, sd))
				printf("删除成功\n\n"), x--;
			else
				printf("删除失败\n\n");
			break;
		case 8:
			printf("已录入的学生个数为:%d\n\n", L.length);
			break;

		}
	}
	printf("\n\n谢谢您的使用，请按任意键退出\n\n\n");
	system("pause");
}