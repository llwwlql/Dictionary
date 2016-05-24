#include <stdio.h>
#include <string.h>
int dp[100010][12];
int Max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	int i,j;
	int n;
	int x,y;
	while(scanf("%d",&n),n)
	{
		int max=0;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			dp[y][x+1]++;
			if(y>max)
				max=y;
		}
		for(i=max-1;i>=0;i--)
		{
			for(j=1;j<=11;j++)
			{
				dp[i][j]+=Max(dp[i+1][j-1],Max(dp[i+1][j],dp[i+1][j+1]));			
			}
		}
		printf("%d\n",dp[0][6]);
	}
	
	return 0;
}
/*
Ê¾Àý£º 
5
2 5
4 2
3 3
6 1
1 7
6
5 1
4 1
6 1
7 2
7 2
8 3
0*/
