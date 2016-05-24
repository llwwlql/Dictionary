#include <stdio.h>
#include <stdlib.h>
typedef struct Tree{
	struct Tree *lchild;
	struct Tree *rchild;
	char data;	
}Tree,*PTree;			//�������Ľṹ����
typedef struct Stack{
	PTree base[200];
	int top;
	int Stacksize;
}Stack;					//ջ�Ľṹ����

/*********************

	ջ�Ĳ��� 

***********************/

void InitStack(Stack &S)
{//����һ����ջ
	S.Stacksize=200;
	S.top=0;
}

void Push(Stack &S,PTree st)
{//��ջ����
	if(S.top+1>S.Stacksize)
	{
		printf("ջ��������ʧ��.");
		return ;
	}
	S.base[S.top++]=st;
}

void Pop(Stack &S,PTree p)
{//��ջ����
	p=S.base[--S.top];
}

int StackEmpty(Stack S)
{//�ж�ջ�Ƿ�Ϊ��
	if(S.top==0)
		return 1;
	return 0;
}

int GetTop(Stack S,PTree p)
{
	p=S.base[S.top-1];
	return 1;
}
/********************

	���Ĳ���

**********************/ 

void InitTree(PTree &bt)
{//�������Ľ���
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
	{
		bt=NULL;
		return ;
	}
	else
	{
		bt=(PTree)malloc(sizeof(Tree));
		if(!bt)
			exit(0);
		bt->data=ch;
		InitTree(bt->lchild);
		InitTree(bt->rchild);
	}
}

int TreeEmpty(PTree bt)
{//�пղ��� 
	if(bt==NULL)
		return 1;
	else
		return 0;
}

void PreOrderTraverse(PTree bt)
{//����ݹ���� 
	if(TreeEmpty(bt))
	{
		return ;
	}
	
	printf("%c",bt->data);
	PreOrderTraverse(bt->lchild);
	PreOrderTraverse(bt->rchild);
}

void InOrderTraverse(PTree bt)
{//����ݹ���� 
	if(TreeEmpty(bt))
		return ;
	InOrderTraverse(bt->lchild);
	printf("%c",bt->data);
	InOrderTraverse(bt->rchild);
}

void PostOrderTraverse(PTree bt)
{//����ݹ���� 
	if(TreeEmpty(bt))
		return ;
	PostOrderTraverse(bt->lchild);
	PostOrderTraverse(bt->rchild);
	printf("%c",bt->data);
}

void DLR(PTree bt)
{//����ǵݹ����
	Stack S;
	PTree p;
	InitStack(S);
	Push(S,bt);
	while(!StackEmpty(S))
	{
	
		while(GetTop(S,p)&&p)
		{
			printf("%c",p->data);
			Push(S,p->lchild);
		}
		Pop(S,p);		//��ָ����ջ
		if(!StackEmpty(S))
		{
			Pop(S,p);
			Push(S,p->rchild);
		}
	}
	
}

void LDR(PTree bt)
{//����ǵݹ����
	Stack S;
	PTree p;
	InitStack(S);
	Push(S,bt);
	while(!StackEmpty(S))
	{
	
		while(GetTop(S,p)&&p)
			Push(S,p->lchild);
		Pop(S,p);		//��ָ����ջ 
		if(!StackEmpty(S))
		{
			Pop(S,p);
			printf("%c",p->data);
			Push(S,p->rchild);
		}
	}
}

void LRD(PTree bt)
{//����ǵݹ����
	Stack S;
	PTree P;
	InitStack(S);
	Push(S,P);
	while(GetTop(S,P)&&P)
		Push(S,P->lchild);
	Pop(S,P);
	if(!StackEmpty(S))
	{
		Push(S,p);
	}
}

int main()
{
	PTree bt;
	printf("������һ����ȫ��������");
	InitTree(bt);
	
	printf("����ݹ������");
	PreOrderTraverse(bt);
	printf("\n����ݹ������");
	InOrderTraverse(bt);
	printf("\n����ݹ������");
	PostOrderTraverse(bt);
	
	putchar('\n');
	
/*	printf("����ǵݹ������");
	DLR(bt);
	printf("\n����ǵݹ������");
	LDR(bt);
	printf("\n����ǵݹ������");
	LRD(bt);*/
	
	return 0;
}
