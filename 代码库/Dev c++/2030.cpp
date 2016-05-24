#include <stdio.h>
int main()
{
	int n,index;
	char ch;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		index=0;
		while(scanf("%c",&ch),ch!='\n')
		{
			if(ch<0)
				index++;
		}
		printf("%d\n",index/2);
	}
	
	return 0;
}
