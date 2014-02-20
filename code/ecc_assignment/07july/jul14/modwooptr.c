/*	FileName	: modwooptr.c
 *	Date    	: 14-07-2010
 *	Author		: Stalin Srinivasan.S
 *	Description	: to get the remainder without using operator
 */

 #include<stdio.h>
 #include<math.h>

 int main(void)
 {
       long long divd,divs,r;
	printf("\nEnter the dividend: ");
	scanf("%qi",&divd);
        if((divd>0)&&(divd<4294967296))
	{
	r=divd&1;
	if(!r) 
	{
		printf("\nIt is even and remainder is %qi",r);
	}
	else
	{
		printf("\nIt is odd and remainder is %qi",r);
	}
	}
	else
	{
		printf("\nOut of range");
	}
	printf("\n\n");
	return 0;
 }	
 	 
