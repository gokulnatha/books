/*	Filename	:	regvar.c
 *	Date		:	14-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate static variable
 */

 #include<stdio.h>
 #include<math.h>

 int main(void)
 {
 	register int c=5;
	int *p;
	p=&c;       
	printf("%d",p);
	return 0;
 }
