#include <stdio.h>
#include <string.h>
int map[105][105];
int dir[4][2]={-1,0,0,1,1,0};
int n,max;
void dfs(int x,int y,int t)
{
	int i;
	if(t==n)
	{
		max++;
		return;
	}
	for(i=0;i<3;i++)
	{
		if(!map[x+dir[i][0]][y+dir[i][1]])
		{
			map[x+dir[i][0]][y+dir[i][1]]=1;
			dfs(x+dir[i][0],y+dir[i][1],t+1);
			map[x+dir[i][0]][y+dir[i][1]]=0;
		}
	}
}

int main()
{
	int T;
	int i,j,a[25];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		max=0;
		map[50][50]=1;
		dfs(50,50,0);
		printf("%d\n",max);
	}
	
	return 0;
}
