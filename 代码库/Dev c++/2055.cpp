#include <stdio.h>

int fun(char ch)
{
	if(ch>='a' && ch<='z')
		return -(ch-'a'+1);
	else
		return ch-'A'+1;
}

int main()
{
	int T;
	int a;
	char ch;
	scanf("%d%*c",&T);
	while(T--)
	{
		scanf("%c %d",&ch,&a);
		getchar();
		printf("%d\n",fun(ch)+a);
	}
	
	return 0;
}
