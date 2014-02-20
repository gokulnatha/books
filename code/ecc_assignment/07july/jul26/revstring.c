/*	Filename	:	revstring.c
 *	Date		:	26-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to reverse the string using function 
 */

 #include<stdio.h>
 #include<stdlib.h>

 char* revstring(char *s)
 {
	char *r;
 	int i,l=0;
	while(*(s+l)!='\0')
	{
		l++;
 	}
	r=malloc(l*sizeof(char));
	for(i=0;i<l;i++)
	{
		*(r+i)=*(s+l-1-i);
	}
	*(r+i)='\0';
	return r;
 }
	
 int main(void)
 {
 	char *s;
	s=malloc(sizeof(char)*1000);
	printf("\nEnter the string to be reversed: ");
	scanf("%s",s);
	s=revstring(s);
	printf("\nreverse: %s",s);
	printf("\n\n");
	return 0;
 } 
 	
