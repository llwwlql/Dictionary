#include <stdio.h>
#include <string.h>
#include <math.h>
int n,m,t;
char map[10][10];
int a[10][10];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int peace,fin_x,fin_y;
void dfs(int x,int y,int time)
{
	int i,p,q,temp;
	printf("<%d %d %d>\n",x,y,time);
	if(x<1 || y<1 || x>n || y>m || time>t || peace)
		return ;
	if(time==t && x==fin_x && y==fin_y)
	{
		peace=1;
		return ;
	}
	temp=t-time-fabs(x-fin_x)-fabs(y-fin_y);
	if(temp<0 || temp%2)
		return ;
	
	for(i=0;i<4;i++)
	{
		p=x+dir[i][0];
		q=y+dir[i][1];
		if(!a[p][q])
		{
			a[p][q]=1;
			dfs(p,q,time+1);
			a[p][q]=0;
		}
	}
	
}

int main()
{
	int i,j;
	int star_x,star_y;
	while(scanf("%d %d %d",&n,&m,&t),n||m||t)
	{
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c",map[i]+j);
				if(map[i][j]=='S')
				{
					star_x=i;
					star_y=j;
				}
				else if(map[i][j]=='D')
				{
					fin_x=i;
					fin_y=j;
				}
				else if(map[i][j]=='X')
					a[i][j]=1;
			}
		}
		
		peace=0;
		a[star_x][star_y]=1;
		dfs(star_x,star_y,0);
		if(peace)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
