/*	Filename	:	1.c
 *	Date		:	26-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to calculate factorial
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include "funcoddev.c"

 int main(void)
 {
	struct list *p;
	int i,j,n,am[2]={0,0},flag=0;
	printf("\nEnter the no of elements to be operated: ");
	scanf("%d",&n);
	p=malloc(n*sizeof(struct list));
        for(i=0;i<n;i++)
	{
		scanf("%d",&(p+i)->a);
	}
        funcoddev(p,n,1,am);	
        for(i=0;i<n;i++)
	{
		if((p+i)->s==1)	
		{
			flag++;
		        (p+i)->f=1;	
			for(j=1;j<=(p+i)->a;j++)
			{
				(p+i)->f*=j;
			}
			printf("no: %d - Factorial: %d\n",(p+i)->a,(p+i)->f);
		}
	}
	printf("\nTotally, there are %d odd nos in your list\n\n",flag);
	if(flag==0)
	{
		printf("\nYour list has no odd nos\n");
	}
	printf("\n\n");
	return 0;
 }
