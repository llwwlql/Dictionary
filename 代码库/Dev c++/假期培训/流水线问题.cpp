#include <stdio.h>
#include <stdlib.h>
	class Type{
		public:
		int operator <=(Type a)const
		{
			return key<=a.key;
		}
		int key,index;
		bool job;
	};
void sort(Type *d,int n)
{
	Type temp;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(d[i].key>d[j].key)
			{
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
	
}	
	
	
int FlowShop(int *a,int *b,int *c,int n)
{
	int i,j,k;
	Type *d;
	d=(Type *)malloc((n+1)*sizeof(Type));
	for(i=0;i<n;i++)
	{
		d[i].key=a[i]>b[i]?b[i]:a[i];
		d[i].job=a[i]<=b[i];
		d[i].index=i;
	}
	sort(d,n);

	j=0;
	k=n-1;
	for(i=0;i<n;i++)
	{
		if(d[i].job)
			c[j++]=d[i].index;
		else
			c[k--]=d[i].index;
	}
	j=a[c[0]];
	k=j+b[c[0]];
	
	for(i=1;i<n;i++)
	{
		j+=a[c[i]];
		k=j<k?k+b[c[i]]:j+b[c[i]];
	}
	free(d);
	return k;
}

int main()
{
	int a[20],b[20],c[20];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d",a+i,b+i);

	printf("%d\n",FlowShop(a,b,c,n));
	
	return 0;
}
