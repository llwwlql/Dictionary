#include <stdio.h>
#include <string.h>
int map[30][30];
int peace;
void dfs(int i,int j)
{
	if(peace)
		return ;
	if(j=='m'-'a')
	{
		peace=1;
		return ;
	}
	map[i][j]=0;
	for(int k=0;k<26;k++)
		if(map[j][k])
			dfs(j,k);
	map[i][j]=1;
}

int main()
{
	char str[100];

	while(~scanf("%s",str))
	{
		memset(map,0,sizeof(map));
				
		while(str[0]!='0')
		{
			map[str[0]-'a'][str[strlen(str)-1]-'a']=1;
			scanf("%s",str);
		}
		peace=0;
		for(int i=0;i<26;i++)
			if(map['b'-'a'][i])
				dfs('b'-'a',i);

		if(peace)
			printf("Yes.\n");
		else
			printf("No.\n");
	}
	
	return 0;
}
