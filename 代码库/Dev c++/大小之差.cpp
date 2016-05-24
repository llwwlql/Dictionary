#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int a[10]={0};

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

void backtrack(int t)
{
	int i,j;
	if(t>=6)
	{
		int temp[10],index;
		int max=0,min=0;
		for(i=0;i<6;i++)
			temp[i]=a[i];
		qsort(temp,6,sizeof(temp[0]),cmp);
		
		for(i=0,j=5;i<6;i++,j--)
		{
			min=min*10+temp[i];
			max=max*10+temp[j];
		}
		
		max=max-min;
		
		if(max>=100000)
		{
			while(max)
			{
				index=max%10;
				max/=10;
				int peace=0;
				for(i=0;i<6;i++)
				{
					if(index==temp[i])
					{
						temp[i]=0;
						peace=1;
					}	
				}
				if(!peace)
					break;
			}
		}
		
		return ;
	}
	
	for(i=1;i<=9;i++)
	{
		a[t]=i;
		backtrack(t+1);
		a[t]=0;
	}
	
}

int main()
{
	backtrack(0);	
	return 0;
}
