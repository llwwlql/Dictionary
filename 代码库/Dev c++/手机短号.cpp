#include <stdio.h>
int main()
{
	int n,i;
	char str[20];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		putchar('6');
		for(i=6;i<=10;i++)
			printf("%c",str[i]);
		putchar('\n');
	}
	return 0;
}
