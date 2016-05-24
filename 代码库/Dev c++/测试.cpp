#include <iostream>
#include <string.h> 
using namespace std;
#include <stack>
#include <vector>
const int MAX=10000+10;
vector<int >map[MAX];//�����ڽӱ�
stack<int >s;//�����µ��ĵ���ջ
int Dfs[MAX];//���ʵĽڵ����//u��u�������ܹ�׷�ݵ��������ջ�нڵ�����(ʱ���)
int Low[MAX];//���ڵ�������ֵ�ʱ���//�ڵ�u���������(ʱ���)
bool isStack[MAX];//�Ƿ���ջ��
int used[MAX];//��Ǹõ������ĸ���ͨ����
int top;//ʱ���
int newflag;//��ͨ����
void init()//���ֳ�ʼ��
{
    memset(Dfs,0,sizeof(Dfs));
    memset(Low,0,sizeof(Low));
    memset(isStack,false,sizeof(isStack));
    memset(used,0,sizeof(used));
    for(int i=0;i<MAX;i++)
    {
        map[i].clear();
    }
    while(!s.empty())
    {
        s.pop();
    }
    newflag=0;
    top=0;
}
void tarjan(int u)
{
    Dfs[u]=Low[u]=++top;//ʱ���
    isStack[u]=true;//����ջ��
    s.push(u);
    for(int x=0;x<map[u].size();x++)
    {
        int v=map[u][x];
        if(!Dfs[v])//�ж��Ƿ���¹�
        {
            tarjan(v);//�ݹ飬��������
            if(Low[v]<Low[u])//�������ӽڵ����ҵ��ȸ��ڵ����ڵ㣬���л�
            {
                Low[u]=Low[v];
            }
        }
        else if(isStack[v]&&Dfs[v]<Low[u])
        {
            Low[u]=Dfs[v];
        }
    }
    if(Dfs[u]==Low[u])//�Ҳ����ڽӵ��ˣ����ҵ���ͨ�����Ľ�������
    {
        newflag++;
        int x;
        do
        {
            x=s.top();
            isStack[x]=false;
            used[x]=newflag;
            s.pop();
        }while(x!=u);//�����ͨ����
    }
    return;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        init();
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            map[x].push_back(y);
        }
        for(int i=1;i<=n;i++)
        {
            if(!Dfs[i])
            {
                tarjan(i);
            }
        }
        if(newflag==1)
        {
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
