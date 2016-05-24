#include <stdio.h>

int map[10][10];
int a[4]={-1,1,0,0};
int b[4]={0,0,-1,1};
int count;
int n,m;
void dfs(int i,int j,int len,int index)
{
	if(map[i][j]==3)
	{
		if(count<index)
			count=index;
		return ;
	}
	
	if(i<0 || j<0 || i>=n || j>=m || len<=0)
		return ;
	if(map[i][j]==0)
		return ;
	if(map[i][j]==4 && len>0)
	{
		map[i][j]=0;
		len=6;
	}
	
	
	for(int k=0;k<4;k++)
		dfs(i+a[k],j+a[k],len-1,index+1);
	
}

int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%d",map[i]+j);
				if(map[i][j]==2)
				{
					x=i;
					y=j;
				}
			}
		count=100000;
		dfs(x,y,6,0);
		if(count==100000)
			printf("-1\n");
		else
			printf("%d\n",count);
	}
	
	return 0;
}