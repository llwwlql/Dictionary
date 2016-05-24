#include <stdio.h>
#include <string.h> 
int main()
{
	int a[10];
	int i,j,k,l,m;
	int sum=45;
	int x1,x2;
	memset(a,0,sizeof(a));
	for(i=2;i<=4;i+=2)
	{
		if(i>=2)
			for(j=1;j<10;j++)
			{
				a[j]=1;
				for(k=0;k<10 /*&& j!=k*/;k++)
				{
					sum+=j*10+k;
					sum-=j+k;
					if(i>=4)
					{
						for(l=1;l<10 /*&& j!=l && l!=k*/;l++)
						{
							for(m=0;m<10/* &&m!=l && m!=k && m!=j*/;m++)
							{
								sum+=l*10+m;
								sum-=l+m;
								if(sum==100)
									printf("%d %d\n",j*10+k,l*10+m);
								sum-=l*10+m;
								sum+=l+m;
							}
						}
					}
					if(sum==100)
						printf("%d %d\n",j*10+k,l*10+m);
					sum-=j*10+k;
					sum+=j+k;
				}
			}
	}
	
	return 0;
}
