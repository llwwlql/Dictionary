#include <stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void sort(int *J,int *F,int n)
{
	int i,j;
	double average;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(J[i]*1.0/F[i]<J[j]*1.0/F[j])
			{
				swap(&J[i],&J[j]);
				swap(&F[i],&F[j]);
			}
		}
	}
}

int main()
{
	int n,m;
	int i,j;
	int J[1005],F[1005];
	while(scanf("%d %d",&m,&n),n!=-1 || m!=-1)
	{
		double sum=.0;
		for(i=0;i<n;i++)
			scanf("%d %d",J+i,F+i);
		sort(J,F,n);
		
		for(i=0;i<n && m>0;i++)
		{
			if(m>=F[i])
			{
				m-=F[i];
				sum+=J[i];
			}
			
			else
			{
				sum+=J[i]*1.0*m/F[i];
				m=0;
			}
		}
		printf("%.3lf\n",sum);
	}
	
	return 0;
}
