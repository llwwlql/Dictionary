#include <stdio.h>
int main()
{
	double a,b;
	while(~scanf("%lf %lf",&a,&b))
	{
		if(a==b)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
