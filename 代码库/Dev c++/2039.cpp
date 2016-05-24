#include <stdio.h>
int main()
{
	int n;
	double a=.0,b=.0,c=.0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		if(a+b>c && a+c>b && b+c>a)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
