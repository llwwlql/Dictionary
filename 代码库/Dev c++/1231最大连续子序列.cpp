#include <stdio.h>
int main()
{
	int n,i;
	int max,a[10005],l,r,m_l,m_r,sum;
	while(scanf("%d",&n),n)
	{
		sum=0;
		l=r=1;
		max=-1000000;
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			if(sum>0)
			{
				r=i;
				sum+=a[i];
			}
			
			else
			{
				l=r=i;
				sum=a[i];
			}
			
			if(sum>max)
			{
				max=sum;
				m_l=l;
				m_r=r;
			}
		}
		if(max<0)
		{
			max=0;
			m_l=1;
			m_r=n;
		}
		printf("%d %d %d\n",max,a[m_l],a[m_r]);
	}
	
	return 0;
}
