#include <stdio.h>
#include <string.h>
#include <math.h>
int pin[15];
int temp[15],index;

int judge(int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(fabs(pin[i]-pin[j])==fabs(i-j))
				return 0;
		}
	}
	return 1;
}

void dfs(int t,int n)
{
	int i;
	if(t==n+1)
	{
		if(judge(n))
			index++;
		return ;
	}
	
	for(i=1;i<=n;i++)
	{
		if(!temp[i])
		{
			temp[i]=1;
			pin[t]=i;
			dfs(t+1,n);
			temp[i]=0;
		}
	}
}

int main()
{
	int n;
	int a[15];
	int i,j;
	
	for(i=1;i<=10;i++)
	{
		index=0;
		memset(temp,0,sizeof(temp));
		dfs(1,i);
		a[i]=index;
	}
		
	
	while(scanf("%d",&n),n)
	{
		printf("%d\n",a[n]);
	}
	
	return 0;
}
