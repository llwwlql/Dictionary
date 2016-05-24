#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef char Car[10];
typedef struct
{
    Car *elem;
    int length;
}LinkList;

void Iuput(LinkList &L)
{
    printf("请输入待排序车辆的数目:\n");
    scanf("%d",&L.length);
	L.elem=(Car*)malloc(L.length*sizeof(Car));
    printf("请依次输入车辆的车牌号:\n");
    for(int i=0;i<L.length;i++)
        scanf("%s",L.elem[i]);
}

void BubbleSort(LinkList &L)
{//对车牌号进行排序
	char a[20];
	int i,j;
	int flag=1;
	for(i=0;i<L.length-1 && flag;i++)
	{
		flag=0;
		for(j=0;j<L.length-i-1;j++)
			if(strcmp(L.elem[j],L.elem[j+1])>0)
			{
				strcpy(a,L.elem[j]);
				strcpy(L.elem[j],L.elem[j+1]);
				strcpy(L.elem[j+1],a);
				flag=1;
			}
	}
}

void Binsrch(LinkList &L,char *a)
{//利用折半查找查找车牌号是否存在
	int low,high,mid;
	int flag=1;
	low=0;
	high=L.length-1;
	while(low<=high&&flag)
	{
	    mid=(low+high)/2;
		if(strcmp(a,L.elem[mid])==0)
		{
			printf("查找的该车牌号是第%d个。\n",mid+1);
			flag=0;
		}
		else if(strcmp(a,L.elem[mid])>0)
		{
			low=mid+1;
			mid=(low+high)/2;
		}
		else
		{
			high=mid-1;
			mid=(low+high)/2;
		}
	}
	if(flag)
		printf("查找的车牌号不存在。\n");
}

void Output(LinkList &L)
{
    int i;
    for(i=0;i<L.length;i++)
      printf("%s\n",L.elem[i]);
}

int main()
{
    LinkList L;
	char car[20];
    Iuput(L);
    BubbleSort(L);
	printf("输出排好序的车牌号:\n");
	Output(L);
	printf("输入要查找的车牌号:\n");
	getchar();
	gets(car);
	Binsrch(L,car);
	return 0;
}
