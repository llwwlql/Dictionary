#include <stdio.h>
typedef struct{
	int *head,*tail;
	int lenth;
}Queue;
Queue Q;

void InQueue(int *q,int date)
{
	queue[Q.tail]=date;
	if(Q.tail==Q.lenth)
		Q.tail=queue;
	else
		Q.tail++;
}

void DeQueue(int *q)
{
	if(Q.head==Q.lenth)
		Q.head=queue;
	else
		Q.head++;
}

int main()
{

	int queue[20];
	int n,date;
	Q.head=Q.tail=queue;
	Q.lenth=queue[19];
	printf("要输入数据个数(小于20):");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&date);
		InQueue(q,date);
	}
	while(peace)
	{
		printf("		1、入队\n");
		printf("		2、出队\n");
		printf("		3、退出\n"); 
		printf("		输入要执行的指令:");
		scanf("%d",&n)
		switch(n)
		{
			case 1:
				printf("请输入数据:");
				scanf("%d",&date);
				InQueue(q,date);
				break;
		}
	}
	
	return 0;
}
