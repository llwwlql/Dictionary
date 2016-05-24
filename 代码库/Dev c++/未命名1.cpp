#include<stdio.h>
int main ()
{
	int a,b;
	for(a=1;a<=49;a++)
	for(b=1;b<=49;b++)
	{
		if(2015-a*(a+1)-b*(b+1)==1225-2*a-1-2*b-1)
		printf("%d %d\n",a,b);
	}
	return 0;
}
