/*	Filename	:	demostaticglobal.c
 *	Date		:	14-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate static variable
 */

 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 
 int main(void)
 {
	char s[30],tr,tbr;
        int i,j,p,l,f=0;
	printf("\nEnter the string: ");
	scanf("%s",s);
	getchar();
	printf("\nEnter the character to be replaced: ");
	scanf("%c",&tbr);
	getchar();
	printf("\nEnter the character to replace: ");
	scanf("%c",&tr);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]==tbr)
		{	
		        s[i]=tr;	
			f++;
		}
	}
	if(!f)
	{
		printf("Your mentioned character is not available");
		exit(0);
	}
	else
	{
		printf("\nMentioned character available %d times",f);
		printf("\nAfter replacement : %s",s);
	}
	printf("\n\n");
	return 0;
 }	
		

