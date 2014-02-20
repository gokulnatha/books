/*	Filename	:	preproc3.c
 *	Date		:	29-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to observe preprocessor directives
 */

 #include<stdio.h>
 #include<stdlib.h>

 int main(void)
 {
	int x=1;
 	#if x<2
		printf("\nYes you are correct\n");
	#else
		printf("\nNo you are wrong\n");
	#endif
	return 0;
 }


