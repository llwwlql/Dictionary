#include <stdio.h>
#include <string.h>
int n,sum;
int a[25],ans[25];
int peace;

void dfs(int z,int count,int k)
{
	if(peace)
		return;
	if(count>sum)
		return ;
	if(count==sum)
		dfs(z+1,0,0);
	if(z==4)
		peace=1;
	for(int i=k+1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=1;
			dfs(z,count+ans[i],i);
			a[i]=0;
		}
	}
}

int main()
{
	int T;
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",ans+i);
			sum+=ans[i];
		}
		
		if(sum%4)
		{
			printf("no\n");
			continue;
		}
		else
		{
			peace=0;
			memset(a,0,sizeof(a));
			sum/=4;
			dfs(0,0,0);
			if(peace)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	
	return 0;
}
