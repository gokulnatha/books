/*	Filename	:	preproc2.c
 *	Date		:	29-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to observe the preprocessor directives  
 */

 #include<stdio.h>
 #define COT(a,b) a##b
 int main(void)
 {
	printf("\nResult: %d",COT(1,2)+8);
	return 0;
 }
