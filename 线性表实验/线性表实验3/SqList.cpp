#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "SqList.h"

//�������״̬���� 
#define TRUE     1     //�����г���TRUE�൱�ڳ�����1 
#define FALSE    0     //����FALSE�൱�ڳ�����0 
#define OK       1     //����OK�൱�ڳ�����1 
#define ERROR    0     //����ERROR�൱�ڳ�����0 
#define INFEASIBLE    -1
#define OVERFLOW      -2 

typedef int  Status;
typedef int ElemType;

#define LIST_INIT_SIZE    100     //���Ա�洢�ռ�ĳ�ʼ������ 
#define LISTINCREMENT     10      //���Ա�洢�ռ�ķ������� 



//����һ���յ����Ա�
Status InitList_Sq(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));      //L.elemΪ��Ԫ�صĵ�ַ 
	if (!L.elem) {            //����洢�ռ����ʧ�ܣ�L.elemΪNULL
		printf("�洢�ռ����ʧ��\n");
		exit(OVERFLOW);
	}
	L.length = 0;            //��ǰ���Ա�Ϊ�ձ������Ա���Ϊ0
	L.listsize = LIST_INIT_SIZE;           //�����Ա�����ʼ����
	printf("һ���յ����Ա��Ѿ������ɹ�\n");      //��������Ա����ɹ�����ʾ��Ϣ 
	return OK;
}

//�����Ա���и�ֵ
Status ValueList_Sq(SqList& L) {
	int i = 10, j; printf("������Ԫ��"); 
	for (j = 0; j < i; j++) {
		scanf_s("%c ",&L.elem[j]);
	}
	L.length = i;          //��ֵ��ɺ��޸Ĳ��������Ա�ĳ��� 
	printf("��ֵ�ɹ�\n");
	return OK;
}

//�����Ա��������
Status DistoryList_Sq(SqList& L) {
	if (!L.elem) {
		printf("����δ�������Ա����Ƚ������Ա�\n");
		return ERROR;
	}
	free(L.elem);            //ʹ��free��������֮ǰ��̬������ڴ滹��ϵͳ 
	L.elem = NULL;           //����elem��ֵΪNull 
	L.length = 0;            //�����Ա��Ԫ�ظ�������Ϊ0
	L.listsize = 0;          //�����Ա�Ĵ洢��������Ϊ0 
	printf("���Ա��Ѿ�����\n");
	return OK;
}

//�����Ա��������
Status ClearList_Sq(SqList& L) {
	if (L.elem) {                  //������Ա���� 
		L.length = 0;            //�����Ա��Ԫ�ظ�������Ϊ0
		printf("���Ա�������\n");
		return OK;
	}
	else
		printf("���Ա����ڣ��޷�����\n");
	return OK;
}

//�ж����Ա��Ƿ�Ϊ��
Status ListEmpty_Sq(SqList& L) {
	if (L.elem) {          //�ж����Ա��Ƿ�Ϊ�յ�ǰ�������Ա���ڣ�����Ԫ�ص�ַ��L.elem����ʱ˵�����Ա���� 
		if (L.length != 0) {               //������Ա���Ԫ��Ϊ0����L.length��ֵΪ0ʱ˵�����Ա��ǿձ� 
			printf("���Ա��ǿձ�\n");
			return FALSE;
		}
		else
			printf("���Ա��ǿձ�\n");
		return TRUE;
	}
	else
		printf("���Ա����ڣ��޷��ж�\n");
	return OK;
}

//��ȡ���Ա�ĳ���
Status ListLength_Sq(SqList& L) {
	if (L.elem) {              //�жϵ�ǰ���Ա���� 
		int K;
		K = L.length;        //�����Ա��Ԫ�ظ�����ֵ��K
		printf("���Ա���Ϊ%d\n", K);
		return OK;
	}
	else
		printf("���Ա����ڣ��޷��ж�\n");
	return OK;
}

//��ȡ���Ա�ĳһλ�ö�Ӧ��Ԫ��
void GetElem_Sq(SqList& L, int index) {
	char Num;
	Num = L.elem[index - 1];
	printf("��%d��λ�õ�Ԫ��Ϊ��%c\n", index, Num);
}


