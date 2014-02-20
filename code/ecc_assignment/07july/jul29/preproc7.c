/*	Filename	:	preproc5.c
 *	Date		:	29-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to observe preprocessor directives
 */

 #ifdef __Windows__
	#include<windows.h>
 #else	__LINUX__
	#include<stdio.h>
 #endif

 int main(void)
 {
	printf("\nMax: ");
	return 0;
 }


