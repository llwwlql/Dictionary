#include <stdio.h>
#include <string.h>
int dp[120005];
void ZeroOnePack(int v,int w,int V)
{
	int j;
	for(j=V;j>=w;j--)
	{
		if(dp[j-w]+v>dp[j])
			dp[j]=dp[j-w]+v;
	}
}

int main()
{
	int n[10],N=6;
	int V;
	int i,j,k;
	int index=0;
	while(scanf("%d %d %d %d %d %d",&n[1],&n[2],&n[3],&n[4],&n[5],&n[6]),n[1]||n[2]||n[3]||n[4]||n[5]||n[6])
	{
		index++;
		V=0;
		for(i=1;i<=N;i++)
			V+=n[i]*i;
		if(V%2==0)
		{
			V/=2;
			memset(dp,0,sizeof(dp));
			for(i=1;i<=N;i++)
			{
				if(n[i]*i>=V)			//��ȫ���� 
				{
					for(j=i;j<=V;j++)		//��������i��ʼѭ���ģ������1ѭ����j-i�����Ҳ��� 
					{
						if(dp[j-i]+i>dp[j])
							dp[j]=dp[j-i]+i;
					}
				}
				else
				{
					for(k=1;k<n[i];k*=2)		//���ֲ���
					{
						ZeroOnePack(k*i,k*i,V);
						n[i]=n[i]-k;
					}
					ZeroOnePack(n[i]*i,n[i]*i,V);
				}
			}
			if(dp[V]==V)
				printf("Collection #%d:\nCan be divided.\n\n",index);
			else
				printf("Collection #%d:\nCan't be divided.\n\n",index);
		}
		else
			printf("Collection #%d:\nCan't be divided.\n\n",index);
		
	}
	
	return 0;
}
