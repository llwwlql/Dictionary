#include <stdio.h>
#include <string.h>
char map[25][25];
int dir[5][2]={-1,0,0,1,1,0,0,-1,0,0};
char a[25][25];
int peace;
int n,m;

int check1(int x,int y)
{
	for(int i=0;i<5;i++)
	{
		if(map[x+dir[i][0]][y+dir[i][1]]=='0')
		{
			return 0;
		}		
	}
	return 1;
}

void change(int x,int y)
{//填雷，周围数字改变 
	for(int i=0;i<5;i++)
		map[x+dir[i][0]][y+dir[i][1]]-=1;
}

void rechange(int x,int y)
{//周围数字还原 
	for(int i=0;i<5;i++)
		map[x+dir[i][0]][y+dir[i][1]]+=1;
}

int judge()
{//结束判断是否符合
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(map[i][j]!='0')
				return 0;
	}
	return 1;
}

void dfs(int x,int y,int t)
{
	int i,j;
	if(peace)
		return ;
	if(t==n*m+1)
	{
		if(judge())		//结束判断是否符合 
		{
			peace=1;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
					printf("%c",a[i][j]);
				putchar('\n');
			}
		}
		return ;
	}
	int px=t/m+1,py=t%m+1;
	if(check1(x,y))		//判断能否填雷
	{
		change(x,y);
		a[x][y]='*';
		dfs(px,py,t+1);
		rechange(x,y);
	}
	if(map[x-1][y]=='0' || x==1)	//剪枝
	{
		a[x][y]='.';	//不能填雷
		dfs(px,py,t+1);	
	}
}

int main()
{
	int T;
	int i,j; 
	int d=0;
	
	scanf("%d",&T);
	while(T--)
	{
		d++;
		memset(map,0,sizeof(map));
		memset(a,0,sizeof(a));
		for(i=0;i<25;i++)
			map[i][0]=map[0][i]='9';	//赋初值
		scanf("%d %d%*c",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%c",map[i]+j);
			}
			getchar();
		}
		peace=0;
		printf("Case %d:\n",d);
		dfs(1,1,1);
	}
	return 0;
}
