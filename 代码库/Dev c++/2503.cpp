#include <stdio.h>

int gcd(int a,int b)
{
	int temp;
	if(a<b)
	{
		temp=a;a=b;b=temp;
	}
	while(a%b)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	
	return b;	
}

int main()
{
	int T,i,j;
	int a,b,c,d,e,f,temp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		f=b*d;	
		e=b*c+a*d;	//�����ļӷ� 
		if(e==f)
		{
			printf("1 1\n");
			continue;
		}
		temp=gcd(e,f);//�������Լ�� 
		printf("%d %d\n",e/temp,f/temp);	//������� 
	}
	
	return 0;
}
