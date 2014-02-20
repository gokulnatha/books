/*	File Name      : env.c
 *	Date           : 13-07-2010
 *	Author	       : Stalin Srinivasan.S
 *	Description    : to display the environment variables
 */

#include<stdio.h>
#include<stdlib.h>

	int main(int argc,char *argv[],char *environ[]) /* each environ variable be element of array of strings */
	{
		int i=0;
		while(environ[i]!=NULL)
		{
			printf("%s\n",environ[i]);
			i++;
		}
		return 0;
	}
