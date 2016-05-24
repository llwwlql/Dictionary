#include <stdio.h>
int main()
{
	int n,m; 
	while(~scanf("%d %d",&n,&m))
	{
		if(n%(m+1)==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
