#include "SqList.h"
#include <stdio.h>


void SortList(SqList& L, int m, int n);

int main()
{
	SqList L;
	int m, n, i;
	InitList_Sq(L);
	printf("˳�����ǰ������ĸ����ֱ�Ϊ��");
	scanf_s("%d %d", &m, &n);
	printf("��������%d������Ԫ��", m);
	for (i = 0; i < m; i++)
	{
		scanf_s("%d", &L.elem[i]);
	}
	printf("���������%d������Ԫ��", n);
	for (i; i < (m + n); i++)
	{
		scanf_s("%d", &L.elem[i]);
	}
	L.length = (m + n);
	printf("��ǰ���Ա��Ԫ��Ϊ��");
	PrintList_Sq(L);
	printf("��������Ա��Ԫ��Ϊ��");
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
	while (m < length - 1)
	{
		if (L.elem[n] < L.elem[m])
		{
			temp = L.elem[n];
			for (i = n; i > m; i--)
				L.elem[i] = L.elem[i - 1];
			L.elem[m] = temp;
			m++;
			n++;
		}
		else if (L.elem[m] < L.elem[n])
		{
			m++;
		}
	}
}
