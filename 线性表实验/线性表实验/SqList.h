#ifndef __SqList_H


typedef char Status;
typedef char ElemType;

typedef struct {
	ElemType* elem;          //存储空间的基址 
	int length;              //当前线性表的长度
	int listsize;            //当前线性表的存储容量          
}SqList;

Status InitList_Sq(SqList& L);
Status ValueList_Sq(SqList& L);
Status DistoryList_Sq(SqList& L);
Status ClearList_Sq(SqList& L);
Status ListEmpty_Sq(SqList& L);
Status ListLength_Sq(SqList& L);
void GetElem_Sq(SqList& L, int index);
void ListInsert_Sq(SqList& L, int i, ElemType e);
Status PrintList_Sq(SqList& L);
Status DeleteList_Sq(SqList& L, int i);
Status PriorElem_Sq(SqList& L, int i);
Status NextElem_Sq(SqList& L, int i);
void DelectList_chongfu(SqList& L);

#endif // !__SqList_H
