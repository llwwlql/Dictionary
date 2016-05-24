//括号匹配 
#include <stdio.h>
#include <string.h>
typedef struct Stack{
	char base[200];
	int top;
	int Stacksize;
}Stack;

void InitStack(Stack &S)
{//建立一个空栈
	S.Stacksize=200;
	S.top=0;
}

void Push(Stack &S,char ch)
{//入栈操作
	if(S.top+1>S.Stacksize)
	{
		printf("栈满，操作失败.");
		return ;
	}
	S.base[S.top++]=ch;
}

void top(Stack &S,char &ch)
{//出栈操作
	ch=S.base[--S.top];
}

int StackEmpty(Stack S)
{//判断栈是否为空
	if(S.top==0)
		return 1;
	return 0;
}

int Judge(char *str,Stack &S)
{//判断括号是否匹配
	int len,i,j;
	char ch;
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]=='[' || str[i]=='(' || str[i]=='{')
			Push(S,str[i]);
		
		else if(str[i]== ']' || str[i]== ')' ||str[i]== '}')
		{
			if(StackEmpty(S))
				return 0;
			top(S,ch);
			if(str[i]==')' && ch=='(' || str[i]=='}' && ch=='{' || str[i]==']' && ch=='[')
				continue;
		    else
		    	return 0;	
		}
	}
        if(StackEmpty(S))
            return 1;
        else
            return 0;
}

int main()
{
	Stack S;
	char str[100];
	int judge;
	InitStack(S);
	printf("请输入算术表达式：");
	scanf("%s",str);
	judge=Judge(str,S);
	if(judge)
		printf("算数表达式括号正确\n");
	else
		printf("括号不匹配。\n");
	
	return 0;
}
