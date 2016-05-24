#include <stdio.h>
int v,n;
void swp(int &a,int &b)
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
			if(a[i]<a[j])
			{
				swp(a[i],a[j]);
				swp(b[i],b[j]);
			}
		}
	}
}

int main()
{
	int p[105],m[105];
	int i,j,index,sum;
	while(scanf("%d",&v),v)
	{
		scanf("%d",&n);
		index=0;
		sum=0;
		for(i=1;i<=n;i++)
			scanf("%d %d",p+i,m+i);
		sort(p,m);
		for(i=1;i<=n && index!=v;i++)
		{
			if(index+m[i]<=v)
			{
				index+=m[i];
				sum+=p[i]*m[i];
			}
			else
			{
				sum+=(v-index)*p[i];
				index=v;
				break;
			}
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
