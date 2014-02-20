/*	File Name  : cmdarg.c
 *	Date       : 13-07-2010
 *	Author     : Stalin Srinivasan.S
 *	Description: To demonstrate command line arguments
 */

#include<stdio.h>

	int main(int argc, char *argv[])
	{
		int j;
		printf("no of commandline arg is %d",argc-1); /* since exe file also considered as a cmd lin arg */
		if(argc==1)
		{
			printf("\nNo command line arguments");
		}
		else
		{
			for(j=1;j<argc;j++)
			{
				printf("\n%s",argv[j]);
				printf("\n");
			}
		}
		printf("\n\n");
		return 0;
	}
