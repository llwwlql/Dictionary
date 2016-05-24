#include <stdio.h>
int map[25][25];
int n,m;
int star_x,star_y;
int max;

int dir[2][4]={-1,0,1,0,0,1,0,-1};

void dfs(int i,int j,int count)
{
	//printf("<%d %d %d>\n",i,j,count);
	if(i<1 || j<1 || i>n || j>m)
		return ;
	if(map[i][j]==0)
		return ;
	if(count>max)
		max=count;
	count++;
	map[i][j]=0;
	
	for(int k=0;k<4;k++)
		dfs(i+dir[0][k],j+dir[1][k],count);
	
	//map[i][j]=1;
	//count--;
}

int main()
{
	int i,j;
	char ch;
	while(scanf("%d %d",&m,&n),n||m)
	{
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c",&ch);
				if(ch=='.')
					map[i][j]=1;
				else if(ch=='@')
				{
					star_x=i;
					star_y=j;
					map[i][j]=2;
				}
				else
					map[i][j]=0;
			}
		}
		
		/*for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
			
				if(map[i][j]==1)
					printf(".");
				else if(map[i][j]==2)
					printf("@");
				else
					printf("#");	
			}
			putchar('\n');
		}*/
			
		max=0;		
		
		dfs(star_x,star_y,1);
		printf("%d\n",max);
		
	}
	return 0;
}
