#ifndef __SqList_H

const int maxsize = 200;

typedef struct//����ѧ���Ĵ洢��Ϣ 
{
	char ID[8];
	char name[20];
	char sex[10];
	double score;
}student;

typedef struct
{
	student* s;//˳���Ļ���ַ 
	int length;//��ĳ��� 
}slist;

int emlist(slist* l);//����һ���յ�˳��� ��ʵ���Ͼ��Ǹ�˳������ռ䣩 
void output(student* sd);//���ѧ����Ϣ 
student getsd(slist& L, int i);
int search(slist& L, char str[]);//����ѧ����Ϣ 
int listinsert(slist& L, int i, student sd);//����ѧ����Ϣ 
int listdelete(slist& L, int i, student sd);//ɾ��ѧ����Ϣ 
void menu();//���˵�
void input(student* sd);//����ѧ����Ϣ 

#endif // !__SqList_H

