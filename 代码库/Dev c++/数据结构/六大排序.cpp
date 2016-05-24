#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
typedef struct student{
	char num[20];
	char name[25];
	int score;	
}*Stu,StuNode;

void Build(Stu stu)
{
	FILE *fp;
	char name[20];
	int score,i;
	char num[20];
	fp=fopen("E:\\Student.txt","w");
	printf("������ѧ������:");
	scanf("%d",&n);

	printf("������ѧ����Ϣ(ѧ�ţ��������ɼ�)��\n");
	for(i=1;i<=n;i++)
	{
		scanf("%s %s %d",num,name,&score);
		fprintf(fp,"%s %s %d\n",num,name,score);
	}
	printf("��¼�ɹ�.\n");
	fclose(fp);
}
void ReadFile(Stu &stu)
{//���ļ����浽Stu�ṹ���� 
	FILE *fp;
	int i;
	stu=(Stu)malloc(sizeof(StuNode)*(n+1));
	fp=fopen("E:\\Student.txt","r");
	for(i=1;i<=n;i++)
		fscanf(fp,"%s %s %d",stu[i].num,stu[i].name,&stu[i].score);

	fclose(fp);
}

void Display(Stu stu)
{//��ʾ���� 
	int i;
	int temp=1,index=0;
	for(i=1;i<=n;i++)
	{
		printf("%2d %15s %15s %5d\n",temp,stu[i].num,stu[i].name,stu[i].score);
		if(i<n && stu[i].score==stu[i+1].score)
			index++;		
		else
		{
			temp+=index+1;
			index=0;
		}
	}
	
	free(stu);
}

void Swap(StuNode &a,StuNode &b)
{
	StuNode temp;
	temp=a;
	a=b;
	b=temp;
}

void InsertSort(Stu stu)
{//ֱ�Ӳ�������
	int i,j;
	int key;
	char name[20];
	char num[20];
	StuNode temp;
	stu=(Stu)malloc(sizeof(StuNode)*(n+1));
	ReadFile(stu);
	
	for(i=n;i>=1;i--)
	{
		temp=stu[i];
		j=i-1;
		while(j>=1 && temp.score> stu[j].score)
		{
			stu[j+1]=stu[j];
			j--;
		}
		j+=1;
		stu[j]=temp;
	}
	Display(stu);
}

void BubbleSort(Stu stu)
{//ð������ 
	int i,j,peace;
	stu=(Stu)malloc(sizeof(StuNode)*(n+1));
	ReadFile(stu);
	peace=1;
	for(i=1;i<=n-1 && peace;i++)
	{
		peace=0;
		for(j=1;j<=n-j;j++)
		{
			if(stu[j].score < stu[j+1].score)
			{
				Swap(stu[j],stu[j+1]);
				peace=1;
			}
		}
	}
	Display(stu);
}
int Partition(Stu stu,int low,int high)
{//��������--���� 
	int Pi;
	stu[0]=stu[low];
	
	Pi=stu[0].score;
	while(low<high)
	{
		while(low<high && stu[high].score<=Pi)
			high--;
		stu[low]=stu[high];
		while(low<high && stu[low].score>=Pi)
			low++;
		stu[high]=stu[low];
	}
	stu[low]=stu[0];
	return low;
}
void QuickSort(Stu stu,int low,int high)
{//��������--���� 
	int Pi;
	if(low<high)
	{
		Pi=Partition(stu,low,high);
		QuickSort(stu,low,Pi-1);
		QuickSort(stu,Pi+1,high);
	}
}
void SeletionSort(Stu stu)
{//ѡ������ 
	int i,j,temp;
	stu=(Stu)malloc(sizeof(StuNode)*(n+1));
	ReadFile(stu);
	for(i=1;i<=n-1;i++)
	{
		int key=stu[i].score;
		for(j=i+1;j<=n;j++)
		{
			if(key<stu[j].score)
			{
				temp=j;
				key=stu[j].score;
			}
		}
		if(i!=j)
			Swap(stu[i],stu[temp]);
	}
	Display(stu);
}
void HeapAdjust(Stu stu,int s,int m)
{//������ 
	int j;
	StuNode rc;
	rc=stu[s];
	
	for(j=2*s;j<=m;j*=2)
	{
		if(j<m && stu[j].score>stu[j+1].score)
			j++;
		if(!(rc.score>stu[j].score))
			break;
		stu[s]=stu[j];
			s=j;
	}
	stu[s]=rc;
}
void HeapSort(Stu stu)
{//������ 
	int i;
	ReadFile(stu);
	for(i=n/2;i>0;i--)
		HeapAdjust(stu,i,n);
	for(i=n;i>1;i--)
	{
		Swap(stu[1],stu[i]);
		HeapAdjust(stu,1,i-1);
	}
	Display(stu);
}

void Merge(Stu stu,int low,int mid,int high)
{//�鲢����--�鲢 
	if(low>=high)
		return ;
	int i,j,k;
	StuNode temp[1005];
	i=low;j=mid+1;k=0;
	while(i<=mid && j<=high)
	{
		if(stu[i].score>stu[j].score)
			temp[k++]=stu[i++];
		else
			temp[k++]=stu[j++];
	}
	while(i<=mid)
		temp[k++]=stu[i++];
	while(j<=high)
		temp[k++]=stu[j++];
	for(i=low;i<=high;i++)
	{
		stu[i]=temp[i-low];
		printf("%d ",stu[i].score);
	}
	putchar('\n');
	
}

void MergeSort(Stu stu,int low,int high)
{//�鲢����--���� 
	if(low>=high)
		return ;
	int mid=(low+high)/2;
	MergeSort(stu,low,mid);
	MergeSort(stu,mid+1,high);
	Merge(stu,low,mid,high);
}

int main()
{
	Stu stu;
	int key;
	while(1)
	{
		printf("	----------------------\n");
		printf("	1.¼��ѧ��������Ϣ��\n");
		printf("	2.ֱ�Ӳ�������\n");
		printf("	3.ð������\n");
		printf("	4.��������\n"); 
		printf("	5.��ѡ������\n");
		printf("	6.������\n");
		printf("	7.2-·�鲢����\n");
		printf("	8.���ѧ����Ϣ��\n");
		printf("	9.�˳���\n");
		printf("	----------------------\n");
		scanf("%d",&key);
				
		switch(key)
		{
			case 1:
				Build(stu);
				break;
			case 2:
				InsertSort(stu);
				break;
			case 3:
				BubbleSort(stu);
				break;
			case 4:
				ReadFile(stu);
				QuickSort(stu,1,n);
				Display(stu);
				break;
			case 5:
				SeletionSort(stu);
				break;
			case 6:
				HeapSort(stu);
				break;
			case 7:
				ReadFile(stu);
				MergeSort(stu,1,n);
				Display(stu);
				break;
			case 8:
				ReadFile(stu);
				Display(stu);
				break;
			default:
				return 0;
		}
	}
}

