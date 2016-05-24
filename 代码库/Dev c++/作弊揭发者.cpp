#include <stdio.h>
#include <string.h>
int main()
{
	char str[10],ch[10],temp[1000][10];
	int n,i;
	int index=0,peace;
	scanf("%s",str);
	scanf("%d",&n);
	while(n--)
	{
		printf("***%d****\n",n);
		peace=1;
		scanf("%s",ch);
		for(i=0;i<9 && peace;i++)
		{
			if(str[i]!=ch[i] && str[i]!='*')
				peace=0;
		}
		if(peace)
		{
			strcpy(temp[index],ch);
			index++;
		}
	}
	printf("%d\n",index);
	for(i=0;i<index;i++)
		printf("%s\n",temp[i]);
	
	return 0;
}
