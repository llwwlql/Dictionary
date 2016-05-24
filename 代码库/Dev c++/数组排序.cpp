//数组的排序 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void Sort(int *a)
{
	int temp;
	int i,j;
	for(i=0;i<N-1;i++)		//冒泡排序 
	{
		for(j=i+1;j<N;j++)
		{
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main()
{
	int array[N];
	srand(time(0));		//随机产生数 
	int i,j;
	for(i=0;i<N;i++)
	{
		array[i]=rand()%100;	//随机产生100以内的数字，赋值 
		printf("%d ",array[i]);
	}
	putchar('\n');
	Sort(array);			//排序 
	for(i=0;i<N;i++)
		printf("%d ",array[i]);
	
	return 0;
}
