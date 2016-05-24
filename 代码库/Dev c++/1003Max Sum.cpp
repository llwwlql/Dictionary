#include <stdio.h>
int main()
{
	int T,n,i,j;
	int a,sum,max,l,r,m_l,m_r;
	scanf("%d",&T);
	j=0;
	while(T--)
	{
		j++;
		sum=0;
		max=-1,m_l=0,m_r=0;
		scanf("%d",&n);
		l=r=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(sum+a>=a)
			{
				r=i;
				sum+=a;
			}
			else
			{
				l=r=i;
				sum=a;
			}
			if(max<=sum)
			{
				m_l=l;
				m_r=r;
				max=sum;
			}
		}
		if(j!=1)
			putchar('\n');
		printf("Case %d:\n",j);
		printf("%d %d %d\n",max,m_l,m_r);
	}
	
	return 0;
}
