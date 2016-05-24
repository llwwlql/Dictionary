#include <stdio.h>
int main()
{
	char str[20];
	int n,i;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		printf("6");
		for(i=6;i<11;i++)
			printf("%c",str[i]);
		putchar('\n');
	}
	
	return 0;
}
