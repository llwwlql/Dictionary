#include <stdio.h>
#include <math.h> 
int main()
{
	long long a;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d",&a);
		if(n&1)
			printf("True\n");
		else
		{
			if(n%4==0)
				printf("True\n");
			else
				printf("False\n"); 
		}
		
	}
	
	return 0;
}
