#include <stdio.h>
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int map[20][20];
int sum,n,m,peace;
char a[20][20];
void dfs(int x,int y,float num)
{
	int i,j,p,q,r,c;
	char temp;
	if(x<1 || y<1 || x>n || y>m || peace)
		return ;
	if(num==sum)
	{
		peace=1;
		return ;
	}
	for(i=0;i<4;i++)
	{
		p=x+dir[i][0];
		q=y+dir[i][1];
		if(map[p][q])
		{
			map[p][q]=0;
			temp=a[p][q];
				for(j=0;j<4;j++)
				{
					r=p+dir[j][0];
					c=q+dir[j][1];
					if(map[r][c])
					{
						
						map[r][c]=0;
						if(temp=='*')
							dfs(r,c,num*(a[r][c]-'0'));
						else if(temp=='+')
							dfs(r,c,num+(a[r][c]-'0'));
							
						else if(temp=='-')
							dfs(r,c,num-(a[r][c]-'0'));
						else if(temp=='/' && a[r][c]!='0')
							dfs(r,c,num*1.0/(a[r][c]-'0'));
						map[r][c]=1;
					}
				}
		}
		map[p][q]=1;
	}
	
}

int main()
{
	int i,j;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(i=0;i<=20;i++)
			for(j=0;j<=20;j++)
				map[i][j]=1;
		for(i=0;i<=20;i++)
		{
			map[i][0]=0;
			map[0][i]=0;
		}
		scanf("%d %d",&n,&m);
		scanf("%d",&sum);
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c",a[i]+j);
				if(a[i][j]=='#')
					map[i][j]=0;
			}
		}
		peace=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(map[i][j] && a[i][j]>='0' && a[i][j]<='9')
				{
					map[i][j]=0;
					dfs(i,j,(a[i][j]-'0')*1.0);
					map[i][j]=1;
				}
			}
		}
		if(peace)
			printf("Possible\n");
		else
			printf("Impossible\n");
		
	}
	
	
	return 0;
}
