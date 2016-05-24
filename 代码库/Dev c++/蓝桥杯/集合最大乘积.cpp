#include <stdio.h>
int a[1005];
int n;
int max=-1;
void dfs(int sum,int t)
{
	if(t==n)
	{
		if(sum>max)
			max=sum;
		return ;
	}
	dfs(sum*a[t],t+1);
	dfs(sum,t+1);
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	dfs(1,0);
	printf("%d\n",max);
	return 0;
}
