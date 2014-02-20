/*	File Name  : findsize.c
 *	Date       : 13-07-2010
 *	Author     : Stalin Srinivasan.S 
 *	Description: to find the size of the basic data types
 */

	#include<stdio.h>
	#include<math.h>

	int main(void)
	{
		int s,choice;
		double r;
		printf("\nChoose the type be analysed for its range\n");
		printf("\n1.int 2.char 3.float 4.double 5.void -- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nSize of int type is %d",sizeof(int));	
				s=8*sizeof(int);
				r=pow(2,s);
				printf("\nRange of int: 0 to %.0lf",r-1);
				r=r/2;
				printf("\nRange of signed int: %.0lf to %.0lf",-r,r-1);
				s=8*sizeof(short int);
				r=pow(2,s);
				printf("\nRange of short int: 0 to  %.0lf",r-1); 
				break;
			}
			case 2:
			{
				printf("\nSize of char type is %d",sizeof(char));
				s=8*sizeof(char);
				r=pow(2,s);
				printf("\nRange of char: 0 to %.0lf",r-1);
				r=r/2;
				printf("\nRange of signed char: %.0lf to %.0lf",-r,r-1);
				break;
			}
			case 3:
			{
				printf("\nSize of float type is %d",sizeof(float));
				s=8*sizeof(float);
				r=pow(2,s);
				printf("\nRange of float: 0 to %.0lf",r-1);
				break;
			}
			case 4:
			{
				printf("\nSize of double type is %d",sizeof(double));
				s=8*sizeof(double);
				r=pow(2,s);
				printf("\nRange of double type: 0 to %.0lf",r-1);
				break;
			}
			case 5:
			{
				printf("\nSize of void type is %d",sizeof(void));
				s=8*sizeof(void);
				r=pow(2,s);
				printf("\nRange of  void type: 0 to %.0lf",r-1);
				break;
			}
			default:
			{
				printf("\nPlease enter the valid choice");
				break;
			}
		}
		printf("\n\n");
		return 0;
	}	
