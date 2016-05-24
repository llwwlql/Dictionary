#include <stdio.h>
#include <string.h>
int main()
{
	int n,m;
	int k[10005];
	int a[3005],index,sum;
	int i,j;
	while(~scanf("%d %d",&n,&m))
	{
		memset(k,0,sizeof(k));
		scanf("%d",&a[0]);
		for(i=1;i<n;i++)
		{
			scanf("%d",a+i);
			for(j=0;j<i;j++)
			{
				sum=a[j]+a[i];
				k[sum]++;
			}
		}
		
		index=10000;

		while(k[index]==0)
			index--;
				
		printf("%d",index);
		k[index]--;
		m--;
		while(m)
		{
			while(k[index]==0)
				index--;
			printf(" %d",index);
			k[index]--;
			m--;
		}
		putchar('\n');
	}
	
	return 0;
}
