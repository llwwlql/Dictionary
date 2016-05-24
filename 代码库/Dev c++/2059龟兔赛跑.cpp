#include <stdio.h>
double dp[105];
int main()
{
	int i,j;
	int a[105];
	int N,C,T;
	int vr,vt1,vt2,L;
	while(~scanf("%d",&L))
	{
		double temp=.0,rabbit=.0;
		int len;
		for(i=0;i<=100;i++)
			dp[i]=1000000.0;
		scanf("%d %d %d",&N,&C,&T);
		scanf("%d %d %d",&vr,&vt1,&vt2);
		for(i=1;i<=N;i++)
			scanf("%d",a+i);
		a[0]=0;
		a[N+1]=L;
		dp[0]=.0;
		for(i=1;i<=N+1;i++)
		{
			for(j=0;j<i;j++)
			{
				len=a[i]-a[j];
				temp= len>=C ? (C*1.0)/vt1+(len-C)*1.0/vt2:(len*1.0)/vt1;
				if(j)
					temp+=T;
				if(dp[i]>dp[j]+temp)
					dp[i]=dp[j]+temp;
			}
		}
		for(i=0;i<=N+1;i++)
			printf("%.2lf ",dp[i]);
		putchar('\n');
		
		rabbit=L*1.0/vr;
		if(rabbit<dp[N+1])
			printf("Good job,rabbit!\n");
		else
			printf("What a pity rabbit!\n");
	}
	return 0;
}
