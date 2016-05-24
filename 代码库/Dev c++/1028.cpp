#include <stdio.h>
long long fun(int n,int m)
{
	if(m==1 || n==1)
		return 1;
	else if(m>n)
		return fun(n,n);
	else if(n==m)
		return 1+fun(n,n-1);
	else
		return fun(n,m-1)+fun(n-m,m);
}

int main()
{
	int n,i;
	for(i=1;i<=20;i++)
		printf("%I64d\n",fun(i,i));
	
	return 0;
}
