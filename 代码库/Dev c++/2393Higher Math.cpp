#include <stdio.h>
void swap(int &a,int &b,int &c)
{
	int temp;
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(a>c)
	{
		temp=c;
		c=a;
		a=temp;
	}
	if(b>c)
	{
		temp=b;
		b=c;
		c=temp;
	}
}

int main()
{
	int n;
	int i,j;
	int a,b,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		printf("Scenario #%d:\n",i);
		swap(a,b,c);
		if(a*a+b*b==c*c)
			printf("yes\n");
		else
			printf("no\n");
		putchar('\n');
	}
	
	return 0;
}
