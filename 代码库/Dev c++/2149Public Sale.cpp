#include <stdio.h>
int main()
{
	int n,m;
	int i,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		if(n%(m+1)==0)
			printf("Rabbit\n");
		else
			printf("Grass\n");
	}
	
	return 0;
}
