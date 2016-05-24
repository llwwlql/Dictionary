#include <stdio.h>
int m[10][10];
int n,p[10];
int LookupChain(int i,int j)
{
	if(m[i][j]>0) return m[i][j];
	if(i==j)	return 0;
	int u=LookupChain(i,i)+LookupChain(i+1,j)+p[i-1]*p[i]*p[j];
	for(int k=i+1;k<j;k++)
	{
		int t=LookupChain(i,k)+LookupChain(k+1,j)+p[i-1]*p[k]*p[j];
		if(t<u)
			u=t;
	}
	m[i][j]=u;
	return u;
}

int MemoizedMatrixChain()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			m[i][j]=0;
	return LookupChain(1,n);
}


int main()
{
	int i;
	n=6;
	for(i=0;i<=n;i++)
		scanf("%d",p+i);
	printf("%d",MemoizedMatrixChain());
	return 0;
}
