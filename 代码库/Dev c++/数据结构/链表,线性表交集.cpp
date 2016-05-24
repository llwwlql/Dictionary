typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,* LinkList;

typedef struct{
	int *elem;
	int Length;
	int SizeLength;
}SqList;

void Intersect_Link(LinkList L,LinkList M,LinkList &K)
{
	LinkList cur,cur1,cur2,s;
	K=(LinkList)malloc(sizeof(LNode));
	cur=K;
	cur1=L->next;
	cur2=M->next;
	while(cur1 && cur2)
	{
		if(cur1->data>cur2->data)
		{
			s=cur1;
			cur1=cur1->next;
		}
		
		else if(cur1->data<cur2->data)
		{
			s=cur2;
			cur2=cur2->next;
		}
		
		else
		{
			cur->next=cur1;
			s=cur1;
			cur=cur->next;
			cur1=cur1->next;
			free(s);
			s=cur2;
			cur2=cur2->next;
		}
		free(s);
	}
}

void Intersect_List(SqList &L,SqList M,int index)
{
	int i,j;
	index=0;				//计数器，交集元素的个数 
	for(i=0;i<L.Length;i++)
	{
		for(j=0;j<M.Length;j++)
		{
			if(L.elem[i]==M.elem[j])
				L.elem[index++]=L.elem[i];		//把相交的数，放到第一个数组的前面 
		}
	}
}

