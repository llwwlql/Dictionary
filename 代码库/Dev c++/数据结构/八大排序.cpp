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
	printf("请输入学生人数:");
	scanf("%d",&n);

	printf("请输入学生信息(学号，姓名，成绩)：\n");
	for(i=1;i<=n;i++)
	{
		scanf("%s %s %d",num,name,&score);
		fprintf(fp,"%s %s %d\n",num,name,score);
	}
	printf("登录成功.\n");
	fclose(fp);
}

void ReadFile(Stu &stu)
{//读文件，存到Stu结构体中 
	FILE *fp;
	int i;

	fp=fopen("E:\\Student.txt","r");
	for(i=1;i<=n;i++)
		fscanf(fp,"%s %s %d",stu[i].num,stu[i].name,&stu[i].score);

	fclose(fp);
}

void Display(Stu stu)
{
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
	temp.score=a.score;
	strcpy(temp.name,a.name);
	strcpy(temp.num,a.num);
	
	a.score=b.score;
	strcpy(a.name,b.name);
	strcpy(a.num,b.num);
	
	b.score=temp.score;
	strcpy(b.name,temp.name);
	strcpy(b.num,temp.num);
	
}

void InsertSort(Stu stu)
{//直接插入排序
	int i,j;
	int key;
	char name[20];
	char num[20];
	StuNode temp;
	stu=(Stu)malloc(sizeof(StuNode)*(n+1));
	ReadFile(stu);
	
	for(i=n;i>=1;i--)
	{
		Swap(temp,stu[i]);
		j=i-1;
		while(j>=1 && temp.score> stu[j].score)
		{
			Swap(stu[j],stu[j+1]);
			j--;
		}
		j+=1;
		Swap(stu[j],temp);
	}
	Display(stu);
}

void BubbleSort(Stu stu)
{
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
{
	int Pi;
	strcpy(stu[0].name,stu[low].name);
	strcpy(stu[0].num,stu[low].num);
	stu[0].score=stu[low].score;
	
	Pi=stu[0].score;
	while(low<high)
	{
		while(low<high && stu[high].score<=Pi)
			high--;
		Swap(stu[high],stu[low]);
		while(low<high && stu[low].score>=Pi)
			low++;
		Swap(stu[low],stu[high]);
	}
	Swap(stu[low],stu[0]);
	return low;
}

void QuickSort(Stu stu,int low,int high)
{
	int Pi;
	if(low<high)
	{
		Pi=Partition(stu,low,high);
		QuickSort(stu,low,Pi-1);
		QuickSort(stu,Pi+1,high);
	}
}

void SeletionSort(Stu stu)
{
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
{
	int i,j;
	StuNode rc;
	strcpy(rc.name,stu[s].name);
	strcpy(rc.num,stu[s].num);
	rc.score=stu[s].score;
	
	for(j=2*s;j<=m;j*=2)
	{
		if(j<m && stu[j].score>stu[j+1].score)
			j++;
		if(!(rc.score>stu[j].score))
			break;
		strcpy(stu[s].name,stu[i].name);
		strcpy(stu[s].num,stu[i].num);
		stu[s].score=stu[i].score;
			s=j;
	}
	strcpy(stu[s].name,rc.name);
	strcpy(stu[s].num,rc.num);
	stu[s].score=rc.score;
}

void HeapSort(Stu stu)
{
	int i;
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
{
	int i,j,k;
	StuNode temp[1005];
	i=low;j=mid+1;k=0;
	while(i<=mid && j<=high)
	{
		if(stu[i].score<stu[j].score)
			Swap(temp[k++],stu[i++]);
		else
			Swap(temp[k++],stu[j++]);
	}
	while(i<=low)
		Swap(temp[k++],stu[i++]);
	while(j<=high)
		Swap(temp[k++],stu[j++]);
	for(i=low;i<=high;i++)
		Swap(stu[i],temp[i-low]);
}

void MergeSort(Stu stu,int low,int high)
{
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
		printf("	1.录入学生基本信息。\n");
		printf("	2.直接插入排序。\n");
		printf("	3.冒泡排序。\n");
		printf("	4.快速排序。\n"); 
		printf("	5.简单选择排序。\n");
		printf("	6.堆排序。\n");
		printf("	7.2-路归并排序。\n");
		printf("	8.输出学生信息。\n");
		printf("	9.退出。\n");
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
				stu=(Stu)malloc(sizeof(StuNode)*(n+1));
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
				MergeSort(stu,1,n);
				stu=(Stu)malloc(sizeof(StuNode)*(n+1));
				ReadFile(stu);
				Display(stu);
				break;
			case 8:
				Display(stu);
				break;
			default:
				return 0;
		}
	}
}
