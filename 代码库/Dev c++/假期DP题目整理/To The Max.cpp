#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	int i,j,k;
	int a[105][105];
	int sum;
	while(~scanf("%d",&n))
	{
		sum=-10000;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",a[i]+j);
		for(k=1;k<=n;k++)
		{
			int b[105];
			memset(b,0,sizeof(b));
			for(i=k;i<=n;i++)
			{
				for(j=1;j<=n;j++)
					b[j]+=a[i][j];
				
				
				int temp;
				temp=0;
				for(j=1;j<=n;j++)
				{
					if(temp>0)
						temp+=b[j];
					else
						temp=b[j];
					if(sum<temp)
						sum=temp;
				}
			}
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
