#include <stdio.h>
#include <stdlib.h> 
#define Length 100
#define AddLength 50
//��ɱ�Ľ��������룬ɾ�����������٣����� 
typedef struct {
	int *elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList &L)
{//����һ�����Ա� 
	int n;
	int i,j;
	L.elem=(int *)malloc(Length*sizeof(int));
	if(!L.elem)
		exit(0);
	L.listsize=Length;
	printf("���������ָ���:");
	scanf("%d",&n);
	printf("����������:");
	for(i=0;i<=n-1;i++)
		scanf("%d",&L.elem[i]);
	L.length=n;
	printf("\n�����ɹ�.\n");
}

void SortList(SqList &L)
{//��ɱ������
	int i,j,temp;
	for(i=0;i<L.length-1;i++)
	{
		for(j=i+1;j<L.length;j++)
		{
			if(L.elem[i]<L.elem[j])
			{
				temp=L.elem[i];
				L.elem[i]=L.elem[j];
				L.elem[j]=temp;
			}
		}
	}
}

void AddList(SqList &L,int i,int &e)
{//���e�ŵ���i��λ��ǰ�� 
	int j;
	if(i<=0 && i>L.length+1)
	{
		printf("����λ�ô���\n");
		return ;
	}
	if(L.length+1>L.listsize)
	{
		realloc(L.elem,L.length+AddLength);
		L.listsize=L.length+AddLength;
	}
	for(j=L.length;j>=i;j--)
		L.elem[j]=L.elem[j-1];
	L.elem[i-1]=e;
	L.length++;
	printf("����ɹ�.\n");
}

void DeleteList(SqList &L,int i,int &e)
{//ɾ����i�����ݣ����ظ�e 
	e=L.elem[i-1];
	for(int j=i-1;j<L.length-1;j++)
		L.elem[j]=L.elem[j+1];
	L.length--;
}

void DestoryList(SqList &L)
{
	free(L.elem);
	L.length=0;
	L.listsize=0;
}

int SearchList(SqList L,int e)
{//��������e�ڱ��е�λ�� 
	int i;
	for(i=0;i<L.length;i++)
		if(L.elem[i]==e)
			return i+1;
	return 0;
	
}

void DisplayList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	putchar('\n');
}

int main()
{
	int n,i,e;
	SqList L;
	while(1)
	{
		printf("			1������һ�����Ա�\n");
		printf("			2����������\n");
		printf("			3��ɾ������\n");
		printf("			4������������\n");
		printf("			5���������ݵ�λ��\n");
		printf("			6����ʾ����\n");
		printf("			7���������Ա�\n");
		printf("			8���˳�\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				InitList(L);
				break;
			case 2:
				printf("�����������ݺ�λ��:");
				scanf("%d %d",&e,&i);
				AddList(L,i,e);
				break;
			case 3:
				printf("����ɾ�����ݵ�λ��:");
				scanf("%d",&i);
				DeleteList(L,i,e);
				printf("ɾ��������Ϊ%d\n",e);
				break;
			case 4:
				SortList(L);
				break;
			case 5:
				printf("����Ҫ���ҵ�����:");
				scanf("%d",&e);
				i=SearchList(L,e);
				if(i==0)
					printf("δ���ҵ���\n");
				else
					printf("%d�ڵ�%d��λ��\n",e,i);
				break;
			case 6:
				DisplayList(L);
				break;
			case 7:
				printf("��������\n");
				break;
			case 8:
				return 0;
		}
	}
	
	return 0;
}
