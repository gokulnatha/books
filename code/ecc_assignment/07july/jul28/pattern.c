/*	Filename	:	pattern.c
 *	Date		:	28-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to give pattern for given letters 
 */

 #include<stdio.h>
 #include<stdlib.h>

 char pattern(char ch)
 {
		if((ch=='A')||(ch=='a'))
		{
			return ch;
		}
		else if((ch>65)&&(ch<=122))
		{
			printf("%c%c",pattern(ch-1),ch);
			pattern(ch-1);
		}
		else
		{
			printf("\npls,enter only alphabets");
			return 0;
		}
 }
	
 int main(void)
 {
	printf("\nEnter a character to be patterned: ");
	printf("%c",pattern(getchar()));
	printf("\n");
	return 0;
 }

 


