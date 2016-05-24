#include <stdio.h>
int main()
{
	int n,b;
	int a[100005];
	int i,j,T,l,r,temp,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		l=r=temp=1;
		sum=-100000;
		b=0;
		for(i=1;i<=n;i++)
		{
			if(b>0)
				b+=a[i];
			else
			{
				temp=i;
				b=a[i];
			}
			if(b>=sum)
			{
				l=temp;
				r=i;
				sum=b;
			}
		}
		printf("%d %d %d\n",sum,l,r);
	}
	
	return 0;
}
