/*	Filename	:	demostat.c
 *	Date		:	14-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate static variable
 */

 #include<stdio.h>
 #include<math.h>

 int main(void)
 {
 	float n,i,j,q;
	printf("Enter any number to get square root of it: ");
	scanf("%f",&n);
	i=powf(n,0.5);
        printf("\n\nSquare root of given number: %f",i);
	printf("\n\n");
	return 0;
 } 

 	
