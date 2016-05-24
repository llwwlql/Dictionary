#include <stdio.h>
int n,c,v[105],w[105];
int max=-1;

void dfs(int t,int temp_w,int temp_v)
{
	if(t==n)
	{
		if(temp_w<=c && temp_v>max)
			max=temp_v;
		return ;
	}
	temp_w+=w[t];
	temp_v+=v[t];
	dfs(t+1,temp_w,temp_v);
	temp_w-=w[t];
	temp_v-=v[t];
	dfs(t+1,temp_w,temp_v);
}

int main()
{
	int i,j;
	scanf("%d %d",&n,&c);
	for(i=0;i<n;i++)
		scanf("%d %d",w+i,v+i);		
	dfs(0,0,0);
	printf("%d\n",max);
	
	return 0;
}
