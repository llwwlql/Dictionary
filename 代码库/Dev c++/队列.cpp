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
	printf("Ҫ�������ݸ���(С��20):");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&date);
		InQueue(q,date);
	}
	while(peace)
	{
		printf("		1�����\n");
		printf("		2������\n");
		printf("		3���˳�\n"); 
		printf("		����Ҫִ�е�ָ��:");
		scanf("%d",&n)
		switch(n)
		{
			case 1:
				printf("����������:");
				scanf("%d",&date);
				InQueue(q,date);
				break;
		}
	}
	
	return 0;
}
