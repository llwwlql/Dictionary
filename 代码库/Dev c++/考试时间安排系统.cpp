#include <stdio.h>
#include <string.h>
int N;
typedef struct{
	int month,day;
	char place[100];
	char subject[100];
}Exam;
void add(Exam *exam,int i)					//ָ�� 
{// ��ӿ��԰���
	printf("�������Ŀ:");
	scanf("%s",exam[i].subject);
	printf("�����뿼��ʱ��(��-��)��"); 
	scanf("%d-%d",&exam[i].month,&exam[i].day);
	printf("�����뿼�Եص㣺");
	scanf("%s",exam[i].place);
}
void change(Exam *exam)
{// �ı俼�԰���
	char ch[100];
	int i; 
	printf("������Ҫ�ı�Ŀ��Կ�Ŀ:");
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
{// �Կ��԰��Ű�����ʱ������
	int i,j;
	Exam temp;
	for(i=0;i<N;i++)			//ѭ����� ��ð������
	{
		for(j=i+1;j<N;j++)
		{
			if(exam[i].month>exam[j].month)			//if�ж���� ���жϣ������� 
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
{//�鿴���԰���
	int i;
	printf("��Ŀ	ʱ��	�ص�\n");
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
	printf("�������ļ���:");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)	//	����һ�����ļ�
	{
		printf("�޷��򿪴��ļ�\n");
		return ; 
	}
	fprintf(fp,"��Ŀ	ʱ��	�ص�\n");
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
		printf(" 		1.��ӿ��԰��š�\n");
		printf("		2.�ı俼�԰��š�\n");
		printf("		3.�Կ��԰��Ű�����ʱ������\n");
		printf("		4.�鿴���԰���\n");
		printf("		5.�����ļ�\n");
		printf("		6.�˳�\n");
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
