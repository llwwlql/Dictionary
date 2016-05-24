#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}

int main()
{
	int n;
	int i,j,k,l;
	int a[1005],b[1005],index1,index2;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n;i++)
			scanf("%d",b+i);
		qsort(a,n,sizeof(int),cmp);
		qsort(b,n,sizeof(int),cmp);
		i=0,j=n-1,k=0,l=n-1;
		index1=0;
		index2=0;
		while(j-i!=-1 && l-k!=-1)
		{
			if(a[i]>b[k])
			{
				i++,k++;
				index1++;
			}
			else if(a[i]==b[k])//如果田忌最快的马的速度与齐威王最快的马速度相等 
			{
				if(a[j]>b[l])	//如果田忌最慢的比齐威王最慢的快，则比之  
				{
					index1++;
					j--;l--;
				}
				else			//其他，则拿田忌的最慢马和齐王的最快马比。 
				{
					if(a[j]==b[k])
						index2++;
					j--;k++;
				}
			}
			else//如果田忌的最快马慢于齐王的最快马，则用田忌的最慢马和齐王的最快马比。 
			{
				j--;
				k++;
			}
		}
		printf("%d\n",(2*index1+index2-n)*200);
	}
	
	return 0;
}
