#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;	
}LNode,*LinkList;
int n; 
void Build(LinkList &L)
{//建立，用头指针指向第一个结点
	LinkList p,cur;
	int i;
	printf("请输入人数:");
	scanf("%d",&n);
	p=(LinkList)malloc(sizeof(LNode));
	L=p;
	p->data=1;
	cur=p;
	for(i=2;i<=n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		p->data=i;
		cur->next=p;
		cur=cur->next;
	}
	cur->next=L;
}
void Delete(LinkList &cur)
{//删除结点操作
	LinkList S;
	S=cur->next;
	cur->next=S->next;
	cur=S->next;
	printf("%d ",S->data);
	free(S);
}

void Joseph(LinkList L)
{//约瑟夫问题（数到3出局）
	int index=1;
	LinkList cur;
	cur=L;
	while(n!=1)
	{
		if((index+1)%3==0)
		{
			if(cur->next==L)
				L=L->next;
			Delete(cur);
			index=1;
			n--;
		}
		else
		{
			index++;
			cur=cur->next;
		}
	}
	printf("\n***剩下的人是第%d个人***\n",L->data);
}

void Display(LinkList L)
{//显示
	LinkList cur;
	cur=L;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",cur->data);
		cur=cur->next;
	}
	putchar('\n');
}

int main()
{
	LinkList L;
	Build(L);
	Display(L);

	printf("出局顺序为：");
	Joseph(L);
	
	return 0;
}
