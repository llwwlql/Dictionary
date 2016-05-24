#include <stdio.h>
#define Max 1000001
long long euler(long long n){ //返回euler(n)   
     long long res=n,a=n;  
     for(long long i=2;i*i<=a;i++){  
         if(a%i==0){  
             res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出   
             while(a%i==0) a/=i;  
         }  
     }  
     if(a>1) res=res/a*(a-1);  
     return res;  
}
int main()
{
	long long n,x,sum;
	int i,j;
	while(~scanf("%I64d %I64d",&n,&x))
	{
		sum=n+x+1;
		while(sum%2==0 && (sum/2)%2==1)
			sum/=2;
		printf("%I64d\n",euler(sum));
	}
	
	return 0;
}
