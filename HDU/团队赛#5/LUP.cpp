#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int index;
	int value;
	struct Node *next; 
}Lnode,*Linklist;

void increat(Linklist &head,int num,int v)
{
	Lnode * cur;
	cur = head->next;
	
	Lnode *N = (Lnode *)malloc(sizeof(Lnode));
	N->index=num;
	N->value+=v;
	N = head->next;
	N->next = NULL;
}

void query(Linklist head)
{
	Lnode *p;
	int mv=0,mvi=0;
	int mi=0,miv=0;
	p = head->next;
	while(p)
	{
		if(p->value<mv)
		{
			mv=p->value;
			mvi=p->index;
		}
		if(p->index<mv)
		{
			mi=p->index;
			miv=p->value;
		}
	}
	if(mv==miv)
	{
		if(mvi<mi)
		printf("%d",miv);
		else
		printf("%d",mv);
	}
	else{
		printf("%d",mv);
	}
}

int main()
{
	int t;
	int n;
	int num;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		Lnode *head = (Linklist)malloc(sizeof(Lnode));
		head->next=NULL;
		while(n--)
		{
			char ch;
			scanf("%c",&ch);
			switch(ch)
			{
				case 'b':{
					scanf("%d",&num);
					increat(head,num,1);
					break;
				}
				case 'c':{
					scanf("%d",&num);
					increat(head,num,-1);
					break;
				}
				case 'q':{
					query(head);
					break;
				}
			}
		}
	}
	return 0;
}
