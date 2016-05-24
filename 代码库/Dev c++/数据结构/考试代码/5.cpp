#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct mgraph{
	int vex,arc;
	int elem[105][105];
}MGraph;

typedef struct arcnode{
	int data;
	int next_vex;
	struct arcnode *next;
}ArcNode;

typedef struct vex{
	ArcNode *firstarc;
}Vex;

typedef struct ALgraph{
	int vex,arc;
	Vex elem[105];
}ALGraph;

void createMGraph(MGraph &G)
{	
	int i,a,b,c;
	printf("请输入结点数和边数：");
	scanf("%d %d",&G.vex,&G.arc);
	for(i=1;i<=G.arc;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		G.elem[a][b]=c;
		G.elem[b][a]=c;
	}
}

void changeMtoAL(MGraph &G1,ALGraph &G2)
{
	int i,j;
	ArcNode *p,*s;
	G2.arc=G1.arc;
	G2.vex=G1.vex;
	
	for(i=1;i<=G2.vex;i++)
		G2.elem[i].firstarc=NULL;
	
	for(i=1;i<=G1.vex;i++)
	{
		for(j=1;j<=G1.vex;j++)
		{
			if(G1.elem[i][j])
			{
				p=G2.elem[i].firstarc;
				s=(ArcNode *)malloc(sizeof(ArcNode));
				s->data=G1.elem[i][j];
				s->next_vex=j;
				s->next=NULL;
				if(p)
				{
					while(p->next)
						p=p->next;
					p->next=s;
				}
				else
					G2.elem[i].firstarc=s;	
			}
		}
	}
	
}

int main()
{
	int i,j;
	MGraph G1;
	ALGraph G2;
	ArcNode *p;
	memset(G1.elem,0,sizeof(G1.elem));
	createMGraph(G1);
	changeMtoAL(G1,G2);
	for(i=1;i<=G2.vex;i++)
	{
		p=G2.elem[i].firstarc;
		while(p)
		{
			printf("%d %d %d\n",i,p->next_vex,p->data);
			p=p->next;
		}
	}

	return 0;
}
