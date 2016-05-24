#include <iostream>
#include <math.h>
using namespace std;
int N,M,T,di,dj,escape;
char map[10][10];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
void dfs_search(int si,int sj,int step)
{
	int newi,newj;
	if(si==di && sj==dj && step==T)
		escape=1;
	if(escape==1)
		return;
	int temp=T-step-abs(si-di)-abs(sj-dj);//ºÙ÷¶
	if(temp<0 || temp&1)		//∆Ê≈ººÙ÷¶
		return;
	for(int i=0;i<4;i++)
	{
		newi=si+dir[i][0];
		newj=sj+dir[i][1];
		if(map[newi][newj]!='X')
		{
			map[newi][newj]='X';
			dfs_search(newi,newj,step+1);
			map[newi][newj]='.';
		}
	}
}

int main()
{
	int si,sj;
	while(cin>>N>>M>>T)
	{
		int wall=0;
		if(N==0 && M==0 && T==0)
			break;
		for(int i=0;i<=N;i++)
			map[i][0]=map[i][M+1]='X';
		for(int i=1;i<=M;i++)
			map[0][i]=map[N+1][i]='X';
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='S')
				{si=i;sj=j;}
				else if(map[i][j]=='D')
				{di=i;dj=j;}
				else if(map[i][j]=='X')
					wall++;
			}
			if(T>=N*M-wall)//ºÙ÷¶
			{
				cout<<"NO"<<endl;
				continue;//«Èøˆ¥¶¿Ì∏…æª
			}
			map[si][sj]='X';
			escape=0;
			dfs_search(si,sj,0);
			if(escape==1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
	}
	return 0;
}
