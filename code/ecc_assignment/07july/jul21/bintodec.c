/*	Filename	:	bintodec.c
 *	Date		:	21-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to convert binary to decimal value 
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
	
 int main(void)
 {
 	int i,j,n,c=0,s;
	printf("\nEnter the binary no to be converted: ");
	scanf("%d",&n);
	i=0;
	while(n!=0)
	{
		s=n%10;
		if(s==1)
		{
			c+=pow(2,i);
		}
		else if(s!=0) 
		{
			printf("\nPls enter the binary value ( 0s and 1s )");
			exit(0);
		}
		n/=10;
		i++;
	}
	printf("\nDecimal value: %d",c);
	printf("\n\n");
	return 0;
 }
				
		

