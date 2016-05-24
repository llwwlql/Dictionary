#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INIT 10
typedef struct{
			int *base;
			int *top;
			int stackzise;
}SqStack;
int InitStack(SqStack &S){

	S.base=(int*)malloc(MAX * sizeof(int));
	if(!S.base)
		return 0;
	S.top=S.base;
	S.stackzise=MAX;
	return 1;

}
int GetTop(SqStack S,int &e){

	if(S.top==S.base)
		return 0;
	e=*(S.top-1);
	return 1;

}
int Push(SqStack &S,int e){

	if(S.top-S.base>=S.stackzise){
		
		S.base=(int*)realloc(S.base,(S.stackzise+INIT)*sizeof(int));
		if(!S.base)
			return 0;
		S.top=S.base+S.stackzise;
		S.stackzise+=INIT;

	}
        *S.top++=e;
		return 1;
} 
int Pop(SqStack &S,int e){

	if(S.top==S.base)
	return 0;
	e=*--S.top;
	return 1;


}


void conversion(SqStack S){
	int n,j;
      InitStack(S);
	  printf("请输入数字");
	  scanf("%d",n);
	   printf("请输入进制");
	     scanf("%d",j);
		 while(n){
		 
			 Push(S,n%j);
		 
		 }

		 while(!GetTop(S,e)){
		 
		 Pop(S,e);
		 printf("%d",e);
		 
		 }

}
int main()
{
	
	SqStack S;
	InitStack(SqStack S);
	int e;
	return 0;
}

