#include <stdio.h>
#include <queue>
#include <stack>
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

int main()
{
	BiTree T;
	printf("���������Ľ�㣺");
	InitTree(T);
	
	printf("����������Ϊ��");
	
	PreOrder(T);
	putchar('\n');
	
	/*printf("����������Ϊ��");
	printf(""); 
	*/
	return 0;
}