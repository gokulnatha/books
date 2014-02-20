/*	Filename	:	revparstring.c
 *	Date		:	26-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to reverse the string partially using function 
 */

 #include<stdio.h>
 #include<stdlib.h>

 char* revparstring(char *s,int p)
 {
	char *r;
 	int i,l=0;
	while(*(s+l)!='\0')
	{
		l++;
 	}
	r=malloc(l*sizeof(char));
	for(i=0;i<p;i++)
	{
		*(r+i)=*(s+p-1-i);
	}
	for(i=p;i<l;i++)
	{
		*(r+i)=*(s+i);	
	}
	*(r+i)='\0';
	return r;
 }
	
 int main(void)
 {
 	char *s;
	int p;
	s=malloc(sizeof(char)*100);
	printf("\nEnter the string to be reversed: ");
	scanf("%s",s);
	printf("\nEnter the position: ");
	scanf("%d",&p);
	printf("\nReverse partially: %s",revparstring(s,p));
	return 0;
 } 
 	
