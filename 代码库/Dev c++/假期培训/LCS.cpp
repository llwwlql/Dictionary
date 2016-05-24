#include <stdio.h>
#include <string.h>
void LCSLength(char *str1,char *str2,int (*m)[10],int (*s)[10],int len1,int len2)
{
	int i,j;
	for(i=0;i<=len1;i++)
		m[i][0]=0;
	for(i=1;i<=len1;i++)
		m[0][i]=0;
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				m[i][j]=m[i-1][j-1]+1;
				s[i][j]=1;
			}
			
			else if(m[i-1][j]>=m[i][j-1])
			{
				m[i][j]=m[i-1][j];
				s[i][j]=2;
			}
			else
			{
				m[i][j]=m[i][j-1];
				s[i][j]=3;
			}
		}
	}
}
void LCS(int i,int j,int (*s)[10],char str1[10])
{
	if(i==0 || j==0) return ;
	if(s[i][j]==1)
	{
		LCS(i-1,j-1,s,str1);
		printf("%c",str1[i-1]);
	}
	else if(s[i][j]==2)
		LCS(i-1,j,s,str1);
	else
		LCS(i,j-1,s,str1);
	
}


int main()
{
	char str1[10],str2[10];
	int m[10][10],s[10][10];
	int i,j;
	scanf("%s %s",str1,str2);
	LCSLength(str1,str2,m,s,strlen(str1),strlen(str2));
	printf("%d\n",m[strlen(str1)][strlen(str2)]);
	LCS(strlen(str1),strlen(str2),s,str1);
	
	return 0;
}
