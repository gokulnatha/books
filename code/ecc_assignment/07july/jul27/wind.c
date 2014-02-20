/*	File Name  : unwind.c
 *	Date       : 27-07-2010
 *	Author     : Stalin Srinivasan.S 
 *	Description: to read a character by character and unwinds 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static int i;

void read(char *a)
{
	scanf("%c",a+i);		
	if(*a=='*')
	{
		*(a+i)='\0';
		return;
	}
	else
	{
		getchar();
		i++;
		read(a+i);
	}
}

int main(void)
{
	static int n;
	char *a;
	a=malloc(50);
	printf("\nEnter the string char by char (end with *): ");
	read(a);
	printf("%s\n",a);
	free(a);
	a=malloc(50);
	printf("Enter a string to unwind:\n");
	scanf("%s",a);
	unwind(a,n,strlen(a));
	free(a); 
	return 0;
}


