#include <stdio.h>
#include <string.h>
#define MAX 1000
int min_time;
char str[25][25];
int a[25][25];
int n,m;
int sx,sy,ex,ey;
void DFS(int t,int x,int y)
{
	if(t>min_time || a[x][y]==1)
		return ;
	if(x==ex && y==ey)
	{
		min_time=t;
		return ;
	}
	if(str[x][y]!='-' || str[x][y]!='|')
		a[x][y]=1;
	if(str[x+1][y]=='|' && t%2==0 && str[x+2][y]!='*'|| str[x+1][y]=='-' && t%2==1 && str[x+2][y]!='*')
		DFS(t+1,x+2,y);
	else if(str[x+1][y]!='*')
		DFS(t+1,x+1,y);

	if(str[x-1][y]=='|' && t%2==0 && str[x-2][y]!='*'|| str[x-1][y]=='-' && t%2==1 && str[x-2][y]!='*')
		DFS(t+1,x-2,y);
	else if(str[x-1][y]!='*')
		DFS(t+1,x-1,y);


	if(str[x][y+1]=='-' && t%2==0 && str[x][y+2]!='*'|| str[x][y+1]=='|' && t%2==1 && str[x][y+2]!='*')
		DFS(t+1,x,y+2);
	else if(str[x][y+1]!='*')
		DFS(t+1,x,y+1);

	if(str[x][y-1]=='-' && t%2==0 && str[x][y-2]!='*'|| str[x][y-1]=='|' && t%2==1 && str[x][y-2]!='*')
		DFS(t+1,x,y-2);
	else if(str[x][y-1]!='*')
		DFS(t+1,x,y-1);

	a[x][y]=0;
}

int main()
{
	int i,j;
	while(~scanf("%d %d",&n,&m))
	{
		memset(str,'*',sizeof(str));
		memset(a,0,sizeof(a));
		min_time=MAX;
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c",&str[i][j]);
				if(str[i][j]=='S')
				{
					sx=i;sy=j;
				}
				if(str[i][j]=='T')
				{
					ex=i;ey=j;
				}
			}
		}
		DFS(0,sx,sy);
		printf("%d\n",min_time);
	}
	return 0;
}
