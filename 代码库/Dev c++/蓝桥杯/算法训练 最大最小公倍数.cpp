#include <stdio.h>
int main()
{
	long long n,max;
	scanf("%I64d",&n);
	
	if(n==1)
		printf("1\n");
	else if(n==2)
		printf("2\n");
	else
	{
		if(n%2)
			printf("%I64d\n",n*(n-1)*(n-2));
		else
		{
			if(n%3)
				printf("%I64d\n",n*(n-1)*(n-3));
            else
				printf("%I64d\n",(n-3)*(n-1)*(n-2));
		}
	}
	
	return 0;
}
