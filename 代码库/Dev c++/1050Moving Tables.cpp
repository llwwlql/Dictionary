#include <stdio.h>
#include <string.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;*a=*b;*b=temp;
}
int main()
{
	int T,i,j;
	int n,array[205];
	int a,b;
	scanf("%d",&T);
	while(T--)
	{
		int max=0;
		memset(array,0,sizeof(array));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			if(a>b)
				swap(&a,&b);
			for(j=(a+1)/2;j<=(b+1)/2;j++)
				array[j]++;
		}
		
		for(i=0;i<=200;i++)
			if(max<array[i])
				max=array[i];
		printf("%d\n",max*10);
	}
	
	return 0;
}
