//����Ľ��������룬ɾ�� ���ϲ�����
#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
	int data;
	struct Link *next;
}LNode,*LinkList;

void Create_Link(LinkList &L)
{//����Ľ��� 
	LinkList p,cur;
	L=(LinkList)malloc(sizeof(LNode));
	int n;
	cur=L;
	printf("���ݸ�����"); 
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
{//����ı��� 
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
{//���뵽��i������ 
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
		printf("����λ�ò��Ϸ�.\n");
		return ;
	}
	
	LinkList p=(LinkList)malloc(sizeof(LNode));
	p->data=e;
	p->next=cur->next;
	cur->next=p;
}

void Delete_Link(LinkList &L,int i)
{//ɾ����i��λ�õ���������e������
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
		printf("����λ�ò��Ϸ�.\n");
		return ; 
	}
	
	s=cur->next;
	cur->next=s->next;
	printf("ɾ������Ϊ:%d\n",s->data);
	free(s);
}

void Destroy(LinkList L)
{//���� 
	LinkList cur,p;
	cur=L->next;
	
	while(cur)
	{
		p=cur;
		cur=cur->next;
		free(p);
	}
	
	printf("��������.\n");
}

void Merge(LinkList L,LinkList M,LinkList &K)
{//��������ϲ���ͷ��
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
	
	printf("��������λ�ú�����:");
	scanf("%d %d",&i,&e);
	Insert_Link(K,i,e);
	Display_Link(K);
	printf("����Ҫɾ�����ݵ�λ��:");
	scanf("%d",&i);
	Delete_Link(K,i);
	Destroy(K);
	
	return 0;
}
