#include "SqList.h"
#include <stdio.h>


void sort(SqList& La, SqList& Lb, SqList& Lc);


int main(void)
{
	SqList  La,  Lb,  Lc;
	int m, n, i;
	InitList_Sq(La);
	InitList_Sq(Lb);
	InitList_Sq(Lc);
	printf("AB集合中的个数分别为：");
	scanf_s("%d %d", &m, &n);
	printf("依次输入集合A中的元素");
	for (i = 0; i < m; i++)
	{
		scanf_s("%d", &La.elem[i]);
	}
	printf("依次输入集合B中的元素");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &Lb.elem[i]);
	}
	La.length = m;
	Lb.length = n;
	printf("集合A中");
	PrintList_Sq(La);
	printf("集合B中");
	PrintList_Sq(Lb);
	sort(La, Lb, Lc);
	printf("两个集合的交集为");
	PrintList_Sq(Lc);
}


void sort(SqList& La, SqList& Lb, SqList& Lc)
{
	int i, j, k = 0;
	for (i = 0; i < La.length; i++)
	{
		for (j = 0; j < Lb.length; j++)
		{
			if (La.elem[i] == Lb.elem[j])
			{
				Lc.elem[k] = La.elem[i];
				k++;
			}
		}
	}
	Lc.length = k;
}
