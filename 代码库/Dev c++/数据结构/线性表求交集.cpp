#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int *elem;
	int length;
	int Sizelength;
}SqList;

void InitList(SqList &L)
{
	int i,n;
	L.elem=(int *)malloc(100*sizeof(int ));
	L.Sizelength=100;
	printf("�������ݸ�����");
	scanf("%d",&n);
	printf("���������ݣ�");
	for(i=0;i<n;i++)
		scanf("%d",&L.elem[i]);
	L.length=n;
}

void Insert(SqList L,SqList K)
{
	int i,j;
	SqList M;
	M.elem=(int *)malloc(sizeof(int)*100);
	M.length=0;
	for(i=0;i<L.length;i++)
	{
		for(j=0;j<K.length;j++)
		{
			if(L.elem[i]==K.elem[j])
			{
				M.elem[M.length++]=L.elem[i];
				break;
			}
			
		}
	}
	printf("�������Ա�Ľ���Ϊ:");
	for(i=0;i<M.length;i++)
		printf("%d ",M.elem[i]);
	
}

int main()
{
	int i;
	SqList L,K;
	printf("��һ�����Ա�\n"); 
	InitList(L);
	printf("�ڶ������Ա�\n"); 
	InitList(K);
	
	Insert(L,K);
	
	return 0;
}
