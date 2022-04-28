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
	printf("AB�����еĸ����ֱ�Ϊ��");
	scanf_s("%d %d", &m, &n);
	printf("�������뼯��A�е�Ԫ��");
	for (i = 0; i < m; i++)
	{
		scanf_s("%d", &La.elem[i]);
	}
	printf("�������뼯��B�е�Ԫ��");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &Lb.elem[i]);
	}
	La.length = m;
	Lb.length = n;
	printf("����A��");
	PrintList_Sq(La);
	printf("����B��");
	PrintList_Sq(Lb);
	sort(La, Lb, Lc);
	printf("�������ϵĽ���Ϊ");
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
