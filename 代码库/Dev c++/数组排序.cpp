//��������� 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void Sort(int *a)
{
	int temp;
	int i,j;
	for(i=0;i<N-1;i++)		//ð������ 
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
	srand(time(0));		//��������� 
	int i,j;
	for(i=0;i<N;i++)
	{
		array[i]=rand()%100;	//�������100���ڵ����֣���ֵ 
		printf("%d ",array[i]);
	}
	putchar('\n');
	Sort(array);			//���� 
	for(i=0;i<N;i++)
		printf("%d ",array[i]);
	
	return 0;
}
