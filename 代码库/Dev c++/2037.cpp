#include <stdio.h>
int main()
{
	int n;
	int i,j;
	int temp,index1,peace;
	int bagin[100],end[100];
	while(scanf("%d",&n),n)
	{
		peace=1;
		for(i=0;i<n;i++)
			scanf("%d %d",&bagin[i],&end[i]);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(end[i]>end[j])
				{
					temp=end[i];
					end[i]=end[j];
					end[j]=temp;
					temp=bagin[i];
					bagin[i]=bagin[j];
					bagin[j]=temp;
				}
			}
		}
		index1=0;
		for(i=1;i<n;i++)
		{
			if(end[index1]<=bagin[i])
			{
				peace++;
				index1=i;
			}
		}
		printf("%d\n",peace);
	}
	
	return 0;
}
