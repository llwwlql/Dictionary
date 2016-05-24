#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{ 
	return *(int *)a-*(int *)b;
}

int main()
{
	int i,j;
	int a[10]={2,4,6,7,9,10,11,14,18,30};
	qsort(a,10,sizeof(int),cmp);
	if(bsearch(a[2],a,sizeof(a),sizeof(int),cmp))
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
