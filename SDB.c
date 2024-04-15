#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#define NULL_ 0
int countt=0; u8 count=0;
int i=0; u32 list[10]; 
typedef struct node 
	{
    student data;          
    struct node *Next; 
    } NODE;
	NODE*head=NULL_;
	NODE*counter=NULL_; //I initialized the pointer to node(counter) with NULL value
bool SDB_IsFull() 
{
	counter=head; 
	while(counter->Next!=NULL_)
	{
		counter=counter->Next;
		countt++;
	}
	if(countt>10) {printf("It's full\n"); return true;}
	else {printf("Not full\n"); return false;}
}
u8 SDB_GetUsedSize()
{
	if(head==NULL_) return 0;
	counter=head;
	while(counter->Next!=NULL_)
	{
		counter=counter->Next;
		countt++;
	}
	return countt+1;
}  
bool SDB_AddEntry()
{
    NODE*temp; 
    NODE*p=NULL_;
    temp=(NODE*)malloc(sizeof(NODE)); //Temp now is a new node that will hold each value I enter in the data part which is a struct
    int flag=0; //The flag variable is gonna help me to determine if there's an invalid entry
    int ID,y,c1,c2,c3,g1,g2,g3; //I created variables for the user to scan,and if the entry is valid then the value will get stored in the data of the node
	//If the data is invalid,it won't get stored
	printf("Enter the data for student number: %d\n",i+1);
	printf("Student_ID:"); scanf("%d",&(ID)); printf("\n"); if(ID>0) {temp->data.Student_ID=ID; list[i]=list[i]+temp->data.Student_ID; count++;} else flag++;
	printf("Student_Year:"); scanf("%d",&y); printf("\n");  if((y<=12) && (y>0)) {temp->data.Student_Year=y;} else flag++;
    printf("Course 1 ID:"); scanf("%d",&c1); printf("\n");  if(c1>=0) temp->data.Course1_ID=c1; else flag++;
    printf("Course 1 grade:"); scanf("%d",&g1); printf("\n"); if((g1>0)&&(g1<=100)) {temp->data.Course1_grade=g1;} else flag++;
    printf("Course 2 ID:"); scanf("%d",&c2); printf("\n"); if(c2>=0) {temp->data.Course2_ID=c2;} else flag++;
    printf("Course 2 grade:"); scanf("%d",&g2); printf("\n"); if((g2>0)&&(g2<=100)) {temp->data.Course2_grade=g2;} else flag++;
    printf("Course 3 ID:"); scanf("%d",&c3); printf("\n"); if(c3>=0) {temp->data.Course3_ID=c3;} else flag++;
    printf("Course 3 grade:"); scanf("%d",&g3); printf("\n"); if((g3>0)&&(g3<=100)) {temp->data.Course3_grade=g3;} else flag++;
	temp->Next=NULL_;
	//I created a new node and I stored the values in it but it's still not linked with the rest of the list
if(head==NULL_)
{
	head=temp;
} //If this is the first entry,the new node will become the head;
else
{
	p=head;
	while(p->Next!=NULL_)
	{
		p=p->Next;
	}
	p->Next=temp;
}//Since linked lists store data sequentially,this while loop helps me reach the last node stored in the list and link the new node after it
if(flag>0) {printf("Invalid entry\n\n"); return false;} //If flag is greater than zero then it means that there was at least one invalid entry so it won't be stored
if(flag==0) { i++; printf("Successful entry\n\n"); return true;} 
//If flag is equal to zero then it means that each value passed the if statements successfuly and got stored
//This incrementation helps me keep count of how many student datas were entered
}
void SDB_DeleteEntry(u32 id)
{
	NODE*c=NULL_; //This pointer will point to the current node
	NODE*p=NULL_; //This pointer will point to the previous node
	c=head; p=head; //At first,they're both pointing to head
	while(c->data.Student_ID!=id) 
	{
		p=c; //After making sure the condition is still valid,we will assign the value of current pointer to previous pointer
		c=c->Next; //C is the pointer moving along the linked list
		//Before the other loop begins,we'll have c pointing to a node and p pointing to the node exactly before it
	} //Once we reach the id required we will exit the while loop,having c point to the required node and p to the previous one
	p->Next=c->Next; //Now the next of the previous pointer will point to the next of the current(required) node
	free(c); //After we skipped the node we want to delete and after linking the previous node to the one after it,we'll delete the node from the memory 
	c=NULL_; //Now c points to nothing and we can delete another entry if the function is called again
}
bool SDB_IsIDExist(u32 id)
{
	NODE*current=NULL_; //The current pointer is initialized with the value null
	current=head; //Current is assigned the value of head at first
	while(current->Next!=NULL_) //This while loop will make the current pointer traverse the whole linked list
	{
		if(current->data.Student_ID==id) {return true; break;}
		current=current->Next;
	}
   return false; //it will return false if the ID doesn't exist
}
void SDB_GetList(u8*count,u32*list)
{
	int c=*count; //I assigned the value of count to a c variable so it'll be easier to look at and write in the code
	for(int k=0;k<c;k++)
	{
		printf("Student %d 's ID: %d\n",k+1,list[k]);
	} //I created an array to save all IDs because you put it in the paramters of the function
} 
bool SDB_ReadEntry(u32 id)
{
	NODE*current=NULL_;
	current=head;
	while(current->Next!=NULL_) //This while loop is to make the current pointer move along the whole linked list
	{
		if(current->data.Student_ID==id)  //If we reached the required id,we will stop and print the other information then exit the while loop
		{ 
	    printf("Student Year: %d\n",current->data.Student_Year);
	    printf("Course 1 ID: %d\n",current->data.Course1_ID);
	    printf("Course 1 grade: %d\n",current->data.Course1_grade);
	    printf("Course 2 ID: %d\n", current->data.Course2_ID);
	    printf("Course 2 grade: %d\n",current->data.Course2_grade);
	    printf("Course 3 ID: %d\n",current->data.Course3_ID);
	    printf("Course 3 grade %d\n",current->data.Course3_grade);
		return true;}
		current=current->Next; //Moves us to the next node if the value wasn't found
	}
	if(head==NULL_) {printf("No data exists\n"); return false;} //Compiles if linked list is still empty
}