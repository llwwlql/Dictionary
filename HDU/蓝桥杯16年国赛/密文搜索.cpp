#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[1050000];
int main()
{
	int n;
	int sum=0;
	int i,j;
	char match[10];
	scanf("%s",str);
	scanf("%d",&n);
	while(n--){
		scanf("%s",match);
		sort(match,match+8);
		int len=strlen(str);
		for(i=0;i+8<len;i++)
		{
			char new_str[10];
			for(j=0;j<8;j++)
				new_str[j]=str[i+j];
			new_str[8]='\0';
			if(strcmp(new_str,match)==0)
				sum++;
		}
	}
	printf("%d\n",sum);
	
	return 0;
}
