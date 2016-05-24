#include <stdio.h>
int main()
{
	int a,b,c,d;
	int index;
	index=0; 
	for(a=1;a<=9;a++)
	{
		for(b=1;b<=9;b++)
		{
			if(a!=b)
			{
				for(c=1;c<=9;c++)
				{
					for(d=1;d<=9;d++)
					{
						if(d!=c)
						{
							if((a*10+c)*1.0/(b*10+d)==(a*c)*1.0/(b*d))
							{
								printf("%d/%d   %d/%d\n",a,b,c,d);
								index++;
							}
							
						}
					}
				}
			}
		}
	}
	printf("%d\n",index);
	
	return 0;
}
