#include <stdio.h>
#include <string.h>
int a[105][5];
int b[5]={0,2,4,1,3};
int main()
{
	int i,j;
	int n,m;
	memset(a,0,sizeof(a));
	scanf("%d %d",&n,&m);
	
	for(i=0;i<m;i++)
	{
		for(j=1;j<=4;j++)
		{
			if(!a[(i/2)%n][b[j]])
			{
				a[(i/2)%n][b[j]]=i+1;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<=4;j++)
		{
			if(a[i][j])
				printf("%d ",a[i][j]);
		}
	//	putchar('\n');
	}
	putchar('\n');
	return 0;
}
