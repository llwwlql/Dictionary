#include <stdio.h>
int main()
{
	int n,m,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		if(n%(m+1)==0)
			printf("second\n");
		else
			printf("first\n");
	}
	
	return 0;
}
