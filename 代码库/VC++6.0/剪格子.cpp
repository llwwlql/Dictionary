#include <stdio.h>
int map[15][15];
int n,m;
int a[15][15];
int min=105,sum=0;
int dir[2][4]={-1,0,1,0,0,1,0,-1};

void dfs(int x,int y,int k,int t)
{
	int i,p,q;
	if(x<=0 || y<=0 || x>n || y>m || k>sum/2)
		return ;
	if(k==sum/2)
	{
		if(t<min)
			min=t;
		return ;
	}
	for(i=0;i<4;i++)
	{
		q=i+dir[0][i];
		p=i+dir[1][i];
		if(!a[q][p])
		{
			a[q][p]=1;
			dfs(q,p,k+map[q][p],t+1);
			a[q][p]=0;
		}
	}
}

int main()
{
	int i,j;
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",map[i]+j);
			sum+=map[i][j];
		}
	}
	if(sum%2==0)
	{
		a[1][1]=1;
		dfs(1,1,map[1][1],1);
		printf("%d\n",min);
	}
	else
		printf("0\n");
	
	return 0;
}