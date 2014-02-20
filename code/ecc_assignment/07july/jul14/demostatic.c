/*	Filename	:	demostatic.c
 *	Date		:	14-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate static variable
 */

 #include<stdio.h>
 #include<math.h>
 #include "demostatic.h"

 extern int incstat(void);
 int var;

 int main(void)
 {
 	incstat();
	incstat();
	incstat();
	int z = var++;
	return 0;
 }
