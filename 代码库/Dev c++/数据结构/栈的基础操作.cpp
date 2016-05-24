#include <stdio.h>
typedef struct stack{
	int top;
	int base[100];
	int stacksize;
}Stack;

void InitStack(Stack &S)
{//建立一个栈 
	S.top=0;
	S.stacksize=100;
}


int StackEmpty(Stack S)
{//栈的判空操作 
	if(S.top==0)
		return 1;
	return 0;
}

void Push(Stack &S,int e)
{//入栈 
	if(S.top+1>S.stacksize)
	{
		printf("栈满，入栈失败。\n");
		return ;
	}
	S.base[S.top++]=e;
}

void Pop(Stack &S,int &e)
{//出栈 
	if(StackEmpty(S))
	{
		printf("栈为空，操作失败。\n");
		return ;
	}
	e=S.base[--S.top];
	printf("栈顶元素为：%d\n",e) ; 
}


void GetTop(Stack S,int &e)
{//返回栈顶元素 
	if(StackEmpty(S))
	{
		printf("栈为空，操作失败。\n");
		return ;
	}
	e=S.base[S.top-1];
	printf("栈顶元素为:%d\n",e);
}

int main()
{
	Stack S;
	int e;
	InitStack(S);
	while(1)
	{
		int n;
		printf("			1、入栈\n");
		printf("			2、出栈\n");
		printf("			3、返回栈顶元素\n");
		printf("			4、结束\n");

		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("请输入要入栈的元素:");
				scanf("%d",&e);
	
				Push(S,e);
				break;
			case 2:printf("出栈：\n");
				Pop(S,e);
				break;
			case 3:
					GetTop(S,e);
					break;
			case 4:
				return 0;
		}
		
	
	} 
	
	return 0;
}
