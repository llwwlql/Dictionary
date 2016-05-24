#include <stdio.h>
#include <string.h>
int main()
{
	int T,n,i,j,a,b,temp;
	int count[405];
	scanf("%d",&T);
	while(T--)
	{
		memset(count,0,sizeof(count));
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			if(a>b)
			{
				temp=a;a=b;b=temp;
			}
			if(a%2==0)
				count[a-1]++;
			if(b%2==1)
				count[b+1]++;
			
			for(j=a;j<=b;j++)
				count[j]++;
		}
		int max=0;
		for(i=0;i<=405;i++)
			if(count[i]>max)
				max=count[i];
		printf("%d\n",max*10);
		
	}
	
	return 0;
}
