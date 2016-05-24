#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
typedef struct point{
	int x,y;
}Point;
Point *a;
int map[25][25];
int Count;
int n,m;

int dir[2][4]={-1,0,1,0,0,1,0,-1};

void bfs(int i,int j)
{
	int index=0;
	queue <Point *> q;
	
	a=(Point *)malloc(sizeof(Point));
	
	a->x=i;
	a->y=j;
	map[i][j]=0;
	q.push(a);
	while(!q.empty())
	{
		a=q.front();
		q.pop();
		
		i=a->x;
		j=a->y;
		int k;
		for(k=0;k<4;k++)
		{
			if(i<1 || j<1 || i>m || j>n)
				continue;
			if(map[i+dir[0][k]][j+dir[1][k]]!=0)
			{
				a=(Point *)malloc(sizeof(Point));
				a->x=i+dir[0][k];
				a->y=j+dir[1][k];
				q.push(a);
				map[i+dir[0][k]][j+dir[1][k]]=0;
				Count++;
			}
		}
		
	}
	
}

int main()
{
	int i,j;
	int star_x,star_y;
	char ch;
	while(scanf("%d %d",&n,&m),n||m)
	{
		memset(map,0,sizeof(map));
		for(i=1;i<=m;i++)
		{
			getchar();
			for(j=1;j<=n;j++)
			{
				scanf("%c",&ch);
				if(ch=='.')
					map[i][j]=1;
				else if(ch=='@')
				{
					map[i][j]=2;
					star_x=i;
					star_y=j;
				}
				else
					map[i][j]=0;
			}
		}
		Count=1;
		
		bfs(star_x,star_y);
		
		printf("%d\n",Count);
		
	}
	
	return 0;
}
