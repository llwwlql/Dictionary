#include <stdio.h>
int main()
{
	int i,j,k,l,m;
	for(i=4;i<=20;i++)
	{
		for(j=1;j<i;j++)
		{
			for(k=1;k<j;k++)
			{
				for(l=1;l<k;l++)
				{
					if(j*k*l+i*k*l+i*j*l+i*j*k==i*j*k*l)
						printf("%d %d %d %d 0\n",i,j,k,l);
				}
			}
		}
	}
	
	return 0;
}
