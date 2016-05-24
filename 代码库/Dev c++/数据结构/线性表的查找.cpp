#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct table{
	int *elem;
	int length;
}SSTable;

typedef struct search{
	int key;
	int first;
}Search;

void InitTable(SSTable &ST)
{//�������ұ� 
	int i,j,n;
	srand(time(0));
	printf("����������������ĸ���:");
	scanf("%d",&n);
	
	ST.elem=(int *)malloc(sizeof(int)*(n+1));

	for(i=1;i<=n;i++)
		ST.elem[i]=rand()%90+10;
	ST.length=n;
}

int _Search(SSTable ST,int key)
{//˳����� 
	int n,i,j;
	ST.elem[0]=key;
	for(i=ST.length;ST.elem[i]!=key;i--);
	return i;
}

void Display(SSTable ST)
{//��ʾ����Ļ�� 
	int i;
	for(i=1;i<=ST.length;i++)
		printf("%d ",ST.elem[i]);
	putchar('\n');
}

void Sort(SSTable &ST,int k)
{//��С�������� 
	int i,j;
	int temp;
	for(i=k;i<ST.length;i++)
	{
		for(j=i+1;j<=ST.length;j++)
		{
			if(ST.elem[i]>ST.elem[j])
			{
				temp=ST.elem[i];
				ST.elem[i]=ST.elem[j];
				ST.elem[j]=temp;
			}
		}
	}
	
}
int Search_Bin(SSTable ST,int key)
{//���ֲ���
	int i,j;
	int left=1,right=ST.length;
	int mid=(left+right)/2;
	
	while(left<=right)
	{
		if(ST.elem[mid]==key)
			return mid;
		if(ST.elem[mid]<key)
		{
			left=mid+1;
			mid=(left+right)/2;
		}
		if(ST.elem[mid]>key)
		{
			right=mid-1;
			mid=(left+right)/2;
		}
	}
	return 0;
}

int Block_Search(SSTable &ST)
{//�ֿ���� 
	Search S[10];
	int i,j,n,m,index,key,temp;
	
	
	printf("������ֶ��ٿ�:");
	scanf("%d",&index);
	
	
	for(i=0;i<index;i++)
	{
		S[i].key=0;
		S[i].first=0;
	}
	
	
	m=ST.length/index;
	
	if(ST.length%index)
		m++;
	

	printf("��������%d����:",ST.length);
	
	for(i=1;i<=ST.length;i++)
	{
		temp=(i-1)/m;
		if(!S[temp].first)
			S[temp].first=i;
		scanf("%d",&ST.elem[i]);
		if(S[temp].key<ST.elem[i])
			S[temp].key=ST.elem[i];
	}
	
	
	
	printf("������Ҫ���ҵ���:");
	scanf("%d",&key);
	
	S[(ST.length-1)/m+1].first=ST.length+1;
	
	for(i=0;i<index;i++)
	{
		if(key<=S[i].key)
			break;
	}
	
	if(i<index)
	{
		for(j=S[i].first;j<S[i+1].first;j++)
		{
			if(ST.elem[j]==key)
				return j;
		}
	}
	return 0;
}


int main()
{
	SSTable ST;
	int i,j,n,key;

	InitTable(ST);
	
	Display(ST);
	
	printf("������Ҫ���ҵ���:");
	scanf("%d",&key);
	j=_Search(ST,key);		//˳����� 
	printf("�������ڱ��е�λ��Ϊ(0Ϊδ���ҵ�):%d\n",j);
	
	Sort(ST,1);
	Display(ST);
	//������ʾ 
	printf("������Ҫ���ҵ���:");
	scanf("%d",&key);
	
	j=Search_Bin(ST,key);	//���ֲ���
	printf("�������ڱ��е�λ��Ϊ(0Ϊδ���ҵ�):%d\n",j);


	j=Block_Search(ST);	//�ֿ����
	printf("�������ڱ��е�λ��Ϊ(0Ϊδ���ҵ�):%d\n",j);
	
	
	return 0;
}
