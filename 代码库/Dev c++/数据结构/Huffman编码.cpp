//二叉搜索树 
#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	struct tree *lchild,*rchild;
	int data;	
}*BSTree,BSNode;

void Insert_BSTree(BSTree &BST,int data)
{//插入二叉排序树 
	BSTree p,s;
	p=BST;
	
	s=(BSTree )malloc(sizeof(BSNode));
	s->data=data;
	s->lchild=s->rchild=NULL;	
	while(p)
	{
		if(data<p->data)
			p=p->lchild;
		else if(data>=p->data)
			p=p->rchild;
	}
	p=s;
}

void Init_BSTree(BSTree &bst,int n)
{//建立二叉排序树 
	int data,i;
	
	scanf("%d",&data);
	
	bst=(BSTree)malloc(sizeof(BSNode));
	bst->data=data;
	bst->lchild=bst->rchild=NULL;
	for(i=1;i<n;i++)
	{
		scanf("%d",&data);
		Insert_BSTree(bst,data);
	}
}

void Search_BSTree(BSTree BST,int key)
{//查找关键字
	BSTree p;
	p=BST;
	while(p)
	{
		if(p->data==key)
		{
			printf("数字%d存在。\n",key);
			return ;
		}
		else if(key<p->data)
			p=p->lchild;
		else
			p=p->rchild;
	}
	
	printf("未查找到%d。\n",key);
}

void Delete_BSTree(BSTree BST,int key)
{//删除关键字 
	BSTree p;
	p=BST;
	while(p)
	{
		if(p->data==key)
		{
			
		}
		else if(key<p->data)
			p=p->lchild;
		else
			p=p->rchild;
	}
}

void DLR(BSTree BST)
{
	if(BST==NULL)
		return ;
	printf("%d ",BST->data);
	DLR(BST->lchild);
	DLR(BST->rchild);
}

int main()
{
	BSTree BST;
	int n,key;
	
	while(1)
	{
		printf("		*******************\n");
		printf("		1、建立二叉排序树\n");
		printf("		2、查找关键字\n");
		printf("		3、删除关键字\n");
		printf("		4、插入关键字\n");
		printf("		5、深度优先搜索\n");
		printf("		6、退出\n");
		printf("		*******************\n");
		
		printf("请输入选择：");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("请输入要数字个数：");
				scanf("%d",&key);
				printf("请输入各数字:"); 
				Init_BSTree(BST,key);
				break;
			case 2:
				printf("请输入查找的关键字：");
				scanf("%d",&key);
				Search_BSTree(BST,key);
				break;
			case 3:
				printf("请输入删除的关键字：");
				scanf("%d",&key);
				Delete_BSTree(BST,key);
				break;
			case 4:
				printf("请输入插入的关键字：");
				scanf("%d",&key);
				Insert_BSTree(BST,key);
				break;
			case 5:
				printf("深度优先搜索的结果为：");
				DLR(BST);
				putchar('\n');
				break;
			default:
				return 0;
		}
	}
	
	return 0;
}
