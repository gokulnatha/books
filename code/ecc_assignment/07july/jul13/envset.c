/*      File Name   : envset.c
 *	Date        : 13-07-2010
 *	Author      : Stalin Srinivasan.S
 *	Description : to set the values for environmental variables
 */

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[],char *environ[])
{
	int r;
	char *p;
	r=setenv("nisar","nec",1); /* setting env. variable nisar and its value */
	if(!r)
	{
		printf("\nEnvironment variable set successfully");
	}
	else
	{
		printf("\nSorry to say, not set. better luck next time");
	}
	p=getenv("nisar");
	printf("\nYours environment variable value is %s\n",p);
	r=unsetenv("nisar"); /* unsetting env. variable nisar */
	if(!r)
	{
		printf("\nUnset successfully");
		p=getenv("nisar");
		printf("\nyours unset environment variable is %s",p);
	}
	else
	{
		printf("try again");
	}
	printf("\n\n");
	return 0;
}
