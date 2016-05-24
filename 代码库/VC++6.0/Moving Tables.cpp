#include <stdio.h>
#include <string.h>
void swap(int &a,int &b)
{
	int temp;
	temp=a;a=b;b=temp;
}
int main()
{
	int a,b,greedy[205];
	int n,T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int max=0;
		memset(greedy,0,sizeof(greedy));
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			if(a>b)
				swap(a,b);
			for(j=(a+1)/2;j<=(b+1)/2;j++)
				greedy[j]++;
		}
		
		for(i=0;i<=n;i++)
			if(max<greedy[i])
				max=greedy[i];
		printf("%d\n",max*10);
	}
	
	return 0;
}