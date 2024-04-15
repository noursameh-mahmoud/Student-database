#include<stdio.h>
#include "SDB.h"
u32 id; int b; u8 c; 
void SDB_Action(u8 choice)
{
	switch(choice)
	{
		case '1':
		{
			SDB_AddEntry(); 
			printf("\n"); 
			break;
		}
		case '2':
	    {
			c=SDB_GetUsedSize(); 
			printf("Used size=%d\n",c);
			break;
		} //the variable c stores the value returned by the function
		case '3':
		{ 
		printf("Insert ID:"); 
		scanf("%d",&id); 
		SDB_ReadEntry(id);
		b=SDB_ReadEntry(id); 
		 if(b==0) 
		 {
			 printf("Student wasn't found\n");
			 break;
		 }
		} //the variable b stores the boolean value returned by the function
		//if b doesn't equal 0,then it found the ID and it will print the rest of the details
		case '4':
		{
			SDB_GetList(&count,list); 
			printf("\n"); 
			break;
		} //list is an array that stores all the IDs of the students entered
		case '5':
		{
			printf("Insert ID:"); 
			scanf("%d",&id);
		    SDB_IsIDExist(id); 
			b=SDB_IsIDExist(id); 
			if(b==0) {printf("ID doesn't exist\n");} 
			if(b==1) {printf("ID Exists\n"); break;} 
		}
		case '6':
		{ 
		 printf("Insert ID:"); 
		 scanf("%d",&id);
	     SDB_DeleteEntry(id); 
		 printf("\n"); 
		 break;
		} //the function here takes the id from the user that they want to get deleted
		case '7':
		{
			SDB_IsFull(); 
			printf("\n"); 
			break;
		}
	}
}

void SDB_APP()
{
     u8 x;
	 for(;x!='0';)
	{	printf("\t1. To add entry, enter 1 \n");
		printf("\t2. To get used size in database,enter 2\n");
		printf("\t3. To read student data,enter 3\n");
		printf("\t4.To get the list of all IDs,enter 4\n");
		printf("\t5.To check if ID exists,enter 5\n");
		printf("\t6.To delete student data,enter 6\n");
		printf("\t7.To check if database is full,enter 7\n");
		printf("\t8.To exit,enter 0\n");
		printf("Please insert the number of your choice\n");
	    scanf(" %c",&x); SDB_Action(x);
	} //The leading space prevents the scanf function from reading the newline
}	
