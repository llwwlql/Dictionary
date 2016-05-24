#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main()
{

	int T,n,i,j,m;
	char str[5],ch[10];
	scanf("%d",&T);
	while(T--)
	{
		queue<int> q;
		stack<int> s;
		scanf("%d",&n);
		scanf("%s",str);
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch);
			if(ch[0]=='I')
			{
				scanf("%d",&m);
				if(str[2]=='F')
					q.push(m);
				else
					s.push(m);
			}
			else
			{
				if(str[2]=='F' && q.empty() ||str[2]=='L'&&s.empty())
				{
					printf("None\n");
					continue;
				}
				if(str[2]=='F')
				{
					printf("%d\n",q.front());
					q.pop();
				}
				else
				{
					printf("%d\n",s.top());
					s.pop();
				}
			}
		}
	}
	
	return 0;
}
