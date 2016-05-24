#include <stdio.h>
#include <string.h>
int main()
{
	int n,p[20];
	int m[20][20],i,r,k;
	n=6;
	for(i=0;i<=n;i++)
		scanf("%d",p+i);
	
	for(i=0;i<10;i++)
		m[i][i]=0;
	for(r=2;r<=n;r++)
	{
		for(i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			for(k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];		//
				if(t<m[i][j])
					m[i][j]=t;
			}
		}
	}
	printf("%d\n",m[1][6]);
	
	return 0;
}
