/*	Filename	:	seekrev.c
 *	Date		:	03-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to traverse the records in reverese
 */

 void seekrev(char *filename)
 {
	FILE *fp;
	struct emp *a;
	int i;
	fp=fopen(filename,"r");
	for(i=1;feof(fp)==0;i++)
	{
		fseek(fp,-(sizeof(struct emp)*i),SEEK_END);		/* setting cursor in reverse order and displaying after read using fseek() and fread() 
		a=malloc(sizeof(struct emp));
		fread(a,sizeof(struct emp),1,fp);
		printf("\nName: %s",a->name); 		
		printf("\nAge: %d",a->age); 		
		printf("\nEmpcode: %d",a->empcode); 		
		printf("\n");
		free(a);
	}
	fclose(fp);
 	return;
 }
		
