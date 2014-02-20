/*	Filename	:	demostaticglobal.c
 *	Date		:	14-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate static variable
 */

 #include<stdio.h>
 #include<math.h>

 int var;

 int incstat()
 {
  static int s1;
  var++;
  printf("now your value is %d\n",s1);
  s1++;
 } 	 	 	
