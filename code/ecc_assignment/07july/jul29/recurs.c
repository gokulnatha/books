/*	Filename	:       recurspuzzle.c
 *	Date		:	29-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to construct the puzzle using recursive function 
 */

 #include<stdio.h>
 #include<stdlib.h>
 int count=0;
 void recpuz(int *a,int *store,int count)
 {
	if(count<12)
	{
	if(*a==0)
	{
		printf("\nyou win the match");
		return;
	}
	else if(((10-(a-store))>=*a))
      	{
		count++;
		printf("\nR: %d",*a);	
		recpuz(a+=*a,store,count);
	}
	else if((a-store)>=*a)  
	{	
		count++;
		printf("\nL: %d",*a);
		recpuz(a-=*a,store,count);
	}
	else
	{
		printf("\nJust miss!");
		return;
	}
	}
	else
	{
		printf("\n\nend in an indefinite loop.Try again with new series\n");
		return;
	}	
 }
 
 int main(void)
 {
	srand(times(NULL));
	int *a,*store,i;
	a=malloc(10*sizeof(int));
	for(i=0;i<9;i++)
		*(a+i)=rand()%9+1;
	for(i=0;i<10;i++)
		printf("%d\t",*(a+i));
	store=a;
	recpuz(a,store,count);
	printf("\n\n");
	return 0;
 }
