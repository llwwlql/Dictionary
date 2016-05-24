#include <stdio.h>
#include <string.h>
int main()
{
	char str[105];
	int a[100],peace; 
	int i,j,len,index,index2=0;
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		peace=1;
		index=0;
		while(peace)
		{
			peace=0;
			index=index*10+str[i]-'0';
			for(j=i+1;str[j]=='0';j++,i++)
			{
				index*=10;
			}
			for(j=0;j<index2 && !peace;j++)
				if(index==a[j])
				{
					i++;
					peace=1;
					break;
				}
		}
		a[index2]=index;
		index2++;
	}
	for(i=0;i<index2;i++)
		printf("%d%c",a[i],i==index2-1? '\n':' ');
	
	return 0;
}
