/*	Filename	:	disp.c
 *	Date		:	02-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to write record and operate using files concept
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct emp
 {
	char name[40];
	int age;
	int empcode;
 };

 void disp(char *filename)
 {
	FILE *fp;
	struct emp *a;
	fp=fopen(filename,"r");					//opening the file in read mode
	while(feof(fp)==0)
	{
		a=malloc(sizeof(struct emp));
		fread(a,sizeof(struct emp),1,fp);		//read and display record by record
		printf("\nName: %s",a->name); 		
		printf("\nAge: %d",a->age); 		
		printf("\nEmpcode: %d",a->empcode); 		
		free(a);
	}
	fclose(fp);
 	return;
 }
		
