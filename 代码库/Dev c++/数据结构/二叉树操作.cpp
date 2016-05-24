#include <stdio.h>
#include <stdlib.h>
typedef struct Tree{
	struct Tree *lchild;
	struct Tree *rchild;
	char data;	
}Tree,*PTree;			//二叉树的结构声明
typedef struct Stack{
	PTree base[200];
	int top;
	int Stacksize;
}Stack;					//栈的结构声明

/*********************

	栈的操作 

***********************/

void InitStack(Stack &S)
{//建立一个空栈
	S.Stacksize=200;
	S.top=0;
}

void Push(Stack &S,PTree st)
{//入栈操作
	if(S.top+1>S.Stacksize)
	{
		printf("栈满，操作失败.");
		return ;
	}
	S.base[S.top++]=st;
}

void Pop(Stack &S,PTree p)
{//出栈操作
	p=S.base[--S.top];
}

int StackEmpty(Stack S)
{//判断栈是否为空
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

	树的操作

**********************/ 

void InitTree(PTree &bt)
{//二叉树的建立
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
{//判空操作 
	if(bt==NULL)
		return 1;
	else
		return 0;
}

void PreOrderTraverse(PTree bt)
{//先序递归遍历 
	if(TreeEmpty(bt))
	{
		return ;
	}
	
	printf("%c",bt->data);
	PreOrderTraverse(bt->lchild);
	PreOrderTraverse(bt->rchild);
}

void InOrderTraverse(PTree bt)
{//中序递归遍历 
	if(TreeEmpty(bt))
		return ;
	InOrderTraverse(bt->lchild);
	printf("%c",bt->data);
	InOrderTraverse(bt->rchild);
}

void PostOrderTraverse(PTree bt)
{//后序递归遍历 
	if(TreeEmpty(bt))
		return ;
	PostOrderTraverse(bt->lchild);
	PostOrderTraverse(bt->rchild);
	printf("%c",bt->data);
}

void DLR(PTree bt)
{//先序非递归遍历
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
		Pop(S,p);		//空指针退栈
		if(!StackEmpty(S))
		{
			Pop(S,p);
			Push(S,p->rchild);
		}
	}
	
}

void LDR(PTree bt)
{//中序非递归遍历
	Stack S;
	PTree p;
	InitStack(S);
	Push(S,bt);
	while(!StackEmpty(S))
	{
	
		while(GetTop(S,p)&&p)
			Push(S,p->lchild);
		Pop(S,p);		//空指针退栈 
		if(!StackEmpty(S))
		{
			Pop(S,p);
			printf("%c",p->data);
			Push(S,p->rchild);
		}
	}
}

void LRD(PTree bt)
{//后序非递归遍历
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
	printf("请输入一个完全二叉树：");
	InitTree(bt);
	
	printf("先序递归遍历：");
	PreOrderTraverse(bt);
	printf("\n中序递归遍历：");
	InOrderTraverse(bt);
	printf("\n后序递归遍历：");
	PostOrderTraverse(bt);
	
	putchar('\n');
	
/*	printf("先序非递归遍历：");
	DLR(bt);
	printf("\n中序非递归遍历：");
	LDR(bt);
	printf("\n后序非递归遍历：");
	LRD(bt);*/
	
	return 0;
}
