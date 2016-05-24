#include <stdio.h>
#include <string.h>
int n,a[45],b[25],dfs[25];
void ans(int *a)
{
	int i,j;
	for(i=2;i<=20;i++)
	{
		if(!a[i])
			for(j=i+i;j<=40;j+=i)
				a[j]=1;
	}
}

void DFS(int t)
{
	if(t==n)
	{
		if(a[dfs[t-1]+dfs[0]]==0)
		{
			printf("%d",dfs[0]);
			for(int i=1;i<n;i++)
				printf(" %d",dfs[i]);
			putchar('\n');
		}
		
		return ;
	}
	for(int i=1;i<n;i++)
	{
		if(b[i+1]==0)
		{
			dfs[t]=i+1;
			b[i+1]=1;
			if(a[dfs[t]+dfs[t-1]]==0)
				DFS(t+1);
			b[i+1]=0;
			dfs[t]=0;
		}
	}
	
}

int main()
{
	int i;
	i=1;
	ans(a);
	while(~scanf("%d",&n))
	{
		memset(b,0,sizeof(b));
		memset(dfs,0,sizeof(dfs));
		printf("Case %d:\n",i++);
		dfs[0]=1;
		DFS(1);
		putchar('\n');
	}
	
	return 0;
}
