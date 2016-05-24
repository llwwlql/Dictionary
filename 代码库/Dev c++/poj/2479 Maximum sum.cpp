#include <stdio.h>
int left[50005],right[50005];

int max(int a,int b)
{
	return a>b? a:b;
}

int main()
{
	int T,n;
	int i,j;
	int a[50005];
	int sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) 
			scanf("%d",a+i);
		sum=a[0];
		left[0]=a[0];
		right[n]=a[n];
		for(i=2;i<=n;i++)
		{
			if(sum>0)
				sum=sum+a[i];
			else
				sum=a[i];
			if(sum>left[i-1])
				left[i]=sum;
			left[i]=left[i-1];
		}
		sum=a[n];
		printf("%d\n",left[n]);
		for(i=n-1;i>=1;i--)
		{
			if(sum>0)
				sum=sum+a[i];
			else
				sum=a[i];
			if(sum>left[i-1])
				right[i]=sum;
			right[i]=right[i+1];
		}
		int ans=-1000000;
		for(i=1;i<n;i++)
		{
			if(ans<left[i]+right[i])
				ans=left[i]+right[i+1];
		}
		//printf("%d\n",ans);
	}
	
	return 0;
}
