#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <stdio.h>

using namespace std;
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
	int length,cd;//��ĳ��� 
}slist;

int emlist(slist* l)//����һ���յ�˳��� ��ʵ���Ͼ��Ǹ�˳������ռ䣩 
{
	l->s = (student*)malloc(sizeof(student) * maxsize);//��Ϊmalloc���ص���һ��void* ���������ǿתΪ���Լ���Ҫ������
	if (!l->s) exit(-2);
	l->length = 0;
	return 1;
}

void output(student* sd)//���ѧ����Ϣ 
{
	printf("����:%-20s\nѧ��:%-10s\n�Ա�:%-10s\n�ɼ�:%-10.2lf\n\n", sd->name, sd->ID, sd->sex,sd->score);
}
student getsd(slist& L, int i)
{
	return L.s[i];
}
int search(slist& L, char str[])//����ѧ����Ϣ 
{
	for (int i = 1; i <= L.length; i++)
	{
		if (strcmp(L.s[i].name, str) == 0)
			return i;
	}
	return 0;
}
int listinsert(slist& L,int i,student sd)//����ѧ����Ϣ 
{
	if (i<1 || i>L.length + 1) return 0;//���Ҫ�����λ�ò��Ϸ����� ����ͬ 
	if (i == maxsize) return 0;
	for (int j = L.length; j >= i; j--)//�Ȱ�Ҫ�����λ��֮���Ԫ�غ��� 
	{
		L.s[j + 1] = L.s[j];
	}
	L.s[i] = sd;
	L.length++;//�ǵð�˳���ĳ���++�� 
	return 1;
}
int listdelete(slist& L, int i, student sd)//ɾ��ѧ����Ϣ 
{
	if (i<1 || i>L.length) return 0;
	if (i == maxsize) return 0;
	for (int j = i; j <= L.length; j++)
	{
		L.s[j] = L.s[j + 1];
	}
	L.length--;
	return 1;
}
void menu()//���˵�
{
	printf("\n********************************\n\n");
	puts("1. ����˳���");
	puts("2. ¼��ѧ����Ϣ");
	puts("3. ��ʾѧ����Ϣ");
	puts("4. �������������Ҹ�ѧ��");
	puts("5. ��ʾĳλ�ø�ѧ����Ϣ");
	puts("6. ��ָ��λ�ò���ѧ����Ϣ");
	puts("7. ��ָ��λ��ɾ��ѧ����Ϣ");
	puts("8. ͳ��ѧ������");
	puts("0. �˳�");
	printf("\n********************************\n\n");
}
void input(student* sd)//����ѧ����Ϣ 
{
	printf("����:"); scanf_s("%s", &sd->name,sizeof(sd->name));
	printf("ѧ��:"); scanf_s("%s", &sd->ID,sizeof(sd->ID));
	printf("�Ա�:"); scanf_s("%s",&sd->sex, sizeof(sd->sex));
	printf("�ɼ�:"); scanf_s("%lf", &sd->score);
	printf("�������\n\n");
}
