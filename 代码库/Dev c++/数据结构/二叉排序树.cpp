#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	struct tree *lchild,*rchild;
	int data;
}*BiTree,BiNode;

void Insert(BiTree bt,int data)
{//�ؼ��ֵĲ��� 
	BiTree p,s,parent;
	p=bt;
	while(p)
	{
		if(data<p->data)
		{
			parent=p;
			p=p->lchild;
		}
		
		else if(data>p->data)
		{
			parent=p;
			p=p->rchild;
		}
		else
			return ;
	}
	
	s=(BiTree)malloc(sizeof(BiNode));
	s->data=data;
	s->lchild=s->rchild=NULL;
	if(s->data<parent->data)
		parent->lchild=s;
	else
		parent->rchild=s;
}

void InitTree(BiTree &bt,int n)
{//�������������� 
	int data,i;
	scanf("%d",&data);
	bt=(BiTree)malloc(sizeof(BiNode));
	bt->data=data;
	bt->lchild=bt->rchild=NULL;
	for(i=1;i<n;i++)
	{
		scanf("%d",&data);
		Insert(bt,data);
	}
}

void InOrder(BiTree bt)
{//����������� 
	if(!bt)
		return ;

	InOrder(bt->lchild);
	printf("%d ",bt->data);
	InOrder(bt->rchild);
}

int Search(BiTree bt,int key)
{
	BiTree p;
	p=bt;
	while(p)
	{
		if(key<p->data)
			p=p->lchild;
		else if(key>p->data)
			p=p->rchild;
		else
		{
			printf("����%d���ҳɹ���\n",key);
			return 1;
		}
	}
	printf("δ�ҵ�����%d��\n",key); 
	return 0;
}

void Delete_BiTree(BiTree &bt,int key)
{
	BiTree p,cur,par;
	p=bt;
	while(p){
		if(key==p->data)
			break;
		else if(key<p->data){
			par=p;
			p=p->lchild;
		}
		else{
			par=p;
			p=p->rchild;
		}	
	}
	
	if(!p){
		printf("�����ݲ�����.\n");
		return ;
	}
	
	if(!p->lchild)		//û�������� 
	{
		if(p==bt)
			bt=p->rchild; 
		else if(par->lchild==p)
			par->lchild=p->rchild;
		else
			par->rchild=p->rchild;
		free(p);
	}
	else
	{
		cur=p->lchild;
		par=cur;
		while(cur->rchild)
		{
			par=cur;
			cur=cur->rchild;
		}
		
		if(par==p->lchild)			//p������û�������� 
		{
			p->data=par->data;
			p->lchild=par->lchild;
			free(par);
		}
		else						//p�������������� 
		{
			p->data=cur->data;
			par->rchild=cur->lchild;
			free(cur);
		}
	}
	printf("ɾ���ɹ�.\n");
}


int main()
{
	BiTree bt;
	int n,key,selet;
	while(1)
	{
		printf("		------------------\n");
		printf("		1����������������\n");
		printf("		2���������������\n");
		printf("		3����������\n");
		printf("		4��ɾ������\n");
		printf("		5����������\n");
		printf("		6���˳�\n"); 
		printf("		------------------\n");
		
		scanf("%d",&selet);
		switch(selet)
		{
			case 1:
				printf("�������ֵĸ���:");
				scanf("%d",&n);
				printf("������ÿ������:");
				InitTree(bt,n);
				break;
			case 2:	
				printf("����������Ϊ��");
				InOrder(bt);
				putchar('\n');
				break;
			case 3:
				printf("��������ҵĹؼ��֣�");
				scanf("%d",&key);
				Search(bt,key);
				break;
			case 4:
				printf("������ɾ���Ĺؼ��֣�");
				scanf("%d",&key);
				Delete_BiTree(bt,key);
				break;
			case 5:
				printf("������Ҫ��������ݣ�");
				scanf("%d",&key); 
				Insert(bt,key);
				printf("����ɹ�.\n");
				break;
			default:
				return 0;
		}
	}
}
