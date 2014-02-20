/*	Filename	:	funcoddev.c
 *	Date		:	26-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to detect the odd and even nos using functions
 */

 struct list
 {
	int a,s,f;
 }; 

 void funcoddev(struct list *p,int n,int op,int *am)
 {
	int i;
	for(i=0;i<n;i++)
		if((p+i)->a%2==0)
			(p+i)->s=2;
		else
			(p+i)->s=1;
 }

 

