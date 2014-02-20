/*	Filename	:	vowel.c
 *	Date		:	15-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to spot the vowels in given string 
 */

 #include<stdio.h>
 #include<math.h>
 #include<string.h>
 
 int main(void)
 {
 	char p[20];
	int s=0,a=0,e=0,i=0,u=0,o=0;
	printf("\nEnter the string: ");
	scanf("%s",p);
	while(p[s])
	{
		switch(p[s])
		{
			case 'a':
			case 'A':
			{
				a++;
				break;	
			}
		        case 'e':
			case 'E':
			{
				e++;
				break;	
			}
			case 'I':
			case 'i':
			{
				i++;
				break;
			}
			case 'O':
			case 'o':
			{
				o++;
				break;
			}
			case 'U':
			case 'u':
			{
				u++;
				break;
			}
			default:
			{
			}
		}
		s++;
	}	
        if((a==0)&&(e==0)&&(i==0)&&(o==0)&&(u==0))
	{
		printf("\nThere is no vowels in your string");
	}
	else
	{
		printf("\nNo of times vowels spotted in your string: %d",a+e+i+o+u);
		printf("\n\na=%d\te=%d\ti=%d\to=%d\tu=%d\n\n",a,e,i,o,u);
	}
	printf("\n\n");
	return 0;
 }		
