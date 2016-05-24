#include <stdio.h>
#include <string.h>
#include <math.h>
int ans[25];
int a[25];
int peace,n;
int sum;
void dfs(int arc,int count,int left,int k)
{
	if(peace)
		return ;
		
	if(count>sum)
		return;

	if(count==sum)
	{
		arc++;
		count=0;
	}
	if(arc==4 && left==0)
	{
		peace=1;
		return ;
	}
	
	for(int i=k;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=1;
			dfs(arc,count+ans[i],left-ans[i],i+1);
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
			
		memset(a,0,sizeof(a));
		if(sum%4)
		{
			printf("no\n");
			continue;
		}
		else
		{
			sum/=4;
			peace=0;
			dfs(0,0,sum*4,1);
			if(peace)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	
	return 0;
}
