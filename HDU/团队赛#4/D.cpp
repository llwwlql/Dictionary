#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

map <char,char> a;

int main()
{
	int i,j;
	char str1[111],str2[111];
	int T,n=0;
	
	a['!']='i';
	a['u']='n';
	a['n']='u';
	a['a']='e';
	a['e']='a';
	a['7']='l';
	a['o']='o';
	a['^']='v';
	a['p']='d';
	a['w']='m';
	a['5']='s';
	a[' ']=' ';
	scanf("%d%c",&T);
	while(T--)
	{
		int len;
		gets(str1);
		len=strlen(str1);
		n++;
		for(i=0;i<len;i++)
		{
			str2[i]=a[str1[i]];
		}
		printf("Case %d: ",n);
		for(i=len-1;i>=0;i--)
			printf("%c",str2[i]);
		putchar('\n');
	}
	
	return 0;
}
