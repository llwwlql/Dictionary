#include <stdio.h>
int a[100005];

int dp[100005];

int main()
{
	int n,l,i,j,k,index,peace;
	int T;
	scanf("%d",&T);
	for(k=1;k<=T;k++)
	{
		index=1;
		peace=0;
		int max=0,temp=0;
		scanf("%d %d",&n,&l);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		j=0;
		for(i=1;i<n;i++)
		{
			if(a[i]>a[j])
			{
				index++;
				j=i;
				peace=0;
				temp=0;
			}
			
			else if(peace)
			{
				temp++;
				if(temp>max)
					max=temp;
			}
			else
			{
				temp=1;
				peace=1;
			}
		}
		
		if(max>=l)
			printf("Case #%d: %d\n",k,index);
		else
			printf("Case #%d: %d\n",k,index-(l-max));
		
	}
	
	return 0;
}
