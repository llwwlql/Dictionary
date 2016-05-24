#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	int T,i;
	double temp;
	scanf("%d",&T);
	while(T--)
	{
		temp=.0;
		scanf("%d",&n);
		for(i=2;i<=n;i++)
			temp+=log10(i)*1.0;
		printf("%d\n",(int)(temp+1));
	}
	
	return 0;
}
