#include <stdio.h>
int main()
{
	FILE *fin,*fout;
	
	fin=fopen("input.txt","rb");	
	
	fout=fopen("output.txt","wb");
	//wb是写入为二进制文件，观察文件时会看到的是一堆乱码 
	int i;
	int a[15];
	for(i=1;i<=10;i++)
		fscanf(fin,"%d",a+i);	//这是在文件中的读取操作 
	for(i=1;i<=10;i++)
		fprintf(fout,"%d",a+i);	//这是写入到文件中去 
	fclose(fin);
	fclose(fout);
	
	return 0;
}
