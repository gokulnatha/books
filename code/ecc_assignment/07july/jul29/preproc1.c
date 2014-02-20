/*	Filename	:	preproc1.c
 *	Date		:	29-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to observe the preprocessor directives  
 */

 #include<stdio.h>
 #ifdef 
 	#error "debug"
 #else
 	#error "produ"
 #endif
 #define MAX 1 
 #define SWAP(x,y) x=x+y,y=x-y,x=x-y
 #define SUB(x,y) (x)-(y)
 
 int main(void)
 {
	int i,x=5,y=3;
	for(i=1;i<=MAX;i++)
	{
		printf("\nResult: %d",SUB(x,y));
	}
	SWAP(x,y);
	printf("\nafter swap: x:%d y:%d\n",x,y);
	return 0;
 }
