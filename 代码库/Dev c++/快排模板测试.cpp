#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;
bool cmp(int a,int b)
{
	return a<b;
}


int main()
{
	int a[100];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	putchar('\n');
	sort(a+10,a+n,cmp);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
		if(i%10==0)
			putchar('\n');
	}
	
	return 0;
}
