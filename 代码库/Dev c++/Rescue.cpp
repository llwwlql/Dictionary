#include <stdio.h>
#include <string.h>
int n,m;
int min_t;
char map[205][205];
int visited[205][205];
int dir[2][4]={{-1,0,1,0},{0,1,0,-1}};

void dfs(int i,int j,int time)
{
	if(time>=min_t)
		return ;
	if(visited[i][j] || i<1 || j<1 || i>n || j>m)
		return ;
	if(map[i][j]=='r')
	{
		time++;
		if(time<min_t)
			min_t=time;
		return;
	}	
	else if(map[i][j]=='x')
		time+=2;
	else
		time+=1;
	visited[i][j]=1;
	
	for(int k=0;k<4;k++)
		dfs(i+dir[0][k],j+dir[1][k],time);
	visited[i][j]=0;
}

int main()
{
	int star_x,star_y;
	int i,j;
	while(~scanf("%d %d",&n,&m))
	{
		memset(visited,0,sizeof(visited));
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c",map[i]+j);
				if(map[i][j]=='a')
				{
					star_x=i;
					star_y=j;
				}
				if(map[i][j]=='#')
					visited[i][j]=1;
			}
		}
		
		min_t=40005;
		
		for(int k=0;k<4;k++)
			dfs(star_x+dir[0][k],star_y+dir[1][k],0);
		if(min_t==40005)
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		else
			printf("%d\n",min_t);
	}
	return 0;
}
