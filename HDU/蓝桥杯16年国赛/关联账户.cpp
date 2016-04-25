#include <stdio.h>
#define N 100

int connected(int* m, int p, int q)
{
	return m[p]==m[q]? 1 : 0;
}

void link(int* m, int p, int q)
{
	int i;
	if(connected(m,p,q)) return;
	int pID = m[p];
	int qID = m[q];
	for(i=0; i<N; i++)
		m[i]=(pID==m[i]) ? qID : m[i];
}

int main()
{
	int m[N];
	int i;
	for(i=0; i<N; i++) m[i] = i; 
	link(m,0,1);
	link(m,1,2); 
	link(m,3,4); 
	link(m,5,6); 
	link(m,6,7); 
	link(m,8,9); 
	link(m,3,7); 
	
	printf("%d ", connected(m,4,7));
	printf("%d ", connected(m,4,5));
	printf("%d ", connected(m,7,9));
	printf("%d ", connected(m,9,2));
	return 0;
}

