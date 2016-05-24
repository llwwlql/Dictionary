#include <stdio.h>

char str[10][10];
int n,m,t;

int a[4]={-1,0,0,1};
int b[4]={0,-1,1,0};
int peace;

void dfs(int i,int j,int time)
{
	int k;
	char ch;
	
	if(peace)
		return ;
	
	if(time>t || i<1 || j<1 || i>n || j>m)
		return ;
	
	if(str[i][j]=='X')
		return ;

	if(str[i][j]=='D')
	{
		if(time==t)
			peace=1;
		return ;
	}
	
	ch=str[i][j];
	str[i][j]='X';
	
	
	for(k=0;k<4;k++)
		dfs(i+a[k],j+b[k],time+1);
	str[i][j]=ch;
}

int main()
{
	
	int i,j;
	while(scanf("%d %d %d",&n,&m,&t),n||m||t)
	{
		int star_x=0,star_y=0;
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c",str[i]+j);
				if(str[i][j]=='S')
				{
					star_x=i;
					star_y=j;
				}
			}
			
		}
		
		peace=0;
		dfs(star_x,star_y,0);
		if(peace)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
