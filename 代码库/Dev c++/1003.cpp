#include <stdio.h>
int main()
{
	int T;
	int n,i,j;
	int MAX_SUM,b,l,r,temp;
	int a[100005];
	scanf("%d",&T);
	for(j=1;j<=T;j++)
	{
		scanf("%d",&n);
		MAX_SUM=-100000;
		b=0;
		temp=1;r=1;
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
		{
			if(b>=0)
				b+=a[i];
			else
			{
				b=a[i];
				temp=i;
			}
			if(b>MAX_SUM)
			{
				MAX_SUM=b;
				l=temp;
				r=i;
			}
		}
		printf("Case %d:\n",j);
		printf("%d %d %d\n",MAX_SUM,l,r);
		if(j!=T)
			putchar('\n');
	}
	return 0;
}
