#include <stdio.h>
#include <string.h> 
int N=0;
typedef struct {
	char name[20];		//���� 
	char sex;			//�Ա� 
	int age;			//���� 
	char type[100];		//ְ������ 
	char post[100];		//ְ�� 
	char position[100];	//ְ��
	char education[100];//ѧ�� 
	char politics[100];	//������ò 
	int year;			//��Ժʱ�� 
	int month;
	int day;
	int time; 			//����ʱ�� 
}People;

void add(People *pe,int N)
{
	printf("���������:");
	gets(pe[N].name);
	printf("�������Ա�:") ;
	scanf("%c",pe->sex);
	printf("����������:");
	scanf("%d",&pe[N].age);
	getchar();
	printf("������ְ������:");
	gets(pe[N].type);
	printf("������ְ��:");
	gets(pe[N].post);
	printf("������ְ��:");
	gets(pe[N].position);
	printf("������ѧ��:");
	gets(pe[N].education);
	printf("������������ò:");
	gets(pe[N].politics);
	printf("��������Ժʱ��(year-month-day):");
	scanf("%d-%d-%d",pe[N].year,pe[N].month,pe[N].day);
	printf("�����빤��ʱ��:");
	printf("%d",pe[N].time);
}
void change(People *pe)
{
	char a[20];
	int peace=0,i;
	printf("����Ҫ�ı���Ϣ��������");
	gets(a);
	peace=1;
	for(i=0;i<N && peace;i++)
	{
		if(strcmp(a,pe[i].name)==0)
			peace=0;
	}printf("�������������:");
	gets(pe[i].name);
	printf("�����������Ա�:") ;
	scanf("%c",pe->sex);
	printf("��������������:");
	scanf("%d",&pe[i].age);
	getchar();
	printf("����������ְ������:");
	gets(pe[i].type);
	printf("����������ְ��:");
	gets(pe[i].post);
	printf("����������ְ��:");
	gets(pe[i].position);
	printf("����������ѧ��:");
	gets(pe[i].education);
	printf("����������������ò:");
	gets(pe[i].politics);
	printf("������������Ժʱ��(year-month-day):");
	scanf("%d-%d-%d",pe[i].year,pe[i].month,pe[i].day);
	printf("���������빤��ʱ��:");
	printf("%d",pe[i].time);
}
void dele(People *pe)
{
	char a[20];
	int peace=0,i;
	printf("����Ҫ�ı���Ϣ��������");
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
		printf(" 		1.��ӡ�\n");
		printf("		2.�ı䡣\n");
		printf("		3.ɾ����\n");
		printf("		4.�鿴\n");
		printf("		5.�����ļ�\n");
		printf("		6.�˳�\n");
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
