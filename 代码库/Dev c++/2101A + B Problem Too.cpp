#include <stdio.h>
int main()
{
	long long a,b;
	while(~scanf("%I64d %I64d",&a,&b))
		if((a+b)%86)
			printf("no\n");
		else
			printf("yes\n");
	
	return 0;
}
