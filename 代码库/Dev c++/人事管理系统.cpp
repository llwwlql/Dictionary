#include <stdio.h>
#include <string.h> 
int N=0;
typedef struct {
	char name[20];		//姓名 
	char sex;			//性别 
	int age;			//年龄 
	char type[100];		//职工类型 
	char post[100];		//职务 
	char position[100];	//职称
	char education[100];//学历 
	char politics[100];	//政治面貌 
	int year;			//来院时间 
	int month;
	int day;
	int time; 			//工作时间 
}People;

void add(People *pe,int N)
{
	printf("请输出姓名:");
	gets(pe[N].name);
	printf("请输入性别:") ;
	scanf("%c",pe->sex);
	printf("请输入年龄:");
	scanf("%d",&pe[N].age);
	getchar();
	printf("请输入职工类型:");
	gets(pe[N].type);
	printf("请输入职务:");
	gets(pe[N].post);
	printf("请输入职称:");
	gets(pe[N].position);
	printf("请输入学历:");
	gets(pe[N].education);
	printf("请输入政治面貌:");
	gets(pe[N].politics);
	printf("请输入来院时间(year-month-day):");
	scanf("%d-%d-%d",pe[N].year,pe[N].month,pe[N].day);
	printf("请输入工作时间:");
	printf("%d",pe[N].time);
}
void change(People *pe)
{
	char a[20];
	int peace=0,i;
	printf("输入要改变信息的姓名：");
	gets(a);
	peace=1;
	for(i=0;i<N && peace;i++)
	{
		if(strcmp(a,pe[i].name)==0)
			peace=0;
	}printf("请重新输出姓名:");
	gets(pe[i].name);
	printf("请重新输入性别:") ;
	scanf("%c",pe->sex);
	printf("请重新输入年龄:");
	scanf("%d",&pe[i].age);
	getchar();
	printf("请重新输入职工类型:");
	gets(pe[i].type);
	printf("请重新输入职务:");
	gets(pe[i].post);
	printf("请重新输入职称:");
	gets(pe[i].position);
	printf("请重新输入学历:");
	gets(pe[i].education);
	printf("请重新输入政治面貌:");
	gets(pe[i].politics);
	printf("请重新输入来院时间(year-month-day):");
	scanf("%d-%d-%d",pe[i].year,pe[i].month,pe[i].day);
	printf("请重新输入工作时间:");
	printf("%d",pe[i].time);
}
void dele(People *pe)
{
	char a[20];
	int peace=0,i;
	printf("输入要改变信息的姓名：");
	gets(a);
	peace=1;
	for(i=0;i<N && peace;i++)
	{
		if(strcmp(a,pe[i].name)==0)
			peace=0;
	}
	for(i=i;i<N-1;i++)
	{
		pe[i]=pe[i+1];
	}
	N--;
}

void view(People *pe)
{
	 
}

int main()
{
	People people[1000];
	int n;
	while(1)
	{
		printf("		===============================\n");
		printf(" 		1.添加。\n");
		printf("		2.改变。\n");
		printf("		3.删除。\n");
		printf("		4.查看\n");
		printf("		5.保存文件\n");
		printf("		6.退出\n");
		printf("		===============================\n");
		
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				add(people,N);
				N++;
				break;
			case 2:
				change(people);
				break;
			case 3:
				dele(people); 
				break;
			case 4:
				view(people);
				break;
			case 5:
				Save(people);
				break;
			case 6:
				return 0;
		}
	}
	
	return 0;
}
