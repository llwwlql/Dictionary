#include <stdio.h>
typedef struct Hash{
	int *elem;
	int count;
	int sizeindex;
}HushTable;

int HushCount(int n)
{
	int i,j;
	for(i=1;;i++)
	{
		j=4*i+3;
		if(j>n)
			return j;
	}
}

int Hush(HushTable H,int number)
{//Hush���� 
	int j;
	j=number%
}

void InsertHash(HashTable H,int temp)
{
	int c=0;
	if(Search(H,temp))
		return ;
	else if(c<)
}

void InitHushTable(HushTable H)
{//����һ��Hush�� 
	int n,i;
	printf("Please input numbers count:");
	scanf("%d",&n);
	H.sizeindex=HushCount(n);
	H.count=0;
	H.elem=(HushTable *)malloc(sizeof(int)*H.sizeindex);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		InsertHash(H,temp);
		H.count++;
	}
	printf("����ɹ���\n");
}


int main()
{
	int key;
	HushTable H;
	while(1)
	{
		printf("	----------------------\n");
		printf("	1.�������ݡ�\n");
		printf("	2.���ݲ��ҡ�\n");
		printf("	3.������ӡ�\n");
		printf("	4.�˳���\n");
		printf("	----------------------\n");
		scanf("%d",&key);
				
		switch(key)
		{
			case 1:
				InitHushTable(H);
				break;
			case 2:
				SearchHash(H);
				break;
			case 3:
				InsertHash(H);
				break;
			default:
				return 0;
		}
	}
	
	return 0;
}
