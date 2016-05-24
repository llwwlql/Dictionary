#include <stdio.h>
#define MAX 33333
int n,A,a,b,k,mod,p;
long long x[MAX+5],y[MAX+5];

void init()
{
	int i,j;
	long long ans;
	x[0]=1;
	for(i=1;i<=MAX;i++)
		x[i]=(x[i-1]*A)%p;
	y[0]=1;
	ans=x[MAX];
	for(i=1;i<=n;i++)
		y[i]=(y[i-1]*ans)%p;
}

long long compute()
{
	long long sum=0;
	int fx;
	fx=k;
	for(int i=1;i<=n;i++)
	{
		sum=(sum+(y[fx/MAX]*x[fx%MAX])%p)%p;
		fx=(fx*a+b)%mod;
	}
	return sum;
}

int main()
{
	int T;
	int i,j,index=0;
	scanf("%d",&T);
	while(T--)
	{
		index++;
		scanf("%d %d %d %d %d %d %d",&n,&A,&a,&b,&k,&mod,&p);
		init();
		printf("Case #%d:%I64d\n",index,compute());
	}
	return 0;
}
