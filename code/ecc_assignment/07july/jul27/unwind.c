/*	File Name  : unwind.c
 *	Date       : 27-07-2010
 *	Author     : Stalin Srinivasan.S 
 *	Description: to read a character by character and unwinds 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i=0;

void read(char *a,int l)
{
	if(l>0)
	{
		getchar();
		scanf("%c",a+i);		
		i++;
		read(a,l-1);
	}
	*(a+i)='\0';
}

void unwind(char *a,int n,int l)
{
	if(n<l)
	{
		printf("%c\n",*(a+n));
		unwind(a,n+1,l);
	}
}

int main(void)
{
	static int n;
	int l;
	char *a;
	printf("Enter the length of the string:\n");
	scanf("%d",&l);
	a=malloc(l*sizeof(char));
	read(a,l);
	printf("%s\n",a);
	free(a);
	a=malloc(50);
	printf("Enter a string to unwind:\n");
	scanf("%s",a);
	unwind(a,n,strlen(a));
	free(a); 
	return 0;
}


