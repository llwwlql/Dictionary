#include <stdio.h>
int a[1000005],b[10005];
int next[10005];

void Create_Next(int *b,int m)
{
	int i,j;
	i=1;j=0;
	next[1]=0;
	while(i<=m)
	{
		if(j==0 || b[i]==b[j])
		{
			i++;j++;
			if(b[i]!=b[j])
				next[i]=j;
			else
				next[i]=next[j];
			
		}
		else
			j=next[j];
			
		
	}
}

int KMP(int *a,int *b,int n,int m)
{
	int i,j;
	i=j=1;
	while(i<=n && j<=m)
	{
		if(j==0 || a[i]==b[j])
		{
			i++;
			j++;
		}
		else
			j=next[j];
	}
	if(j>m)
		return i-m;
	else
		return -1;
}

int main()
{
	int i,j;
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(j=1;j<=m;j++)
			scanf("%d",b+j);
		Create_Next(b,m);
		printf("%d\n",KMP(a,b,n,m));
	}
	
	return 0;
}
