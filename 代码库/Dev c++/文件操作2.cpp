#include <stdio.h>
int main()
{
	FILE *fin,*fout;
	
	fin=fopen("input.txt","rb");	
	
	fout=fopen("output.txt","wb");
	//wb��д��Ϊ�������ļ����۲��ļ�ʱ�ῴ������һ������ 
	int i;
	int a[15];
	for(i=1;i<=10;i++)
		fscanf(fin,"%d",a+i);	//�������ļ��еĶ�ȡ���� 
	for(i=1;i<=10;i++)
		fprintf(fout,"%d",a+i);	//����д�뵽�ļ���ȥ 
	fclose(fin);
	fclose(fout);
	
	return 0;
}
