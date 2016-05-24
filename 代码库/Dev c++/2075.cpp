#include <stdio.h>
int main()
{
	int T;
	long long a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d %I64d",&a,&b);
		if(a%b)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
