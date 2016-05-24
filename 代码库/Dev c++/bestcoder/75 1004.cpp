#include <stdio.h>
#include <stdlib.h>
typedef struct link{
	int data;
	struct link *next;
}Link;
int a[5005];

int main()
{
	int i,j,k;
	int T,n;
	scanf("%d",&T);
		
		for(k=1;k<=5000;k++)
		{
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
				for(j=1;j<i;j++)
					cur=cur->next;
				p=cur->next;
				cur->next=p->next;
				free(p);
			}
			a[k]=cur->data;
		}
		while(T--)
		{
			scanf("%d",&n);
			printf("%d\n",a[n]);
		}
		
	
	return 0;
}
