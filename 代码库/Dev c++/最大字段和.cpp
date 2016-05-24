#include <stdio.h>
int main()
{
	int T,n;
	int i,j,sum,b,a,l,r,temp;
	scanf("%d",&T);
	for(j=1;j<=T;j++)
	{
		b=0;
		sum=-10000;
		temp=l=r=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(b>=0)
				b+=a;
			else
			{
				b=a;
				temp=i;
			}
			if(b>sum)
			{
				r=i;
				l=temp;
				sum=b;
			}
		}
		printf("Case %d:\n%d %d %d\n",j,sum,l,r);
		if(j!=T)
			putchar('\n');
	}
	
	return 0;
}
