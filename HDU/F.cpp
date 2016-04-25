#include <stdio.h>
int main()
{
	int i,j;
	int n,m;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int count=0;
		scanf("%d %d",&n,&m);
		while(n!=m)
		{
			if(n>m)
				n/=2;
			else
				m/=2;
			count++;
		}
		printf("%d\n",count);
	}
	
	return 0;
}
