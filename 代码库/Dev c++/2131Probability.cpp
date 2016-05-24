#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char ch,str[205];
	int i,j;
	while(~scanf("%c %s%*c",&ch,str))
	{
		int len=strlen(str),index=0;
		for(i=0;i<len;i++)
			if(ch==str[i] || fabs(ch-str[i])==32)
				index++;
		double sum=index*1.0/len;
		printf("%.5lf\n",sum);
	}
	
	return 0;
}
