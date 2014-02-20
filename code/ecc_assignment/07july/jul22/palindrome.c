/*	Filename	:	palindrome.c
 *	Date		:	22-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to verify the string palindrome or not
 */

 #include<stdio.h>

 int main(void)
 {
	char s[80];
	int i,j=0,l=0;
	printf("\nEnter the string: ");
	scanf("%s",s);
	while(s[l])
	{
		l++;
	}
	l--;
        for(i=0;i<l;i++)
	{
		if(s[i]==s[l-i])
		{
			j++;
		}
	}
	if(j!=l)
	{
		printf("\n%s is non palindrome\n\n",s);
		return 0;
	}
	printf("\n%s is palindrome",s);
	printf("\n\n");
	return 0;
 }	
	
				
	
	


