#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct list{
	int data;
	struct list *next;
}*List,ListNode;

void createList(List &L)
{
	int i,n;
	L=(List)malloc(sizeof(ListNode));
	List s,p;
	p=L;
	p->next=NULL;
	printf("请输入生成数字个数：");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s=(List)malloc(sizeof(ListNode));
		s->data=rand()%89+10;
		s->next=NULL;
		p->next=s;
		p=p->next;
		printf("%d ",p->data);
	}
	p->next=L;
	putchar('\n');
}

void insertList(List &L1,List &L2)
{
	int n,i;
	printf("请输入把链表2插入到链表1的第几个数字前面：");
	scanf("%d",&n);
	List p,cur;
	p=L1;
	i=1;
	while(i<n)
	{
		i++;
		if(p->next==L1)
			p=L1->next;
		else
			p=p->next;
	}
	cur=p->next;
	p=L2->next;
	while(p->next!=L2)	
		p=p->next;
	
	p->next=cur;
	//free(L2);
	p=L1->next;
	while(p->next!=L1)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

int main()
{
	srand(time(0));
	List RL1,RL2;
	createList(RL1);
	createList(RL2);
	insertList(RL1,RL2);
	return 0;
}