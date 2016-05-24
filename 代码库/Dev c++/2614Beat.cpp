#include <stdio.h>
#include <string.h>
int map[20][20];
int a[20];
int max,n;
void dfs(int t,int i,int sum,int bef)
{
	int j;
	if(t>n)
	{
		if(sum>max)
			max=sum;
		return ;
	}
	
	for(j=1;j<=n;j++)
	{
		if(!a[i])
		{
			if(map[i][j]>=bef)
			{
				a[i]=1;
				dfs(j,t+1,sum+map[i][j],map[i][j]);
				a[i]=0;
			}
		}
	}
}


int main()
{
	int i,j;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%d",map[i]+j);
		}
		memset(a,0,sizeof(a));
		max=0;
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i]=1;
				dfs(1,j,0,map[i][j]);
				a[i]=0;
			}
		}
		printf("%d\n",max);
	}
	
	return 0;
}
