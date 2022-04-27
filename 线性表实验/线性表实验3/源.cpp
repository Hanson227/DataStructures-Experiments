#include "SqList.h"
#include <stdio.h>


void SortList(SqList& L, int m, int n);

int main()
{
	SqList L;
	int m, n, i;
	InitList_Sq(L);
	printf("顺序表中前后有序的个数分别为：");
	scanf_s("%d %d", &m, &n);
	printf("依次输入%d个有序元素", m);
	for (i = 0; i < m; i++)
	{
		scanf_s("%d", &L.elem[i]);
	}
	printf("依次输入后%d个有序元素", n);
	for (i; i < (m + n); i++)
	{
		scanf_s("%d", &L.elem[i]);
	}
	L.length = (m + n);
	printf("当前线性表的元素为：");
	PrintList_Sq(L);
	printf("排序后线性表的元素为：");
	SortList(L, m, n);
	PrintList_Sq(L);
	DistoryList_Sq(L);

}


void SortList(SqList &L, int m, int n)
{
	int i, length, temp;
	length = m + n;
	n = m;
	m = 0;
	while (n < length )
	{
		if (L.elem[n] < L.elem[m])
		{
			temp = L.elem[n];
			for (i = n; i > m; i--)
			{
				L.elem[i] = L.elem[i - 1];
			}
			L.elem[m] = temp;
			m++;
			n++;
		}
		else if (L.elem[m] < L.elem[n+1])
		{
			m++;
		}
	}
}
