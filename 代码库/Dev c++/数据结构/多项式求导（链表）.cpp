typedef struct LNode{
	int coef;		//ϵ�� 
	int expn;		//ָ�� 
	struct LNode *next;
}LNode,*LinkList;

void Derivative(LinkList L)
{
	LinkList cur,s;
	cur=L->next;
	if(cur->expn==0)
	{
		s=cur;
		cur=cur->next;
		L->next=cur;
		free(s);
	}
	while(cur)
	{
		cur->coef=cur->coef*(cur->expn-1);
		cur->expn--;
		cur=cur->next;
	}
	
}
