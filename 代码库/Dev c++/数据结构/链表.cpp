//链表的建立，插入，删除 ，合并链表；
#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
	int data;
	struct Link *next;
}LNode,*LinkList;

void Create_Link(LinkList &L)
{//链表的建立 
	LinkList p,cur;
	L=(LinkList)malloc(sizeof(LNode));
	int n;
	cur=L;
	printf("数据个数："); 
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		cur->next=p;
		cur=p;
	}
	cur->next=NULL;
}

void Display_Link(LinkList L)
{//链表的遍历 
	LinkList cur;
	cur=L->next;
	while(cur)
	{
		printf("%d ",cur->data);
		cur=cur->next;
	}
	putchar('\n');
}

void Insert_Link(LinkList &L,int i,int e)
{//插入到第i个后面 
	int j=1;
	LinkList cur;
	cur=L->next;
	while(j<=i-2 && cur)
	{
		cur=cur->next;
		j++;
	}
	
	if(j!=i-1)
	{
		printf("输入位置不合法.\n");
		return ;
	}
	
	LinkList p=(LinkList)malloc(sizeof(LNode));
	p->data=e;
	p->next=cur->next;
	cur->next=p;
}

void Delete_Link(LinkList &L,int i)
{//删除第i个位置的数，并用e来返回
	LinkList s;
	LinkList cur;
	int j=1;
	cur=L->next;
	while(j<=i-2 && cur->next)
	{
		cur=cur->next;
		j++;
	}
	
	if(j!=i-1)
	{
		printf("输入位置不合法.\n");
		return ; 
	}
	
	s=cur->next;
	cur->next=s->next;
	printf("删除的数为:%d\n",s->data);
	free(s);
}

void Destroy(LinkList L)
{//销毁 
	LinkList cur,p;
	cur=L->next;
	
	while(cur)
	{
		p=cur;
		cur=cur->next;
		free(p);
	}
	
	printf("操作结束.\n");
}

void Merge(LinkList L,LinkList M,LinkList &K)
{//两个链表合并，头插
	LinkList cur1,cur2,temp;
	K=(LinkList)malloc(sizeof(LNode));
	K->next=NULL;
	cur1=L->next;
	cur2=M->next;
	
	while(cur1 && cur2)
	{
		if(cur1->data<cur2->data)
		{
			temp=cur1->next;
			cur1->next=K->next;
			K->next=cur1;
			cur1=temp;
		}
		else
		{
			temp=cur2->next;
			cur2->next=K->next;
			K->next=cur2;
			cur2=temp;
		}
	}
	
	while(cur1)
	{
		temp=cur1->next;
		cur1->next=K->next;
		K->next=cur1;
		cur1=temp;		
	}
	while(cur2)
	{
		temp=cur2->next;
		cur2->next=K->next;
		K->next=cur2;
		cur2=temp;
	}
}
int main()
{
	int i,e;
	LinkList L,M,K;
	Create_Link(L);
	Display_Link(L);
	Create_Link(M);
	Display_Link(M);
	Merge(L,M,K);
	Display_Link(K);
	
	printf("输入插入的位置和数据:");
	scanf("%d %d",&i,&e);
	Insert_Link(K,i,e);
	Display_Link(K);
	printf("输入要删除数据的位置:");
	scanf("%d",&i);
	Delete_Link(K,i);
	Destroy(K);
	
	return 0;
}
