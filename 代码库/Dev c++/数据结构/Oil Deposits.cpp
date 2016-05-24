#include <stdio.h>
#include <string.h>
char map[105][105];
int dir[2][8]={{-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1}};
int index;
int n,m;

void dfs(int i,int j)
{
	if(i<1 || j<1 ||i>n || j>m)
		return ;
	if(map[i][j]!='@')
		return ;
	map[i][j]='*';
	
	for(int k=0;k<8;k++)
		dfs(i+dir[0][k],j+dir[1][k]);
}

int main()
{
	int i,j;
	while(scanf("%d %d",&n,&m),n||m)
	{
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
				scanf("%c",map[i]+j);
		}
		index=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(map[i][j]=='@')
				{
					index++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",index);
	}
	
	return 0;
}
