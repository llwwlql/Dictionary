#include <stdio.h>
typedef struct {
	int base[1000];
	int top;
	int strcksize;
}Strck;

int StrckEmpty(Strck S)
{
	if(S.top==0)
		return 1;
	return 0;
}

void InitStrck(Strck &S)
{
	S.top=0;
	S.strcksize=1000;
}

void Push(Strck &S,int e)
{
	S.base[S.top++]=e;
}

void Pop(Strck &S,int &e)
{
	if(StrckEmpty(S))
		return ;
	e=S.base[--S.top];
}

int main()
{
	int n,m,e;
	Strck S;
	InitStrck(S);
	printf("请输入一个十进制数：");
	scanf("%d",&n);
	printf("请输入要转换的进制：");
	scanf("%d",&m);
	while(n)
	{
		Push(S,n%m);
		n/=m;
	}
	printf("转换结果为:");
	while(!StrckEmpty(S))
	{
		Pop(S,e);
		if(m==16 && e>=10)
			printf("%c",e-10+'A');
		else
			printf("%d",e);
	}
	
	return 0;
}
