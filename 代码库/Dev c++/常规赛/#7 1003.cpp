#include <stdio.h>
#include <string.h>
char str[105];
int min[105];

void dfs(int t,int sum,int len,int flag)
{
	if(t>len)
		return ;
	if(sum>min[t])
		sum=min[t];
	else if(sum<min[t] && t!=len)
		min[t]=sum;
	if(t==len)
	{
		if(sum<min[t] && flag==0)
			min[t]=sum;
		printf("<%d %d %d>\n",t,sum,flag);
		return ;
	}
	if(str[t]>='a' && str[t]<='z')
	{
		if(flag)
		{
			dfs(t+1,sum+2,len,1);
			dfs(t+1,sum+2,len,0);
		}
		else
		{
			dfs(t+1,sum+2,len,1);
			dfs(t+1,sum+1,len,0);
		}
	}
	else
	{
		if(flag)
		{
			dfs(t+1,sum+1,len,1);
			dfs(t+1,sum+2,len,0);
		}
		else
		{
			dfs(t+1,sum+2,len,1);
			dfs(t+1,sum+2,len,0);
		}
	}
}

int main()
{
	int T;
	int i,j,len;
	scanf("%d",&T);
	while(T--)
	{
		
		scanf("%s",str);
		len=strlen(str);
		for(i=1;i<=100;i++)
			min[i]=1000000;
		dfs(0,0,len,0);
		printf("%d\n",min[len]);
	}
	
	return 0;
}
