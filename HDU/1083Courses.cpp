#include <stdio.h> 
#include <string.h>
int map[311][311];
int n,m;
int vis[311],pre[311]; 

int find(int x)
{
	int i;
	for(i=1;i<=m;i++)
	{
		if(map[x][i] && !vis[i])
		{
			vis[i]=1;
			if(!pre[i] || find(pre[i]))
			{
				pre[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int T; 
	int i,j,k;
	int a;
	int sum;
	scanf("%d",&T);
	while(T--)
	{
		memset(map,0,sizeof(map));
		memset(pre,0,sizeof(pre));
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(j=1;j<=k;j++)
			{
				scanf("%d",&a);
				map[i][a]=1;
			}
		}
		sum=0;
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			sum+=find(i);
		}
		if(sum==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
