#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
int pr(int *a,int low,int high)
{
	a[0]=a[low];
	while(low<high)
	{
		while(low<high && a[0]<=a[high])
			high--;
		a[low]=a[high];
		while(low<high && a[0]>=a[low])
			low++;
		a[high]=a[low];
	}
	a[low]=a[0]; 
 	return low;
}

void sort(int *a,int low,int high)
{
	int r,i;
	if(low<high)
	{
		r=pr(a,low,high);
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		putchar('\n');
		sort(a,low,r-1);
		sort(a,r+1,high);
	}
}

int main()
{
	int a[105];
	int i,j;
	int low,high;
	srand(time(0));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i]=rand()%89+10;
		printf("%d ",a[i]);
	}
	putchar('\n');
	low=1;
	high=n;
	sort(a,low,high);
	return 0;
}
