#include <stdio.h>
long long a[2005];
int main()
{
	int T,n;
	int i,j;
	scanf("%d",&T);
	a[1]=26;
	a[2]=26*26;
	a[3]=26*26*26;
	a[4]=26*26*26*26-26;
	
	for(i=5;i<=2000;i++)
	{
		a[i]=1;
		for(j=1;j<=i;j++)
			a[i]=(a[i]*26)%1000000007;
		a[i]=(a[i]-a[i-4]*26)%1000000007;
		if(a[i]<0)
			a[i]+=1000000007;
	}
	
	while(T--)
	{
		scanf("%d",&n);
		printf("%I64d\n",a[n]);
		
	}
	
	return 0;
}
