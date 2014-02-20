/*	Filename	:	fourfunc.c
 *	Date		:	27-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to make four function and make use of function pointers
 */

 #include<stdio.h>
 #include<stdlib.h>
	
 int lengthof(char *s) 
 {
	int l=0;
	while(*(s+l))
	{
		l++;
	}
	return l;
 }
	
 char* reverse(char *s,int l)
 {
	char *r;
	int i;
	r=malloc(l*sizeof(char));
	for(i=0;i<l;i++)
	{	
		*(r+i)=*(s+l-1-i);
	}
	*(r+i)='\0';
	return r;
 }
	
 char* concatthis(char *s1,char *s2)
 {
	char *concat;
	int i,l1,l2;
	l1=lengthof(s1);
	l2=lengthof(s2);
	concat=malloc((l1+l2)*sizeof(char));
        for(i=0;i<(l1+l2);i++)
	{
		if(i<l1)
		{
			*(concat+i)=*(s1+i);
		}
		else
		{
			*(concat+i)=*(s2+i-l1);
		}
	}
	*(concat+i)='\0';
	return concat;
 }

 int vowelscount(char *s)
 {
	int i,l,vow=0;
	l=lengthof(s);
	for(i=0;i<l;i++)
	{
		switch(*(s+i))
		{
			case 'a':
			case 'A':
			{
				vow++;
				break;
			}
			case 'e':
			case 'E':
			{
				vow++;
				break;
			}
			case 'i':
			case 'I':
			{
				vow++;
				break;
			}
			case 'o':
			case 'O':
			{
				vow++;
				break;
			}
			case 'u':
			case 'U':
			{
				vow++;
				break;
			}
			default:
			{
				break;
			}
		}
	}
	return vow;
 }
	
	 
 int main(void)
 {
	char *s;
	int(*fpt)(char*);
	s=malloc(50);
	printf("\nEnter the string1: ");
	scanf("%s",s);
	fpt=vowelscount;
	printf("\nVowels in your string: %d",fpt(concatthis(s,reverse(s,lengthof(s))))/2);
	printf("\n\n");
	return 0;
 }
