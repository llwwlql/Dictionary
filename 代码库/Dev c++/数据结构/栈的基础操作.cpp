#include <stdio.h>
typedef struct stack{
	int top;
	int base[100];
	int stacksize;
}Stack;

void InitStack(Stack &S)
{//����һ��ջ 
	S.top=0;
	S.stacksize=100;
}


int StackEmpty(Stack S)
{//ջ���пղ��� 
	if(S.top==0)
		return 1;
	return 0;
}

void Push(Stack &S,int e)
{//��ջ 
	if(S.top+1>S.stacksize)
	{
		printf("ջ������ջʧ�ܡ�\n");
		return ;
	}
	S.base[S.top++]=e;
}

void Pop(Stack &S,int &e)
{//��ջ 
	if(StackEmpty(S))
	{
		printf("ջΪ�գ�����ʧ�ܡ�\n");
		return ;
	}
	e=S.base[--S.top];
	printf("ջ��Ԫ��Ϊ��%d\n",e) ; 
}


void GetTop(Stack S,int &e)
{//����ջ��Ԫ�� 
	if(StackEmpty(S))
	{
		printf("ջΪ�գ�����ʧ�ܡ�\n");
		return ;
	}
	e=S.base[S.top-1];
	printf("ջ��Ԫ��Ϊ:%d\n",e);
}

int main()
{
	Stack S;
	int e;
	InitStack(S);
	while(1)
	{
		int n;
		printf("			1����ջ\n");
		printf("			2����ջ\n");
		printf("			3������ջ��Ԫ��\n");
		printf("			4������\n");

		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("������Ҫ��ջ��Ԫ��:");
				scanf("%d",&e);
	
				Push(S,e);
				break;
			case 2:printf("��ջ��\n");
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
