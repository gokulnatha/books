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
	int i,n,am[2]={0,1},flag=0;
	printf("\nEnter the no of elements to be operated: ");
	scanf("%d",&n);
	p=malloc(n*sizeof(struct list));
        for(i=0;i<n;i++)
	{
		scanf("%d",&(p+i)->a);
	}
        funcoddev(p,n,2,am);	
	for(i=0;i<n;i++)
	{
		if((p+i)->s==2)
		{
			flag++;
			(p+i)->f=0;
			am[0]+=(p+i)->a;
			am[1]*=(p+i)->a;	
		}
	}
	if(flag==0)
	{
		printf("\nYour list has no even nos\n");
		exit(0);
	}
	printf("\nThere are %d even nos in your list\n\n",flag);
	printf("\nsum: %d, Mul: %d",am[0],am[1]);
	printf("\n\n");
	return 0;
}
