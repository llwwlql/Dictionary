#include <stdio.h>
int n,m;
int star_x,star_y,finish_x,finish_y;
int map[1005][1005];
int dir[2][4]={-1,0,1,0,0,1,0,-1};
int peace;
void dfs(int i,int j,int index,int z)
{
	if(peace)
		return ;
	
	if(i==finish_x && j==finish_y)
	{
		peace=1;
		return;
	}
	
	if(i<1 || j<1 ||i>n ||j>m || index>=3 || map[i][j]!=0)
		return ;
	if(index==2)
	{
		if(!((z==1 && i>finish_x && j==finish_y) || (z==2 && i==finish_x && j<finish_y) || 
		(z==3 && i<finish_x && j==finish_y)||
		(z==4 && i==finish_x && j>finish_y)))
			return ;
	}
	map[i][j]=-1;
	
	for(int k=0;k<4;k++)
	{
		if(k+1==z)
			dfs(i+dir[0][k],j+dir[1][k],index,z);
		else
			dfs(i+dir[0][k],j+dir[1][k],index+1,k+1);
	}
	map[i][j]=0;
}

int main()
{
	int i,j,p;
	
	while(scanf("%d %d",&n,&m),n||m)
	{

		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",map[i]+j);
		scanf("%d",&p);
		
		while(p--)
		{
			scanf("%d %d %d %d",&star_x,&star_y,&finish_x,&finish_y);
			peace=0;
			
			if(map[star_x][star_y]!=map[finish_x][finish_y] || map[star_x][star_y]==0)
			{
				printf("NO\n");
				continue;
			}
			else
			{
				for(i=1;i<=4;i++)
					dfs(star_x+dir[0][i-1],star_y+dir[1][i-1],0,i);
					
				if(peace)
					printf("YES\n");
				else
					printf("NO\n");
			}
			
		}
	}
	return 0;
}
