#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <string.h>
#define MAX 100
using namespace std;

int visited[MAX+1];		//��¼�Ƿ���ʹ� 

typedef struct node{
	int data;
	struct node *next;
}Node,*ArcNode;
//�����ڽӱ�ı�����

typedef struct vnode{
	char data;
	ArcNode firstarc;
}VNode;
//�����ڽӱ�Ľ������ 

typedef struct Graph{
	VNode AdjList[MAX];
	int vexnum,arcnum;
}MGraph;
//����ͼ���� 

int LocateVex(char ch,MGraph G)
{//ȡ�ý���������е�λ�� 
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.AdjList[i].data==ch)
			return i;
	return -1;
}

void InitGraph(MGraph &G)
{//����һ������ͼ 
	int n,m;
	int i,j,k;
	char ch1,ch2;
	ArcNode p;
	printf("������������ͱ߸�����");
	scanf("%d %d",&G.vexnum,&G.arcnum);
	printf("�������㣺");
	getchar();
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.AdjList[i].data);
		G.AdjList[i].firstarc=NULL;
	}
	
	printf("������ߣ�");
	for(k=0;k<G.arcnum;k++)
	{
		getchar();
		scanf("%c %c",&ch1,&ch2);
		
		i=LocateVex(ch1,G);j=LocateVex(ch2,G);
		
		ArcNode e;
		e=(ArcNode)malloc(sizeof(Node));
		e->data=j;
		e->next=NULL;
		p=G.AdjList[i].firstarc;
		if(!p)
			G.AdjList[i].firstarc=e;
		
		else
		{
			while(p->next)
				p=p->next;
			p->next=e;
		}
	}
}


void DFS(MGraph G,int i)
{//������������ݹ��㷨 
	ArcNode p;
	visited[i]=1;
	printf("%c ",G.AdjList[i].data);
	p=G.AdjList[i].firstarc;
	while(p)
	{
		if(!visited[p->data])
			DFS(G,p->data);
		p=p->next;
	}
}

void BFS(MGraph G)
{//����������� 
	queue<int>q;
	int i,j;
	ArcNode p;
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			q.push(i);
			printf("%c ",G.AdjList[i].data);
			while(!q.empty())
			{
				p=G.AdjList[q.front()].firstarc;
				while(p)
				{
					if(!visited[p->data])
					{
						visited[p->data]=1;
						printf("%c ",G.AdjList[p->data].data);
						q.push(p->data);
					}
					p=p->next;
				}
				q.pop();
			}
		}
	}
}

void DFSsearch(MGraph G)
{//������������ǵݹ��㷨 
	int i,j;
	stack <int>s;
	ArcNode p;
	memset(visited,0,sizeof(visited));
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			printf("%c ",G.AdjList[i].data);
			
			s.push(i);
			
			p=G.AdjList[i].firstarc;
			while(!s.empty())
			{
				while(p)
				{
					if(!visited[p->data])
					{
						visited[p->data]=1;
						printf("%c ",G.AdjList[p->data]);
						s.push(p->data);
						p=G.AdjList[p->data].firstarc;
					}
					else
						p=p->next;
				}
				p=G.AdjList[s.top()].firstarc;
				s.pop();
			}
		}
	}
}

void FindInDegree(MGraph G,int *indegree)
{
	int i;
	ArcNode p;
	for(i=0;i<G.vexnum;i++)
	{
		p=G.AdjList[i].firstarc;
		while(p)
		{
			indegree[p->data]++;
			p=p->next;
		}
	}
}

int TopologicalSort(MGraph G)
{
	int indegree[MAX]={0};
	int i,j,k;
	FindInDegree(G,indegree);
	
	stack <int>s;
	
	ArcNode p;
	for(i=0;i<G.vexnum;i++)
	{
		if(!indegree[i])
			s.push(i);
	}
	
	int count=0;
	
	while(!s.empty())
	{
		i=s.top();
		s.pop();
		printf("%c ",G.AdjList[i].data);
		count++;
		for(p=G.AdjList[i].firstarc;p;p=p->next)
		{
			k=p->data;
			if(!(--indegree[k]))
				s.push(k);
		}//for
	}//while
	if(count<G.vexnum)
		return 0;
	else
		return 1;
}

int main()
{
	int i,K;
	MGraph G;
	InitGraph(G);
	
	memset(visited,0,sizeof(visited));
	
	ArcNode p;
	p=G.AdjList[0].firstarc;
	
	printf("������������ĵݹ������"); 
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
			DFS(G,i);
	}
	putchar('\n');
	memset(visited,0,sizeof(visited));
	printf("������������ı�����"); 
	BFS(G);
	putchar('\n');

	printf("������������ķǵݹ������"); 
	DFSsearch(G);
	putchar('\n');
	//��������
	printf("������������Ϊ��");
	K=TopologicalSort(G);
	if(K)
		printf("\n��ͼ�Ǹ������޻�ͼ\n");
	else
		printf("\n��ͼ�Ǹ��л�ͼ\n");
	//�ж��������޻�ͼ
	
	return 0;
}
