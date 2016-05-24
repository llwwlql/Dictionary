#include <stdio.h>
int n,m;

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void sort(int *a,int *b)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
				swap(b[i],b[j]);
			}
		}
	}
}

int main()
{
	int T,i,j,a[1005],b[1005];
	double sum;
	scanf("%d",&T);
	while(T--)
	{
		sum=.0;
		scanf("%d %d",&m,&n);
		for(i=1;i<=n;i++)
			scanf("%d %d",a+i,b+i);
		sort(a,b);
		for(i=1;i<=n && m;i++)
		{
			if(b[i]*a[i]<=m)
			{
				sum+=b[i];
				m-=b[i]*a[i];
			}
			else
			{
				sum+=m*1.0/a[i];
				m=0;
			}
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
