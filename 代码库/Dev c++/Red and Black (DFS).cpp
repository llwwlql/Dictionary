#include <stdio.h>
int n=0,m=0;
char map[25][25];
int dir[2][4]={-1,0,1,0,0,1,0,-1};
int count;
void dfs(int i,int j)
{
	int temp1,temp2;
	count++;
	map[i][j]='#';
	for(int k=0;k<4;k++)
	{
		temp1=i+dir[0][k];
		temp2=j+dir[1][k];
		if(temp1>=1 && temp2>=1 && temp1<=m && temp2<=n && map[temp1][temp2]=='.')
			dfs(temp1,temp2);
	}
}

int main()
{
	int i,j;
	int star_x,star_y;
	printf("%d %d",n,m);
	while(scanf("%d %d",&n,&m),n||m)
	{
		
		for(i=1;i<=m;i++)
		{
			getchar();
			for(j=1;j<=n;j++)
			{
				scanf("%c",map[i]+j);
				if(map[i][j]=='@')
				{
					star_x=i;
					star_y=j;
				}
			}
		}
		
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
				printf("%c ",map[i][j]);
			putchar('\n');
		}
		
		count=0;
		
		dfs(star_x,star_y);
		
		printf("%d\n",count);
		
	}
	
	return 0;
} 
