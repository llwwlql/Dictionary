//Ë«ÏòÃ°ÅÝÅÅÐò 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int *a,int n)
{
	int low,high,i,j,flag;
	int temp;
	flag=1;low=0;high=n-1;
	while(flag)
	{
		flag=0;
		for(i=low;i<high;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];a[i]=a[i+1];a[i+1]=temp;
				flag=1;
			}
		}
		high--;
		for(i=high;i>low;i--)
		{
			if(a[i]<a[i-1])
			{
				temp=a[i];a[i]=a[i-1];a[i-1]=temp;
				flag=1;
			}
		}
		low++;
	}
}

int main()
{
	srand(time(0));
	int i,j,n;
	int *a;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int));
	for(i=0;i<n;i++)
	{
		a[i]=rand()%89+10;
		printf("%d ",a[i]);
	}
	putchar('\n');
	sort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	return  0;
}
