#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insertBegin(int);
void display();
void insertBegin(int val)
{
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=val;
	if(head==NULL)
	{
		newNode->next=NULL;
		head=newNode;
	}
	else
	{
		newNode->next=head;
		head=newNode;
	}
	printf("%d inserted successfully\n",val);
}
	void display()
	{
		struct node *temp=head;
		printf("The data in the linked list are\n");
       while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}


int main()
{
	insertBegin(50);
	insertBegin(40);
	insertBegin(30);
	insertBegin(20);
	insertBegin(10);
	display();
	
	

	return 0;
}