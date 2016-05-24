#include <stdio.h>
int n;
void perm(int *a,int star)
{
	int i,temp,j;
	if(star==n-1)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[j]);
		return ;
	}
	for(i=star;i<n;i++)
	{
		temp=a[star];
		a[star]=a[i];
		a[i]=temp;
		perm(a,star+1);
		putchar('\n');
		temp=a[star];
		a[star]=a[i];
		a[i]=temp;
	}
}

int main()
{
	int a[100],i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	putchar('\n');
	perm(a,0);
	return 0;
}
