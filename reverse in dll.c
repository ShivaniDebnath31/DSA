//reverse of linked list in reverse
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
    	newNode->next=NULL;
    	newNode->prev=NULL;
    	head=newNode;
	}
	else{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->prev=temp;
		newNode->next=NULL;
	}
	printf("%d is inserted at the end\n",val);
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
void displayRev()
{
	struct node *temp=head;
	printf("IN REVERSE\n");
	while(temp->next!=NULL)
	{
	temp=temp->next;
}

while(temp!=NULL){
	printf("%d\n",temp->data);
	temp=temp->prev;
	}


}
int main(){
	insertEnd(10);
	insertEnd(20);
	insertEnd(30);
    display();
	displayRev();
	return 0;
	}
