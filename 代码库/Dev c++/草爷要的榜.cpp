#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sum[1005];
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int h,m;
	int n,s,a;
	int i,j;
	while(~scanf("%d %d",&n,&s))
	{
		memset(sum,0,sizeof(sum));
		for(j=0;j<n;j++)
		{
			for(i=1;i<=s;i++)
			{
				scanf("%d:%d",&h,&m);
				sum[j]+=h*60+m;
			}
			for(i=1;i<=s;i++)
			{
				scanf("%d",&a);
				sum[j]+=(a-1)*20;
			}
		}
		qsort(sum,n,sizeof(sum[0]),cmp);
		for(j=0;j<n;j++)
			printf("%d%c",sum[j],j==n-1? '\n':' ');
	}
	return 0;
}
