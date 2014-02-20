/*	Filename	:	asc.c
 *	Date		:	20-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to sort the elements in array
 */

 #include<stdio.h>
 #include<math.h>
 void swap(int*,int*);
 int main(void)
 {
	int a[40],i,j,n,t;
	printf("\nEnter the no of series to be sorted: ");
	scanf("%d",&n);
	printf("\nEnter the nos to be sorted: ");
	for(i=0;i<n;i++)
        {	
		if(!i)
		{
			scanf("%d",&a[i]);
			continue;
		}
		scanf("%d",&a[i]);
		for(j=0;j<i;j++)
		{
		if(a[j]>a[i])
		{
			swap(&a[j],&a[i]);
		}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n\n");
	return 0;
 }
 void swap(int *a,int *b)
 {
	int t;
	t=*a;
	*a=*b;	
	*b=t;
 }
