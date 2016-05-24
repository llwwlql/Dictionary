#include <stdio.h>
int f[20];
int N,V;
void ZeroOnePack(int v,int w)
{
	int j;
	for(j=V;j>=w;j--)
		if(f[j-w]+v>f[j])
			f[j]=f[j-w]+v;
}

int main()
{
	int n[10],v[10],w[10];
	int i,j,k;
	scanf("%d %d",&N,&V);
	for(i=1;i<=N;i++)
		scanf("%d %d %d",v+i,w+i,n+i);
	for(i=1;i<=N;i++)
	{
		if(n[i]*w[i]>=V)
		{
			for(j=w[i];j<=V;j++)
				if(f[j-w[i]]+v[i]>f[j])
					f[j]=f[j-w[i]]+v[i];
		}
		else
		{
			for(k=1;k<n[i];k*=2)
			{
				ZeroOnePack(k*v[i],k*w[i]);
				n[i]=n[i]-k;
			}
			ZeroOnePack(n[i]*v[i],n[i]*w[i]);
		}
	}
	printf("%d\n",f[V]);
	
	return 0;
}
