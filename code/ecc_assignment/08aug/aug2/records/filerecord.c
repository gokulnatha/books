/*	Filename	:	filerecord.c
 *	Date		:	02-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to write record and operate using files concept
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include "disp.c"
 #include "seekrev.c"
 #include "seekalt.c"
 #include "update.c"

 int main(void)
 {
	FILE *fp;
	struct emp *a;
	int i=0,n,choice,ch;
	char filename[10]="emprec.c";
	do
	{ 
	printf("\n1.Appending 2.Display 3.Seekrev 4.Seekalternate 5.Update 6.Overwriting \n");		//getting choice of operation
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
			fp=fopen(filename,"a+");						//opening the file in append mode
			printf("\nEnter no of employees to be recorded: ");
			scanf("%d",&n);
			printf("\nEnter employee records to be inserted: ");
			if(fp!=NULL)
			{
				for(i=0;i<n;i++)
				{
					a=malloc(sizeof(struct emp));
					printf("\nEmployee %d",i+1);
					printf("\nName: ");
					scanf("%s",a->name);
					printf("\nAge: ");
					scanf("%d",&a->age);
					printf("\nEmpcode: ");
					scanf("%d",&a->empcode);
					fwrite(a,sizeof(struct emp),1,fp);			// getting record in buffer and write to file using fwrite()
					free(a);
				}
			}
			fclose(fp);
			break;
		}
		case 2:
		{
			disp(filename);
			break;
		}
		case 3:
		{
			seekrev(filename);
			break;
		}
		case 4:
		{
			seekalt(filename);
			break;
		}
		case 5:
		{
			update(filename);
			break;
		}
		case 6:
		{
			fp=fopen(filename,"w+");						//opening the file in write+ mode for overwriting 
			printf("\nEnter no of employees to be recorded: ");
			scanf("%d",&n);
			printf("\nEnter employee records to be inserted: ");
			if(fp!=NULL)
			{
				for(i=0;i<n;i++)
				{
					a=malloc(sizeof(struct emp));
					printf("\nEmployee %d",i+1);
					printf("\nName: ");
					scanf("%s",a->name);
					printf("\nAge: ");
					scanf("%d",&a->age);
					printf("\nEmpcode: ");
					scanf("%d",&a->empcode);
					fwrite(a,sizeof(struct emp),1,fp);		 // getting record in buffer and write to file using fwrite()
					free(a);
				}
			}
			fclose(fp);
			break;
		}
		default:
		{
			exit(0);
			break;
		}
	}
	printf("\nPress 1 to continue...:");
	scanf("%d",&ch);
	}while(ch==1);
 	return 0;
 }
	
