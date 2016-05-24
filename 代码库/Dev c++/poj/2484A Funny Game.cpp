#include <stdio.h>
int main()
{
	int n;
	char str[2][100]={"Alice","Bob"};
	while(scanf("%d",&n),n)
	{
		if(n>=3)
			printf("%s\n",str[1]);
		else
			printf("%s\n",str[0]);
	}
	
	return 0;
}
