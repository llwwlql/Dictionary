#include <stdio.h>
int main()
{
	int T;
	int a,b,sum,min_a,min_b,i,j;
	scanf("%d",&T);
	while(T--)
	{
		min_a=1005;
		min_b=1005;
		scanf("%d %d %d",&a,&b,&sum);
		if(sum%2)
			printf("Impossible\n");
		else
		{
			sum/=2;
			for(i=1;i<=sum/a;i++)
			{
				for(j=1;j<=(sum-a*i)/b;j++)
				{
					if(a*i+b*j==sum)
					{
						if(min_a+min_b>i+j)
						{
							min_a=i;
							min_b=j;
						}
					}
				}
			}
			if(min_a==1005 && min_b==1005)
				printf("Impossible\n");
			else
				printf("%d %d\n",min_a*2,min_b*2);
		}
	}
	
	return 0;
}
