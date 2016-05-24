#include <stdio.h>
#include <stdlib.h>
#define Length 10
#define AddLength 10;
typedef struct {
	int *elem;
	int length;
	int listsize;
}SqList;
void InitList(SqList &L)
{
	int n;
	L.elem=(int *)malloc(Length*sizeof(int));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",L.elem+i);
	L.length=n;
	L.listsize=Length;
}

void SearchList(SqList L,int i,int e)
{
	for(j=0;j<n;j++)
	{
		if(a[j]=e)
		{
			i=j+1;
			return ;
		}
	}
}

void ListInsert(SqList &L,int i,int e)
{//把e插到第i个数的前面
	if(L.length+1>=L.listsize)
		L.elem=realloc(L.elem,L.listsize+AddLength);
	for(int j=L.length;j>=i-1;j++)
		L.elem[j]=L.elem[j-1];
	
}

int main()
{
	SqList L;
	InitList(L);
	
	return 0;
}
