#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
void insertBeg(int val)
{
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=val;
	if(head==NULL)
	{
	newNode->prev=NULL;
	newNode->next=NULL;
	head=newNode;
  }
  else{
   newNode->prev=NULL;
   newNode->next=head;
   head->prev=newNode;
   head=newNode;
  	
  }
  printf("%d inserted successfully at the beginning\n",val);
  
}
void display()
{
	struct node *temp=head;
	printf("The values in the linked list are:\n");
	while(temp!=NULL)
	{
		printf("%d\n", temp->data);
		temp=temp->next;
		
	}
}
int main()
{
	insertBeg(10);
		insertBeg(20);
			insertBeg(30);
			display();
			return 0;
	
}
