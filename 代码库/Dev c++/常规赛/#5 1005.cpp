#include <stdio.h>
#include <string.h>
char map[205][205];
int a[205][205];
int b1[205][205],b2[205][205];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int n,m,min,max;
void dfs(int x,int y,int t,int z)
{
	int i,j,p,q;
	if(z && max<t)
		return ;

	if(x<=0 || x>n || y<=0 || y>m)
		return ;
	if(map[x][y]=='@')
	{
		if(z && b2[x][y]>t)
		{
			b2[x][y]=t;
			if(min>b1[x][y]+b2[x][y])
			{
				min=b1[x][y]+b2[x][y];
				max=b2[x][y];
			}
			
		}
				
		else if(!z && b1[x][y]>t)
		{
			b1[x][y]=t;
		}
		return ;
	}
	for(i=0;i<4;i++)
	{
		p=x+dir[i][0];
		q=y+dir[i][1];
		if(!a[p][q])
		{
			a[p][q]=1;
			dfs(p,q,t+1,z);
			a[p][q]=0;
		}
	}
	
}

int main()
{
	int i,j;
	int star1_x,star1_y,star2_x,star2_y;
	while(~scanf("%d %d",&n,&m))
	{
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
			{
				b1[i][j]=160000;
				b2[i][j]=160000;
			}
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c",map[i]+j);
				if(map[i][j]=='Y')
				{
					star1_x=i;
					star1_y=j;
				}
				else if(map[i][j]=='M')
				{
					star2_x=i;
					star2_y=j;
				}
				else if(map[i][j]=='#')
					a[i][j]=1;
				else
					a[i][j]=0;
			}
		}
		min=1000000;
		max=1000000;
		a[star1_x][star1_y]=1;
		dfs(star1_x,star1_y,0,0);
		a[star1_x][star1_y]=0;
		
		a[star2_x][star2_y]=1;
		dfs(star2_x,star2_y,0,1);
		a[star2_x][star2_y]=0;


		printf("%d\n",min*11);
	}
	
	return 0;
}
