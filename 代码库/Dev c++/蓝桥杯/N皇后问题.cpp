#include <stdio.h>
#include <math.h>
#include <string.h>
int a[15],b[15];
int queue[15];
int max;

int judge(int k,int t){
	int i;
	for(i=1;i<t;i++)
	{
		if(fabs(a[i]-k)==fabs(i-t))		//判断是否在同一条斜线上 
			return 0;
	}
	return 1;
}

void dfs(int t,int n)
{
	int i;
	if(t==n+1)
	{
		max++;
		return ;
	}
	
	for(i=1;i<=n;i++)
	{
		if(!b[i] && judge(i,t))	//剪枝 
		{
			b[i]=1;
			a[t]=i;
			dfs(t+1,n);
			b[i]=0;
		}
	}
}

int main()
{
	int n;
	int i,j;
	memset(a,0,sizeof(a));
	for(i=1;i<=10;i++)
	{
		max=0;
		memset(b,0,sizeof(b));
		dfs(1,i);
		queue[i]=max;
	}
	while(scanf("%d",&n),n)
		printf("%d\n",queue[n]);
	
	return 0;
}
