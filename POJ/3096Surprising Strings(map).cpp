#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int main()
{
	char str[85];
	int i,j,k;
	while(scanf("%s",str),str[0]!='*')
	{
		int len=strlen(str);
		if(len<=2)
		{
			printf("%s is surprising.\n",str);
			continue;
		}
		else
		{
			bool sign=true;		//�жϳɹ��ı�־ 
			for(i=0;i<=len-2;i++)	//�����λ��d 
			{
				map <string,bool> temp;
				for(j=0;j<=len-i-2;j++)		//ѭ���жϰ�ÿһ��pari����temp�� 
				{
					char pair[3]={str[j],str[j+i+1],'\0'};
					if(!temp[pair])
						temp[pair]=true;
					else
					{
						sign=false;break;
					}
					
				}
				
				if(sign==false)
					break;
			}
			if(sign)
				printf("%s is surprising.\n",str);
			else
				printf("%s is NOT surprising.\n",str);
			
		}
		
	}
	
	return 0;
}
