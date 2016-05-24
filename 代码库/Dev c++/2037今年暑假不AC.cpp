#include <stdio.h>
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	int n;
	int a[105],b[105];
	int i,j,index,temp;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d %d",a+i,b+i);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(b[i]>b[j])
				{
					swap(b[i],b[j]);
					swap(a[i],a[j]);
				}
			}
		}
		j=0;
		index=1;
		for(i=1;i<n;i++)
		{
			if(a[i]>=b[j])
			{
				index++;
				j=i;
			}
		}
		printf("%d\n",index);
	}
	
	return 0;
}
