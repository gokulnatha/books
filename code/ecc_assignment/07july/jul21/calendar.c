/*	Filename	:	calendar.c
 *	Date		:	21-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to design the calendar
 */

 #include<stdio.h>
 #include<stdlib.h>	

 int main(void)
 {
 	int i,j,k,h,w=1,ndm,day,rem;
	printf("\n** Monthly Calendar **\n");
	do
	{
		printf("\nEnter the no of days in month(28,29,30,31): ");
		scanf("%d",&ndm);
	}while((ndm!=28)&&(ndm!=29)&&(ndm!=30)&&(ndm!=31));
	do
	{
		printf("Enter the index of the day of week ( 1 to 7 -> Sun to Sat ) : ");
		scanf("%d",&day); 
	}while((day<=0)||(day>7));
	day--;
	printf("\nSun\tMon\tTue\tWed\tThu\tFri\tSat\n");
        for(j=0;j<day;j++)
	{
		printf("\t");
	}
	for(i=0;i<6;i++)
	{
		for(k=w;k<(w+(7-day));k++)
		{
			if(k>ndm)
			{
				printf("\n\n");
				exit(0);
			}
			printf("%d\t",k); 
		}
		w=w+(7-day);
		day=0;
		printf("\n");
	}
	printf("\n\n");
	return 0;
 }
	
	

