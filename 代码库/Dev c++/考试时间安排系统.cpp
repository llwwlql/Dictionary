#include <stdio.h>
#include <string.h>
int N;
typedef struct{
	int month,day;
	char place[100];
	char subject[100];
}Exam;
void add(Exam *exam,int i)					//指针 
{// 添加考试安排
	printf("请输入科目:");
	scanf("%s",exam[i].subject);
	printf("请输入考试时间(月-日)："); 
	scanf("%d-%d",&exam[i].month,&exam[i].day);
	printf("请输入考试地点：");
	scanf("%s",exam[i].place);
}
void change(Exam *exam)
{// 改变考试安排
	char ch[100];
	int i; 
	printf("请输入要改变的考试科目:");
	scanf("%s",ch);
	for(i=0;i<N;i++)
	{
		if(exam[i].subject==ch)
		{
			break;
		}
	}
	add(exam,i);	
}
void sort(Exam *exam)
{// 对考试安排按考试时间排序
	int i,j;
	Exam temp;
	for(i=0;i<N;i++)			//循环语句 （冒泡排序）
	{
		for(j=i+1;j<N;j++)
		{
			if(exam[i].month>exam[j].month)			//if判断语句 （判断，交换） 
			{
				temp=exam[i];
				exam[i]=exam[j];
				exam[j]=temp;
			}
			else if(exam[i].month==exam[j].month)
			{
				if(exam[i].day>exam[j].day)
				{		
					temp=exam[i];
					exam[i]=exam[j];
					exam[j]=temp;
				}
			}
		}
	}
}

void view(Exam *exam)
{//查看考试安排
	int i;
	printf("科目	时间	地点\n");
	for(i=0;i<N;i++)
	{
		printf("%s	%2d-%2d	%s\n",exam[i].subject,exam[i].month,exam[i].day,exam[i].place);
	}
}
void Save(Exam *exam)
{
	FILE *fp;
	int i;
	char filename[20];
	printf("请输入文件名:");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)	//	建立一个新文件
	{
		printf("无法打开此文件\n");
		return ; 
	}
	fprintf(fp,"科目	时间	地点\n");
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%s	%2d-%2d	%s\n",exam[i].subject,exam[i].month,exam[i].day,exam[i].place);
	}
	fclose(fp);
	
} 

int main()
{
	FILE *fp;
	Exam exam[20];
	int n;
	N=0;
	while(1)
	{
		printf("		===============================\n");
		printf(" 		1.添加考试安排。\n");
		printf("		2.改变考试安排。\n");
		printf("		3.对考试安排按考试时间排序。\n");
		printf("		4.查看考试安排\n");
		printf("		5.保存文件\n");
		printf("		6.退出\n");
		printf("		===============================\n");
		
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				add(exam,N);
				N++;
				break;
			case 2:
				change(exam);
				break;
			case 3:
				sort(exam); 
				break;
			case 4:
				view(exam);
				break;
			case 5:
				Save(exam);
				break;
			case 6:
				return 0;
		}
	}
	
	return 0;
}
