#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
	char str[6][20]={"1969","1102","3177","1241"};
	int i,temp,len;
	len=3;
	srand(time(0));
	for(i=0;i<3;i++)
	{
		temp=rand()%(len+1);
		printf("%s\n",str[temp]);
		if(temp!=len)
			strcpy(str[temp],str[len]);
		len--;
	}
	
	return 0;
}
