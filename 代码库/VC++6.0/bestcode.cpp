#include <stdio.h>
#include <stdlib.h>
typedef struct link{
	int data;
	struct link *next;
}Link;

int main()
{
	int i,j;
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		Link *head,*cur,*p;
		
		for(i=1;i<=n;i++)
		{
			p=(Link *)malloc(sizeof(Link));
			p->data=i;
			p->next=NULL;
			if(i==1)
			{
				head=cur=p;
			}
			else
			{	
				cur->next=p;
				cur=p;
				p=p->next;
			}
		}
		p=head;
		if(n!=1)
		{
			cur->next=head->next;
			free(p);
		}
			
		
		for(i=2;i<n;i++)
		{
			for(j=1;j<=i;j++)
				p=p->next;
			cur=p;
			cur=p->next;
			p->next=cur->next;
			free(cur);
		}
		printf("%d\n",cur->data);
		
	}
		
	
	return 0;
}