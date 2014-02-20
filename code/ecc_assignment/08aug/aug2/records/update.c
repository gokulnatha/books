/*	Filename	:	update.c
 *	Date		:	03-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to update the record in files
 */

 void update(char *filename)
 {
	FILE *fp;
	struct emp *a;
	int i,f,pos;
	printf("\nEnter ur precord position to be updated: ");        //get the position to be displayed
	scanf("%d",&pos);
	fp=fopen(filename,"r+");
	fseek(fp,sizeof(struct emp)*(pos-1),SEEK_SET);		      //set the cursor to that position
	a=malloc(sizeof(struct emp));
	fread(a,sizeof(struct emp),1,fp);			      //read the data of that position and display it
	printf("\nName: %s",a->name); 		
	printf("\nAge: %d",a->age); 		
	printf("\nEmpcode: %d",a->empcode);
	free(a);
	a=malloc(sizeof(struct emp));
	printf("\nEnter the details: ");			      //get the details for updation
	printf("\nName: ");
	scanf("%s",a->name);
	printf("\nAge: ");
	scanf("%d",&a->age);
	printf("\nEmpcode: ");
	scanf("%d",&a->empcode);
	fseek(fp,sizeof(struct emp)*(pos-1),SEEK_SET);		     //set the cursor to be placed and write it back
	fwrite(a,sizeof(struct emp),1,fp);
	free(a);
	fclose(fp);						     //open the file in read mode and display whole contents	
	fp=fopen(filename,"r");
	for(i=0;i<10;i++)
	{
		a=malloc(sizeof(struct emp));
		fread(a,sizeof(struct emp),1,fp);
		printf("\nName: %s",a->name); 		
		printf("\nAge: %d",a->age); 		
		printf("\nEmpcode: %d",a->empcode);
		printf("\n\n");
		free(a);
	}
	fclose(fp);
	printf("\n\n");
 	return;
 }
		
