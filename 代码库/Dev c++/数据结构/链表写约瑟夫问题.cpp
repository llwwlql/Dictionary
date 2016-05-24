//链表实现约瑟夫问题 
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
int n;
void InitLink(LinkList &L)
{//建立一个循环链表 
	L=(LinkList)malloc(sizeof(LNode));
	LinkList p,cur;
	L->next=NULL;
	cur=L;
	printf("输入人数：");
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		p->data=i;
		cur->next=p;
		cur=cur->next;
	}
	cur->next=L;
}

void Joseph(LinkList &L)
{
	int i,index,e;
	LinkList cur,s;
	cur=L->next;
	index=1;
	for(i=1;i<=n-1;i++)
	{
		if((index+1)%3==0)
		{
			if(cur->next!=L)
				s=cur->next;
			else
				s=cur->next->next;
			if(s->next!=L)
				cur=s->next;
			else
				cur=L->next;
			free(s);
			index=1;
		}
		else
		{
			if(cur->next!=L)
				cur=cur->next;
			else
				cur=L->next;
			index++;
		}
	}
	e=L->next->data;
	printf("%d\n",e);
}

int main()
{
	LinkList L;
	InitLink(L);
	
	Joseph(L); 
	
	//printf("最后剩下的是第%d个人\n",L->next->data); 
	
	return 0;
}
