#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int map[35][35];
int a[1005];
typedef struct node{
	int data;
	struct node *next;
}Link;
int main()
{
	int n;
	int T,i,j;
	while(scanf("%d",&n),n)
	{
		int sum=0,dir=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",map[i]+j);
		}
		char str[5];
		int d;
		memset(a,0,sizeof(a));
		
		Link *head,*cur,*p,*temp;
		int count=0;
		
		scanf("%d",&T);
		while(T--)
		{
			scanf("%s",str);
			if(strcmp(str,"UP")==0)
			{ 
				scanf("%d",&d);
				if(count<7 && d!=dir)	//�ж�����2��3 
				{
					p=(Link *)malloc(sizeof(Link));
					p->next=NULL;
					p->data=d;			//����һ���˵���Ϣ 
					a[d]++;				//��dλ�õ��˼�1 
					if(count==0)
						head=cur=p;
					else
					{
						cur->next=p;
						cur=cur->next;
					}
					count++;
				}
			}
			else if(strcmp(str,"GO")==0 && count>0)
			{
				p=head;			//�����ϳ������³� 
				d=p->data;
				sum+=map[dir][d];
				dir=d;
				head=head->next;
				free(p);
				a[d]--;
				count--;
				while(a[d])		//��ͬĿ�ĵص����³� 
				{
					p=head;
					if(head->data==d)	//������ͬĿ�ĵص�����ͷָ��ָ�� 
					{
						head=head->next;
						free(p);
					}
					else				//������ͬĿ�ĵص��˲���ͷָ��ָ��
					{
						while(p->next->data!=0)
							p=p->next;
						temp=p->next;
						p->next=temp->next;
						free(temp);
					}
					a[d]--;
					count--;
				}
			}
			
		}		
		printf("%d\n",sum);
	}
	
	return 0;
}
