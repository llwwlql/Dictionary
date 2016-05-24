//����ƥ�� 
#include <stdio.h>
#include <string.h>
typedef struct Stack{
	char base[200];
	int top;
	int Stacksize;
}Stack;

void InitStack(Stack &S)
{//����һ����ջ
	S.Stacksize=200;
	S.top=0;
}

void Push(Stack &S,char ch)
{//��ջ����
	if(S.top+1>S.Stacksize)
	{
		printf("ջ��������ʧ��.");
		return ;
	}
	S.base[S.top++]=ch;
}

void top(Stack &S,char &ch)
{//��ջ����
	ch=S.base[--S.top];
}

int StackEmpty(Stack S)
{//�ж�ջ�Ƿ�Ϊ��
	if(S.top==0)
		return 1;
	return 0;
}

int Judge(char *str,Stack &S)
{//�ж������Ƿ�ƥ��
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
	printf("�������������ʽ��");
	scanf("%s",str);
	judge=Judge(str,S);
	if(judge)
		printf("�������ʽ������ȷ\n");
	else
		printf("���Ų�ƥ�䡣\n");
	
	return 0;
}