//�����Ա�ĳһλ�ò���Ԫ��
void ListInsert_Sq(SqList& L, int i, ElemType e) {
	ElemType* newbase;
	int* q, * p;
	q = &(L.elem[i - 1]);                 //L.elem[index-1]Ϊ�����е����һ��Ԫ�أ�qΪҪ�����λ�� 
	for (p = &(L.elem[L.length - 1]); p >= q; --p)
		*(p + 1) = *p;                    //Ҫ����λ���Լ�֮���λ������� 
	*q = e;                             //��e���뵽��Ҫ�����λ�� 
	++L.length;                         //�����µ�Ԫ��֮�����1 
	printf("Ԫ�ز���ɹ�\n");
}

//��ӡ���Ա�
Status PrintList_Sq(SqList& L) {
	
	for (int K = 0; K < L.length; K++)      //������ǰ���Ա� 
		printf("  %d", L.elem[K]);
	printf("\n");                        //���� 
	return OK;
}

//ɾ�����Ա�ĳһλ�õ�Ԫ��
Status DeleteList_Sq(SqList& L, int i) {
	int* p, * q;
	if (i < 1 || i > L.length) {            //���Ҫɾ����λ�ò��Ϸ�
		printf("������һ����Ч����\n");
		return ERROR;
	}
	p = &(L.elem[i - 1]);                 //pΪ��ɾ��Ԫ�ص�λ��
	q = L.elem + L.length - 1;            //����βԪ�ص�λ�ø�ֵ��q
	for (++p; p <= q; p++)
		*(p - 1) = *p;                    //��ɾ����Ԫ��֮���Ԫ��ȫ������ 
	--L.length;                           //����1 
	printf("��%d��Ԫ��ɾ���ɹ�\n", i);
	return OK;
}

//�����Ա�ĳһԪ�ص�ǰ��
Status PriorElem_Sq(SqList& L, int i) {
	int K;
	if (L.elem) {          //�ж����Ա��Ƿ�Ϊ�յ�ǰ�������Ա���ڣ�����Ԫ�ص�ַ��L.elem����ʱ˵�����Ա����
		if (i <= 1 || i > L.length + 1)              //�ж������iֵ�Ƿ�Ϸ� 
			printf("������һ����Ч����\n");
		K = L.elem[i - 2];        //����i��Ԫ�ص�ǰһ��Ԫ�ظ�ֵ��K
		printf("��%d��λ�õ�ֱ��ǰ��Ϊ��%d\n", i, K);
	}
	else
		printf("���Ա����ڣ��޷��ж�\n");
	return OK;
}

//�����Ա�ĳһԪ�صĺ�� 
Status NextElem_Sq(SqList& L, int i) {
	int K;
	if (L.elem) {          //�ж����Ա��Ƿ�Ϊ�յ�ǰ�������Ա���ڣ�����Ԫ�ص�ַ��L.elem����ʱ˵�����Ա����
		if (i <= 1 || i > L.length - 1)              //�ж������iֵ�Ƿ�Ϸ� 
			printf("������һ����Ч����\n");
		K = L.elem[i];        //����i��Ԫ�صĺ�һ��Ԫ�ظ�ֵ��K
		printf("��%d��λ�õ�ֱ�Ӻ��Ϊ��%d\n", i, K);
	}
	else
		printf("���Ա����ڣ��޷��ж�\n");
	return OK;
}

void DelectList_chongfu(SqList& L) {
	int* p, * q;
	for (int i = 0; i < L.length; i++)
	{
		char b = L.elem[i];
		for (int j = i+1; j < L.length; j++)
		{
			if (b==L.elem[j])
			{
				p = &(L.elem[j]);                 //pΪ��ɾ��Ԫ�ص�λ��
				q = L.elem + L.length - 1;            //����βԪ�ص�λ�ø�ֵ��q
				for (p; p < q; p++)
				{
					*(p) = *(p+1);                    //��ɾ����Ԫ��֮���Ԫ��ȫ������
				}	 
				--L.length;
			}
		}
	}
}

