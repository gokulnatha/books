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
		printf("\nChoose the type be analysed for its size: ");
		printf("\n1.int 2.char 3.float 4.double 5.void -- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nSize of int type is %d",sizeof(int));
				printf("\nSize of short int is %d",sizeof(short int));
				printf("\nSize of long int is %d",sizeof(long int));
				printf("\nSize of signed int is %d",sizeof(signed int));
				break;
			}
			case 2:
			{
				printf("\nSize of char type is %d",sizeof(char));
				printf("\nSize of signed char type is %d",sizeof(signed char));
				break;
			}
			case 3:
			{
				printf("\nSize of float type is %d",sizeof(float));
				break;
			}
			case 4:
			{
				printf("\nSize of double type is %d",sizeof(double));
				printf("\nSize of long double is %d",sizeof(long double));  
				break;
			}
			case 5:
			{
				printf("\nSize of void type is %d",sizeof(void));
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
