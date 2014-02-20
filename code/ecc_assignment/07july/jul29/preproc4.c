/*	Filename	:	preproc4.c
 *	Date		:	29-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to observe preprocessor directives
 */

 #include<stdio.h>
 #include<stdlib.h>

 #define MAX 5
 #ifdef MAX
	#undef	MAX 
 #endif
 #ifndef MAX
	#define MAX 6
 #endif

 int main(void)
 {
	printf("\nMax: %d",MAX);
	return 0;
 }


