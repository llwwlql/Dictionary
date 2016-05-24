#include <stdio.h>
#include <string.h>
int a[1000005];
int main()
{
	long long i,n;
	int T;
	int x,c,k;
	int d=0;
	scanf("%d",&T);
	while(T--)
	{
		d++;
		scanf("%d %I64d %d %d",&x,&n,&k,&c);
		memset(a,0,sizeof(a));
		int j=0;
		int sum=x;
		for(i=1;i<=1000000;i++)
		{
			sum%=k;
			a[j]=sum;
			sum=sum*10+x;
			if(a[j]==a[0] && j!=0)
				break;
			else
				j++;
		}
		printf("Case #%d:\n",d);
		if(a[(n-1)%j]==c)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
