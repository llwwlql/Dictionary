#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	char a,b,c;
	while(~scanf("%c %c %c",&a,&b,&c))
	{
		getchar();
		if(a>b)
			swap(a,b);
		if(a>c)
			swap(a,c);
		if(b>c)
			swap(b,c);
		printf("%c %c %c\n",a,b,c);
	}
	
	
	
	return 0;
}
