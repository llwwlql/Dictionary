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
{//Hush函数 
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
{//建立一个Hush表 
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
	printf("输入成功！\n");
}


int main()
{
	int key;
	HushTable H;
	while(1)
	{
		printf("	----------------------\n");
		printf("	1.输入数据。\n");
		printf("	2.数据查找。\n");
		printf("	3.数据添加。\n");
		printf("	4.退出。\n");
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
