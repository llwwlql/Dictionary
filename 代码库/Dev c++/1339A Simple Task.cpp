#include <stdio.h>
int main()
{
	int n;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int index=0;
		scanf("%d",&n);
		while(n%2==0)
		{
			n/=2;
			index++;
		}
		
		printf("%d %d\n",n,index);	
	}
	
	return 0;
}
