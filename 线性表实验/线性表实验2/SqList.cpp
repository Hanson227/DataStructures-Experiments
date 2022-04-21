#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <stdio.h>

using namespace std;
const int maxsize = 200;

typedef struct//定义学生的存储信息 
{
	char ID[8];
	char name[20];
	char sex[10];
	double score;
}student;
typedef struct
{
	student* s;//顺序表的基地址 
	int length,cd;//表的长度 
}slist;

int emlist(slist* l)//创建一个空的顺序表 （实际上就是给顺序表分配空间） 
{
	l->s = (student*)malloc(sizeof(student) * maxsize);//因为malloc返回的是一个void* 所以这里得强转为你自己需要的类型
	if (!l->s) exit(-2);
	l->length = 0;
	return 1;
}

void output(student* sd)//输出学生信息 
{
	printf("姓名:%-20s\n学号:%-10s\n性别:%-10s\n成绩:%-10.2lf\n\n", sd->name, sd->ID, sd->sex,sd->score);
}
student getsd(slist& L, int i)
{
	return L.s[i];
}
int search(slist& L, char str[])//搜索学生信息 
{
	for (int i = 1; i <= L.length; i++)
	{
		if (strcmp(L.s[i].name, str) == 0)
			return i;
	}
	return 0;
}
int listinsert(slist& L,int i,student sd)//插入学生信息 
{
	if (i<1 || i>L.length + 1) return 0;//如果要插入的位置不合法报错 ，下同 
	if (i == maxsize) return 0;
	for (int j = L.length; j >= i; j--)//先把要插入的位置之后的元素后移 
	{
		L.s[j + 1] = L.s[j];
	}
	L.s[i] = sd;
	L.length++;//记得把顺序表的长度++； 
	return 1;
}
int listdelete(slist& L, int i, student sd)//删除学生信息 
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
void menu()//主菜单
{
	printf("\n********************************\n\n");
	puts("1. 构造顺序表");
	puts("2. 录入学生信息");
	puts("3. 显示学生信息");
	puts("4. 输入姓名，查找该学生");
	puts("5. 显示某位置该学生信息");
	puts("6. 在指定位置插入学生信息");
	puts("7. 在指定位置删除学生信息");
	puts("8. 统计学生个数");
	puts("0. 退出");
	printf("\n********************************\n\n");
}
void input(student* sd)//输入学生信息 
{
	printf("姓名:"); scanf_s("%s", &sd->name,sizeof(sd->name));
	printf("学号:"); scanf_s("%s", &sd->ID,sizeof(sd->ID));
	printf("性别:"); scanf_s("%s",&sd->sex, sizeof(sd->sex));
	printf("成绩:"); scanf_s("%lf", &sd->score);
	printf("输入完成\n\n");
}
