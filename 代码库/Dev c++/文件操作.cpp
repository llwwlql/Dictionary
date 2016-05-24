#include <stdio.h>
int main()
{
	freopen("E:\\input.txt","r",stdin);
	freopen("E:\\output.txt","w",stdout);
	int i;
	int a[15];
	for(i=1;i<=10;i++) 
		scanf("%d",&a[i]);
	
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
