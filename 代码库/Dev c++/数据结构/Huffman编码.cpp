//���������� 
#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	struct tree *lchild,*rchild;
	int data;	
}*BSTree,BSNode;

void Insert_BSTree(BSTree &BST,int data)
{//������������� 
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
{//�������������� 
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
{//���ҹؼ���
	BSTree p;
	p=BST;
	while(p)
	{
		if(p->data==key)
		{
			printf("����%d���ڡ�\n",key);
			return ;
		}
		else if(key<p->data)
			p=p->lchild;
		else
			p=p->rchild;
	}
	
	printf("δ���ҵ�%d��\n",key);
}

void Delete_BSTree(BSTree BST,int key)
{//ɾ���ؼ��� 
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
		printf("		1����������������\n");
		printf("		2�����ҹؼ���\n");
		printf("		3��ɾ���ؼ���\n");
		printf("		4������ؼ���\n");
		printf("		5�������������\n");
		printf("		6���˳�\n");
		printf("		*******************\n");
		
		printf("������ѡ��");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("������Ҫ���ָ�����");
				scanf("%d",&key);
				printf("�����������:"); 
				Init_BSTree(BST,key);
				break;
			case 2:
				printf("��������ҵĹؼ��֣�");
				scanf("%d",&key);
				Search_BSTree(BST,key);
				break;
			case 3:
				printf("������ɾ���Ĺؼ��֣�");
				scanf("%d",&key);
				Delete_BSTree(BST,key);
				break;
			case 4:
				printf("���������Ĺؼ��֣�");
				scanf("%d",&key);
				Insert_BSTree(BST,key);
				break;
			case 5:
				printf("������������Ľ��Ϊ��");
				DLR(BST);
				putchar('\n');
				break;
			default:
				return 0;
		}
	}
	
	return 0;
}
