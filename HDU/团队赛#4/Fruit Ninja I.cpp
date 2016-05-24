#include <stdio.h>
#include <string.h>

int max(int a,int b)
{
	return a>b? a:b;
}

int map[10005][205];
int a[10005];
int Max[10005];
int main()
{
	int T;
	int d=0;
	int n,m,i,j;
	int x,y,c;
	int maxn,maxm;
	scanf("%d",&T);
	while(T--)
	{
		d++;
		maxn=0;
		maxm=0;
		for(i=0;i<=10000;i++)
			for(j=0;j<=200;j++)
				map[i][j]=-10000;
		memset(a,0,sizeof(a));
		memset(Max,0,sizeof(Max));
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&x,&c,&y);
			maxn=max(maxn,x);
			maxm=max(maxm,y);
			if(c==0)
				map[x][y]=1;
			else if(c==1)
				map[x][y]=-1;
		}
		
		for(i=1;i<=maxn;i++)
		{
			int temp=0;
			for(j=1;j<=maxm;j++)
			{
				
				if(a[i]>Max[i])
					Max[i]=a[i];
				
				if(a[i]+map[i][j]<=0)
				{
					a[i]=0;
					temp=0;
				}	
				else
				{
					temp++;
					if(map[i][j]<=0)
						temp=0;
					if(temp==3)
						a[i]+=4;
					else if(temp>3)
						a[i]+=map[i][j]*2;
					else
						a[i]+=map[i][j];
				}
			}
			if(a[i]>Max[i])
				Max[i]=a[i];
		}
	//	int mmax=0;
	//	for(i=1;i<=m;i++)
	//	{
			int sum=0;
			for(j=1;j<=maxn;j++)
			{
				sum+=Max[j];
				j+=m;
			}
	//		if(mmax<sum)
	//			mmax=sum;
	//	}
		printf("Case %d: %d\n",d,sum);
	}
	
	return 0;
}
