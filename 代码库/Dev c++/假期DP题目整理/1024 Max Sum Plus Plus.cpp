#include <stdio.h>
int a[100005];
int Max_sum(int n,int m)
{
	int sum=0;
	int i,j,k;
	int **b=new int*[m+1];
	if(n<m || m<1)	return 0;
	for(i=1;i<=m;i++)
		b[i]=new int[n+1]; 
	for(i=0;i<=n;i++)
		b[0][i]=0;
	for(j=0;j<=m;j++)
		b[j][0]=0;
	for(i=1;i<=m;i++)
	{
		for(j=i;j<=n-m+i;j++)
		{
			if(j>i)
			{
				b[i][j]=b[i][j-1]+a[j];
				for(k=i-1;k<j;k++)
				{
					if(b[i][j]<b[i-1][k]+a[j])
						b[i][j]=b[i-1][k]+a[j];
				}
			}
			else
			b[i][j]=b[i-1][j-1]+a[j];
		}
		for(j=m;j<=n;j++)
			if(sum<b[m][j])
				sum=b[m][j];
	}
	return sum;
}

int main()
{
	int n,m;
	int i;
	while(~scanf("%d %d",&m,&n))
	{
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		printf("%d\n",Max_sum(n,m));
	}
	
	return 0;
}
