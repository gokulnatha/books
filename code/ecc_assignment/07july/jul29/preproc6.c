/*	Filename	:	preproc6.c
 *	Date		:	29-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to observe preprocessor directives
 */

 #include<stdio.h>
 #include<stdlib.h>

 int main(void)
 {
	printf("\nLine is: %d\n",__LINE__);
	printf("\nFilename is: %s\n",__FILE__);
	printf("\nTime is : %s\n",__TIME__);
	printf("\nDATE is: %s\n",__DATE__);
	printf("\nANSI C: %d\n",__STDC__); 
	return 0;
 }


