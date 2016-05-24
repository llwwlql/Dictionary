#include <stdio.h>
#include <stdio.h>
char str[105][105];
int n,m;
int a[8]={-1,-1,-1,0,0,1,1,1};
int b[8]={-1,0,1,-1,1,-1,0,1};

void dfs(int i,int j)
{
	int k;
	if(i<0 || j<0)
		return ;
	
	if(str[i][j]!='@')
		return ;
	str[i][j]='*';
	for(k=0;k<=7;k++)
		dfs(i+a[k],j+b[k]);
		
}

int main()
{
	int i,j;
	int count;
	while(scanf("%d%d",&n,&m),n||m)
	{
		count=0;
		for(i=0;i<n;i++)
			scanf("%s",str[i]);
			
		
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(str[i][j]=='@')
				{
					count++;
					dfs(i,j);
				}
			}
		printf("%d\n",count);
	}
	
	return 0;
}
