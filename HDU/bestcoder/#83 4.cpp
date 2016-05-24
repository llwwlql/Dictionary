#include <stdio.h>
int map[20005][10005];
int main()
{
	int T;
	int n,m;
	int i,j,k;
	int x;
	int y;
	int a[20005];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			for(j=i-1;j>0;j--)
			{
				map[i][j]=a[i]+a[j];
			}
				
		}
		
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			
			for(j=1;j<=x;j++)
				map[x][j]=map[x][j]-a[x]+y;
			for(j=x+1;j<=n;j++)
				map[j][x]=map[j][x]-a[x]+y;
			int sum=0;
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=j-1;k++)
					sum=sum^map[j][k];
			}
			printf("%d\n",sum);
			a[x]=y;
		}
	}
	return 0;
}
