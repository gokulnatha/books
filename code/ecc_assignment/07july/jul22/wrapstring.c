/*	Filename	:	wrapstring.c
 *	Date		:	22-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to wrap the string as you wish
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 int main(void)
 {
	char s[80],c[80];
	int i,j,l,w;
	printf("\nEnter the string to be wrapped: ");
	scanf("%s",s);
	l=strlen(s);
	printf("\nEnter the wrap around value: ");
	scanf("%d",&w);
	for(i=0;i<w;i++)
	{
		c[i]=s[l-w+i];
	}
	c[i]='\0';
        for(i=l-w;i>=0;i--)
	{
		s[i+w]=s[i];
	}
	for(i=0;i<w;i++)
	{
		s[i]=c[i];
	}
	s[l]='\0';
	printf("\n\nafter Wrapped: %s",s);
	printf("\n\n");
	return 0;
 }
 

