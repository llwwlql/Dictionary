#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
#define INF 1<<30
map <string,int> a; 

int Map[200][200];
int vis[200],dis[200];
int Count;

void init()
{
	int i,j;
	a.clear();
	for(i=0;i<200;i++)
		for(j=0;j<200;j++)
			Map[i][j]=(i==j) ? 0:INF;
	Count=1;
}

void Dijkstra()
{
	int i,j;
	int mark=-1,min=INF;
	memset(vis,0,sizeof(vis));
	
	for(i=1;i<Count;i++)
		dis[i]=Map[1][i];
	vis[1]=1;
	
	for(i=1;i<Count;i++)
	{
		min=INF;
		for(j=1;j<Count;j++)
		{
			if(!vis[j] && dis[j]<min)
			{
				min=dis[j];
				mark=j;
			}
		}
					
		vis[mark]=1;
		for(j=1;j<Count;j++)
		{
			if(!vis[j] && dis[j] > dis[mark] + Map[mark][j])
				dis[j] = dis[mark] + Map[mark][j];		
		}
	}
}

int main()
{
	int T;
	int i,j;
	char str1[35],str2[35];
	int x,y,c;
	while(scanf("%d",&T),T!=-1)
	{
		init();
		scanf("%s %s",str1,str2);
		a[str1]=Count++;
		a[str2]=Count++;	
		for(i=1;i<=T;i++)
		{
			scanf("%s %s %d",str1,str2,&c);
			if(!a[str1])
				a[str1]=Count++;
			if(!a[str2])
				a[str2]=Count++;
			x=a[str1];
			y=a[str2];
			if(c<Map[x][y])
				Map[x][y]=Map[y][x]=c;
		}
		Dijkstra();
		if(dis[2]==INF)
			printf("-1\n");
		else
			printf("%d\n",dis[2]);
		
	}	
	return 0;
}
