#include <stdio.h>
int main()
{
	int n,p,q;
	int i,j;
	while(~scanf("%d %d %d",&n,&p,&q))
	{
		if(n%q>p)
			printf("LOST\n");
		else
			printf("WIN\n");
	}
	
	return 0;
}
