#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	map <string,int> a;
	int i,j;
	
	scanf("%d",&T);
	while(T--)
	{
		string str;
		cin>>str;
		sort(str.begin(),str.end());
		a[str]++;
		printf("%d\n",a[str]-1);
	}
	return 0;
}
