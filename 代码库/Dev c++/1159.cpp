#include <stdio.h>
#include <string.h>
int m[1005][1005];
void LCSLength(char *str1,char *str2,int len1,int len2)
{
	int i,j;
	for(i=0;i<=len1;i++)
		m[i][0]=0;
	for(i=0;i<=len2;i++)
		m[0][i]=0;
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(str1[i-1]==str2[j-1])
				m[i][j]=m[i-1][j-1]+1;
			else if(m[i-1][j]>=m[i][j-1])
				m[i][j]=m[i-1][j];
			else
				m[i][j]=m[i][j-1];
		}
	}
}

int main()
{
	char str1[1005],str2[1005];
	while(~scanf("%s %s",str1,str2))
	{
		LCSLength(str1,str2,strlen(str1),strlen(str2));
		printf("%d\n",m[strlen(str1)][strlen(str2)]);
		memset(str1,0,1005);
		memset(str2,0,1005);
	}
	return 0;
}
