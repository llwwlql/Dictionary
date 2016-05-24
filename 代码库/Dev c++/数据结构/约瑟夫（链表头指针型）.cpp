#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;	
}LNode,*LinkList;
int n; 
void Build(LinkList &L)
{//��������ͷָ��ָ���һ�����
	LinkList p,cur;
	int i;
	printf("����������:");
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
{//ɾ��������
	LinkList S;
	S=cur->next;
	cur->next=S->next;
	cur=S->next;
	printf("%d ",S->data);
	free(S);
}

void Joseph(LinkList L)
{//Լɪ�����⣨����3���֣�
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
	printf("\n***ʣ�µ����ǵ�%d����***\n",L->data);
}

void Display(LinkList L)
{//��ʾ
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

	printf("����˳��Ϊ��");
	Joseph(L);
	
	return 0;
}
