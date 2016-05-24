#include <stdio.h>
#include <stack>
using namespace std;
/*typedef struct stack{
	int base[25];
	int top;
	int stacksize;
}Stack;*/
int n,a[25],b[25];


void ans(int *a)
{
	int i,j;
	for(i=2;i<=10;i++)
	{
		if(!a[i])
			for(j=i+i;j<=20;j+=i);
				a[j]=1;
	}
}

void DFS(int t,stack S)
{
	if(t==n)
	{
		printf("%d",S.base[0]);
		for(int i=1;i<n;i++)
			printf(" %d",S.base[i]);
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			Push(a,)
		}
	}
	
}

int main()
{
	int i;
	stack<int>S;
	i=1;
	ans(a);
	S
	while(~scanf("%d",&n))
	{
		memset(b,0,sizeof(b));
		printf("Case %d:\n",i++);
		DFS(0);
		putchar('\n');
	}
	
	return 0;
}