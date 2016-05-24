#include <stdio.h>
#include <string.h>
int main()
{
	char str[1005][100];
	char ch[10005];
	int i,j,k,peace;
	while(1)
	{
		gets(ch);
		if(ch[0]=='#')
			break;
		int len=strlen(ch);
		int index=0;
		j=0,k=0;
		for(i=0;i<len;i++)
		{
			if(ch[i]==' ')
			{
				j++;
				k=0;
			}
			else
				str[j][k++]=ch[i];
		}
		
		for(i=0;i<=j;i++)
		{
			peace=1;
			for(k=0;k<i;k++)
			{
				if(strcmp(str[i],str[k])==0)
					peace=0;
			}
			if(peace)
				index++;
		}
		printf("%d\n",index);
	}
	
	return 0;
}
