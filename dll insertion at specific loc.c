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
	
}
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


void insertSpecific(int val, int loc)
{
	struct node *temp=head;
	if(head==NULL)
	{
		insertBeg(val);
	}
	else if(head->next==NULL)
	{
		insertEnd(val);
	}
	else{
		struct node *newNode;
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=val;
		int i;
		for(i=0;i<loc-1;i++)
		{
		temp=temp->next;
		}
		temp->next->prev=newNode;
		newNode->next=temp->next;
		newNode->prev=temp;
		temp->next=newNode;
	}
	printf("%d value insertred at loc %d\n",val,loc);
}

void display()
{
	struct node *temp=head;
	printf("The values in the linked list are:\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;

	}
}
int main()
{
	insertBeg(12);
	insertSpecific(10,0);
	insertSpecific(30,1);
	insertspecific(20,1);
	display();
	return 0;
}
