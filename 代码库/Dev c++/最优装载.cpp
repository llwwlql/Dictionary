#include <stdio.h>
int main()
{
	int c,i,j,n,temp,sum,index;
	int a[100];
	while(scanf("%d %d",&n,&c),n,c)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n-1;i++)				//排序 
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		
		sum=0;
		index=0;
		for(i=0;i<n;i++)			//最小的装上 
		{
			if(a[i]<c-sum)
			{
				sum+=a[i];
				index++;
			}
		}
		printf("%d\n",index);
	}
	
	return 0;
}
