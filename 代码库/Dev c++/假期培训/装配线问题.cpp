#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int a[2][6],t[2][6];
int i,j,e1,e2,x1,x2;
int f[2][10];
int l[2][10];

void fast()
{
	for(i=1;i<6;i++)
	{
		if(a[0][i]<=a[1][i]+t[0][i])
		{
			f[0][i]=f[0][i-1]+a[0][i];
			l[0][i]=1;
		}
		else
		{
			f[0][i]=f[0][i-1]+a[1][i]+t[0][i];
			l[1][i]=1;
		}
	}
	for(i=0;i<2;i++)
	{
		if(l[i][5]==1)
			f[i][6]=f[i][5]+x1;
		else
			f[i][6]=f[i][5]+x2;
	}
}

int main()
{

	srand(time(0));
	for(i=0;i<6;i++)
	{
		a[0][i]=rand()%11;
		t[0][i]=rand()%11;
		a[1][i]=rand()%11;
		t[1][i]=rand()%11;
	}
	e1=rand()%11;
	e2=rand()%11;
	x1=rand()%11;
	x2=rand()%11;
	for(i=0;i<2;i++)
	{
		for(j=0;j<6;j++)
			printf("%d ",a[i][j]);
		putchar('\n');
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<6;j++)
			printf("%d ",t[i][j]);
		putchar('\n');
	}
	printf("%d %d %d %d\n",e1,e2,x1,x2);
	f[0][0]=e1+a[0][0];
	f[1][0]=e2+a[1][0];
	fast();
	
	if(f[0][6]<f[1][6])
	{
		printf("%d\n",f[0][6]);
		for(i=1;i<6;i++)
			printf("%d ",l[0][i]);
		putchar('\n');
	}
	else
	{
		printf("%d\n",f[1][6]);
		for(i=1;i<6;i++)
			printf("%d ",l[1][i]);
		putchar('\n');
	}
		
	return 0;
}
