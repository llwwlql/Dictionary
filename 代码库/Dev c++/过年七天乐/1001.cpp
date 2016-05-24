#include <stdio.h>
#include <string.h>
int map[25][25];
int index;
int a,b,A,B,k;
int n,m;
void dfs(int i,int t)
{
	int j;
	if(t==k)			//判断t==k时，就结束 
	{
		if(i==B)		//如果结束时点是B则计数+1 
			index=(index+1)%1000;
		return ;
	}
	
	for(j=0;j<n;j++)
	{
		if(map[i][j])
			dfs(j,t+1);
	}
	
}
int main()
{

	int i,j,T; 

	while(scanf("%d %d",&n,&m), n||m )
	{
		memset(map,0,sizeof(map));
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a][b]=1;
		}
		scanf("%d",&T);
		while(T--)
		{
						
			scanf("%d %d %d",&A,&B,&k);
			
			index=0;
			dfs(A,0);
			printf("%d\n",index);
		}		
	}
	
	return 0;
}
