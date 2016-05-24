//ABD###CE##F##
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue> 
using namespace std;
typedef struct tree{
	char data;
	struct tree *lchild,*rchild;	
}BiNode,*BiTree;

void InitTree(BiTree &T)
{ 
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
	{
		T=NULL;
		return ;
	}
	T=(BiTree)malloc(sizeof(BiNode));
	T->data=ch;
	InitTree(T->lchild);
	InitTree(T->rchild);
}

void PreOrder(BiTree bt)
{
	stack <BiTree> S;
	int i,j;
	BiTree p;
	if(bt)
		p=bt;
	S.push(p);
	while(!S.empty())
	{
		while(p)
		{
			printf("%c",p->data);
			p=p->lchild;
			S.push(p);
		}
		S.pop();
		if(!S.empty())
		{
			p=S.top();
			S.pop();
			p=p->rchild;
			S.push(p);
		}
	}
}

void InOrder(BiTree bt)
{
	stack <BiTree> S;
	int i,j;
	BiTree p;
	if(bt)
		p=bt;
	S.push(p);
	while(!S.empty())
	{
		while(p)
		{
			p=p->lchild;
			S.push(p);
		}
		S.pop();
		if(!S.empty())
		{
			p=S.top();
			printf("%c",p->data);
			S.pop();
			p=p->rchild;
			S.push(p);
		}
	}
}

void PostOrder(BiTree bt)
{ //����ǵݹ���� 
	stack <BiTree> s;
	BiTree p,last;
	if(bt)
	{
		s.push(bt);
		p=bt;
	}
	while(!s.empty())
	{
		p=s.top();
		if((p->lchild==NULL && p->rchild==NULL) || last!=NULL &&(last==p->lchild || last==p->rchild))
		{
			printf("%c",p->data);
			last=p;
			s.pop();
		}
		else
		{
			if(p->rchild)
				s.push(p->rchild);
			if(p->lchild)
				s.push(p->lchild);
		}
	}
	
}
 
void LevelOrder(BiTree bt)
{//��α��� 
	queue <BiTree> q;
	BiTree p;
	if(bt)
		q.push(bt);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		printf("%c",p->data);
		if(p->lchild)
			q.push(p->lchild);
		if(p->rchild)
			q.push(p->rchild);
	}
}


int main()
{
	BiTree T;
	printf("���������Ľ�㣺");
	InitTree(T);
	
	printf("����������Ϊ��");
	
	PreOrder(T);
	putchar('\n');
	
	printf("����������Ϊ��");
	InOrder(T);
	putchar('\n');
	
	printf("����������Ϊ��");
	PostOrder(T);
	putchar('\n');
	
	printf("��α������Ϊ��");
	LevelOrder(T);
	putchar('\n');
	
	return 0;
}
