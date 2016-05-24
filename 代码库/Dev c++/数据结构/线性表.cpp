#include <stdio.h>
#include <stdlib.h> 
#define Length 100
#define AddLength 50
//完成表的建立，插入，删除，排序，销毁，查找 
typedef struct {
	int *elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList &L)
{//构建一个线性表 
	int n;
	int i,j;
	L.elem=(int *)malloc(Length*sizeof(int));
	if(!L.elem)
		exit(0);
	L.listsize=Length;
	printf("请输入数字个数:");
	scanf("%d",&n);
	printf("请输入数据:");
	for(i=0;i<=n-1;i++)
		scanf("%d",&L.elem[i]);
	L.length=n;
	printf("\n创建成功.\n");
}

void SortList(SqList &L)
{//完成表的排序
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
{//添加e放到第i个位置前面 
	int j;
	if(i<=0 && i>L.length+1)
	{
		printf("插入位置错误\n");
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
	printf("插入成功.\n");
}

void DeleteList(SqList &L,int i,int &e)
{//删除第i个数据，返回给e 
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
{//查找数据e在表中的位置 
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
		printf("			1、建立一个线性表\n");
		printf("			2、插入数据\n");
		printf("			3、删除数据\n");
		printf("			4、对数据排序\n");
		printf("			5、查找数据的位置\n");
		printf("			6、显示数据\n");
		printf("			7、销毁线性表\n");
		printf("			8、退出\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				InitList(L);
				break;
			case 2:
				printf("输入插入的数据和位置:");
				scanf("%d %d",&e,&i);
				AddList(L,i,e);
				break;
			case 3:
				printf("输入删除数据的位置:");
				scanf("%d",&i);
				DeleteList(L,i,e);
				printf("删除的数据为%d\n",e);
				break;
			case 4:
				SortList(L);
				break;
			case 5:
				printf("输入要查找的数据:");
				scanf("%d",&e);
				i=SearchList(L,e);
				if(i==0)
					printf("未查找到。\n");
				else
					printf("%d在第%d个位置\n",e,i);
				break;
			case 6:
				DisplayList(L);
				break;
			case 7:
				printf("销毁数据\n");
				break;
			case 8:
				return 0;
		}
	}
	
	return 0;
}
