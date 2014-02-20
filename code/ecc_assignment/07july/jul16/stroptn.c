/*	Filename	:	stroptn.c
 *	Date		:	16-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to perform comparison and finding length operation in string
 */

 #include<stdio.h>
 #include<math.h>
 
 int main(void)
 {
	char s1[20],s2[20];
	int i,l;
	printf("\n\nEnter the two  Strings:\n");
	scanf("%s\t%s",s1,s2);
	for(i=0;s1[i]!='\0';i++);
	l=i;
	for(i=0;s2[i]!='\0';i++);
	printf("\n\nLength of String1: %d",l);
	printf("\n\nLength of String2: %d",i);
        if(l==i)
	{
		for(i=0;((s1[i]==s2[i])&&(i<l));i++);
		if(i==l)
		{
			printf("\n\nStrings are equal in both length and contents");
		}
		else
		{
			printf("\n\nStrings are not equal but equal in length");
		}
	}
	else if(l>i)
	{
		printf("\n\nStrings are not equal\n\tString1 is bigger");
	}
        else
	{
		printf("\n\nStrings are not equal\n\tString2 is bigger");
	}
	printf("\n\n");
	return 0;
 }
	
		
