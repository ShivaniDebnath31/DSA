#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
void insertEnd(int val)
{
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=val;
	if(head==NULL)
	{
	head=newNode;
	newNode->prev=head;
	newNode->next=head;

  }
  else{
  	struct node *temp=head;
  	while(temp->next!=head)
  	{
  		temp=temp->next;
	  }
  temp->next=newNode;
  newNode->prev=temp;
  newNode->next=head;
  head->prev=newNode;
   }
  printf("%d inserted successfully at the end\n",val);
}

void display()
{
	struct node *temp=head;
	printf("The values in the circular  linked list are:\n");
do
	{
		printf("%d\n", temp->data);
		temp=temp->next;

	}	while(temp!=head);
}
void delBeg()
{

	if(head==NULL)
	{
		printf("nothing is there in the linked list\n");
	}

	else

	{
		struct node *temp=head;
	    head=head->next;
		temp->prev->next=head;
		head->prev=temp->prev;
		printf("%d deleted\n",temp->data);
		free(temp);
		temp=NULL;
	
	}
	
}
int main(){
	insertEnd(10);
	insertEnd(20);
	insertEnd(30);
	display();
	delBeg();
	display();
	return 0;
	}
