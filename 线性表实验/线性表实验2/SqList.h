#ifndef __SqList_H

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
	int length;//表的长度 
}slist;

int emlist(slist* l);//创建一个空的顺序表 （实际上就是给顺序表分配空间） 
void output(student* sd);//输出学生信息 
student getsd(slist& L, int i);
int search(slist& L, char str[]);//搜索学生信息 
int listinsert(slist& L, int i, student sd);//插入学生信息 
int listdelete(slist& L, int i, student sd);//删除学生信息 
void menu();//主菜单
void input(student* sd);//输入学生信息 

#endif // !__SqList_H

