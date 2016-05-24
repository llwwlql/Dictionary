#include <stdio.h>
#include <string.h>
int a[100005];
int b[100005];
int main()
{
	int n;
	int i,j,sum,max;
	while(~scanf("%d",&n))
	{
		int index=0;
		sum=0;
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		while(index<n)
		{
			max=30005;
			for(i=1;i<=n;i++)
			{
				if(!b[i])
				{
					if(a[i]<=max)
					{
						max=a[i];
						index++;
						b[i]=1;
					}
				}
			}
			sum++;
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
