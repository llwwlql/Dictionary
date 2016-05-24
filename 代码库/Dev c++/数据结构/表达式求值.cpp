//栈的表达式求值
#include <stdio.h>
#include <string.h>
typedef struct {
	int base[1000];
	int top;
	int strcksize;
}Strck;

int StrckEmpty(Strck S)
{//判断栈是否为空 
	if(S.top==0)
		return 1;
	return 0;
}

void InitStrck(Strck &S)
{//建立一个空栈 
	S.top=0;
	S.strcksize=1000;
}

void Push(Strck &S,int e)
{//入栈操作 
	S.base[S.top++]=e;
}

void Pop(Strck &S,int &e)
{//出栈操作
	if(StrckEmpty(S))
		return ;
	e=S.base[--S.top];
}

char precede (char a,char b)
{//判断符号的优先级 
    if (a=='-')
        {
        if ((a=='-' && b=='+') || (a=='-' && b=='-') || (a=='-' && b==')') || (a=='-' && b=='#'))
            return '>';
        else
            return '<';
        }

    else if (a=='+')
        {
            if ((a=='+' && b=='+') || (a=='+' && b=='-') || (a=='+' && b==')') || (a=='+' && b=='#'))
            return '>';
               else return '<';
        }
    else if (a=='*')
    {
        if ((a=='*' && b=='+') || (a=='*' && b=='-') || (a=='*' && b=='*') || (a=='*' && b=='/') || (a=='*' && b==')') || (a=='*' && b=='#'))
            return '>';
        else
        return '<';
    }
    else if (a=='/')
    {
        if ((a=='/' && b=='+') || (a=='/' && b=='-') || (a=='/' && b=='*') || (a=='/' && b=='/') || (a=='/' && b==')') || (a=='/' && b=='#'))
            return '>';
        else
        return '<';
    }
    else if (a=='(')
    {
        if (a=='(' && b==')')
                return '=';
        else
            return '<';
    }
    else if (a==')')
        return '>';
    else if (a=='#')
    {
        if (a=='#' && b=='#')
            return '=';
        else
            return '<';
    }
}

int Calculate(Strck &OPTR,strck &OPEN)
{
	char str[1000];
	int len,i,temp;
	printf("请输入算术表达式:\n");
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			temp=str[i]-'0';
			while(str[i+1]>='0' && str[i]<='9')
			{
				i++;
				temp=temp*10+str[i]-'0';
			}
			Push(OPEN,temp);
		}
		else if(str[i]==)
	}
}

int main()
{
	Strck OPER,OPEN;
	int sum;
	InitStrck(OPER);
	InitStrck(OPEN);
	sum=Calculate(S,L);
	printf("表达式的值为：%d\n",sum);
	
	return 0;
}
