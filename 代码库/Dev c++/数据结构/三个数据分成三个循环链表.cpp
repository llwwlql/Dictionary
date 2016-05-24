typedef struct LNode{
	int number;
	char word;
	float real;
	struct LNode *next;
}LNode,*LinkList;

void Separate_Link(LinkList L,LinkList &P,LinkList &Q,LinkList &R)
{
	LinkList cur,temp,cur1,cur2,cur3;
	P=(LinkList)malloc(sizeof(LNode));
	Q=(LinkList)malloc(sizeof(LNode));
	R=(LinkList)malloc(sizeof(LNode));
	cur=L->next;
	cur1=P;
	cur2=Q;
	cur3=R;
	while(cur)
	{
		temp=(LinkList)malloc(sizeof(LNode));
		temp->number=cur->number;
		cur1->next=temp;
		temp=(LinkList)malloc(sizeof(LNode));
		temp->real=cur->real;
		cur2->next=temp;
		temp=(LinkList)malloc(sizeof(LNode));
		temp->word=cur->word;
		cur3->next=temp;
		cur=cur->next;
	}
	cur1->next=cur2->next=cur3->next=NULL;
}
