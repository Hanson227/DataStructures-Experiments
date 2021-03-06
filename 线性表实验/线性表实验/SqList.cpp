#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "SqList.h"

//函数结果状态代码 
#define TRUE     1     //代码中出现TRUE相当于出现了1 
#define FALSE    0     //出现FALSE相当于出现了0 
#define OK       1     //出现OK相当于出现了1 
#define ERROR    0     //出现ERROR相当于出现了0 
#define INFEASIBLE    -1
#define OVERFLOW      -2 

typedef char Status;
typedef char ElemType;

#define LIST_INIT_SIZE    100     //线性表存储空间的初始分配量 
#define LISTINCREMENT     10      //线性表存储空间的分配增量 



//构造一个空的线性表
Status InitList_Sq(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));      //L.elem为首元素的地址 
	if (!L.elem) {            //如果存储空间分配失败，L.elem为NULL
		printf("存储空间分配失败\n");
		exit(OVERFLOW);
	}
	L.length = 0;            //当前线性表为空表，即线性表长度为0
	L.listsize = LIST_INIT_SIZE;           //给线性表分配初始容量
	printf("一个空的线性表已经构建成功\n");      //输出空线性表构建成功的提示消息 
	return OK;
}

//对线性表进行赋值
Status ValueList_Sq(SqList& L) {
	int i = 10, j; printf("请输入元素"); 
	for (j = 0; j < i; j++) {
		scanf_s("%c ",&L.elem[j]);
	}
	L.length = i;          //赋值完成后，修改并保存线性表的长度 
	printf("赋值成功\n");
	return OK;
}

//对线性表进行销毁
Status DistoryList_Sq(SqList& L) {
	if (!L.elem) {
		printf("您还未建立线性表，请先建立线性表\n");
		return ERROR;
	}
	free(L.elem);            //使用free函数，将之前动态分配的内存还给系统 
	L.elem = NULL;           //重置elem的值为Null 
	L.length = 0;            //将线性表的元素个数重置为0
	L.listsize = 0;          //将线性表的存储容量重置为0 
	printf("线性表已经销毁\n");
	return OK;
}

//对线性表进行重置
Status ClearList_Sq(SqList& L) {
	if (L.elem) {                  //如果线性表存在 
		L.length = 0;            //将线性表的元素个数重置为0
		printf("线性表已重置\n");
		return OK;
	}
	else
		printf("线性表不存在，无法重置\n");
	return OK;
}

//判断线性表是否为空
Status ListEmpty_Sq(SqList& L) {
	if (L.elem) {          //判断线性表是否为空的前提是线性表存在，当首元素地址即L.elem存在时说明线性表存在 
		if (L.length != 0) {               //如果线性表中元素为0，即L.length的值为0时说明线性表是空表 
			printf("线性表不是空表\n");
			return FALSE;
		}
		else
			printf("线性表是空表\n");
		return TRUE;
	}
	else
		printf("线性表不存在，无法判断\n");
	return OK;
}

//获取线性表的长度
Status ListLength_Sq(SqList& L) {
	if (L.elem) {              //判断当前线性表存在 
		int K;
		K = L.length;        //将线性表的元素个数赋值给K
		printf("线性表长度为%d\n", K);
		return OK;
	}
	else
		printf("线性表不存在，无法判断\n");
	return OK;
}

//获取线性表某一位置对应的元素
void GetElem_Sq(SqList& L, int index) {
	char Num;
	Num = L.elem[index - 1];
	printf("第%d个位置的元素为：%c\n", index, Num);
}


//在线性表某一位置插入元素
void ListInsert_Sq(SqList& L, int i, ElemType e) {
	ElemType* newbase;
	char* q, * p;
	q = &(L.elem[i - 1]);                 //L.elem[index-1]为数组中的最后一个元素，q为要插入的位置 
	for (p = &(L.elem[L.length - 1]); p >= q; --p)
		*(p + 1) = *p;                    //要插入位置以及之后的位置向后移 
	*q = e;                             //将e插入到想要插入的位置 
	++L.length;                         //插入新的元素之后表长加1 
	printf("元素插入成功\n");
}

//打印线性表
Status PrintList_Sq(SqList& L) {
	printf("当前线性表的元素为：");
	for (int K = 0; K < L.length; K++)      //遍历当前线性表 
		printf("  %c", L.elem[K]);
	printf("\n");                        //换行 
	return OK;
}

//删除线性表某一位置的元素
Status DeleteList_Sq(SqList& L, int i) {
	char* p, * q;
	if (i < 1 || i > L.length) {            //如果要删除的位置不合法
		printf("请输入一个有效数字\n");
		return ERROR;
	}
	p = &(L.elem[i - 1]);                 //p为被删除元素的位置
	q = L.elem + L.length - 1;            //将表尾元素的位置赋值给q
	for (++p; p <= q; p++)
		*(p - 1) = *p;                    //被删除的元素之后的元素全部左移 
	--L.length;                           //表长减1 
	printf("第%d个元素删除成功\n", i);
	return OK;
}

//求线性表某一元素的前驱
Status PriorElem_Sq(SqList& L, int i) {
	int K;
	if (L.elem) {          //判断线性表是否为空的前提是线性表存在，当首元素地址即L.elem存在时说明线性表存在
		if (i <= 1 || i > L.length + 1)              //判断输入的i值是否合法 
			printf("请输入一个有效数字\n");
		K = L.elem[i - 2];        //将第i个元素的前一个元素赋值给K
		printf("第%d个位置的直接前驱为：%d\n", i, K);
	}
	else
		printf("线性表不存在，无法判断\n");
	return OK;
}

//求线性表某一元素的后继 
Status NextElem_Sq(SqList& L, int i) {
	int K;
	if (L.elem) {          //判断线性表是否为空的前提是线性表存在，当首元素地址即L.elem存在时说明线性表存在
		if (i <= 1 || i > L.length - 1)              //判断输入的i值是否合法 
			printf("请输入一个有效数字\n");
		K = L.elem[i];        //将第i个元素的后一个元素赋值给K
		printf("第%d个位置的直接后继为：%d\n", i, K);
	}
	else
		printf("线性表不存在，无法判断\n");
	return OK;
}

void DelectList_chongfu(SqList& L) {
	char* p, * q;
	for (int i = 0; i < L.length; i++)
	{
		char b = L.elem[i];
		for (int j = i+1; j < L.length; j++)
		{
			if (b==L.elem[j])
			{
				p = &(L.elem[j]);                 //p为被删除元素的位置
				q = L.elem + L.length - 1;            //将表尾元素的位置赋值给q
				for (p; p < q; p++)
				{
					*(p) = *(p+1);                    //被删除的元素之后的元素全部左移
				}	 
				--L.length;
			}
		}
	}
}

