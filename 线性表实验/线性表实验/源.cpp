#include "SqList.h"
#include <stdio.h>


int main()
{
	SqList L; 
	InitList_Sq(L);
	ValueList_Sq(L);
	ListLength_Sq(L);
	ListEmpty_Sq(L);
	GetElem_Sq(L, 5);
	ListInsert_Sq(L, 4,'g');
	PrintList_Sq(L);
	DeleteList_Sq(L, 3);
	PrintList_Sq(L);
	DelectList_chongfu(L);
	PrintList_Sq(L);
	DistoryList_Sq(L);
	return 0;
}