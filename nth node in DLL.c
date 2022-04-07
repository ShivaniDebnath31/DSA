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
void get_nth_node(int index)
{
	struct node *temp=head;
	int i=0;
	while(temp!=NULL)
	{
		if(i==index)
		{
		printf("The value at %d node is %d",index,temp->data);
		}
		i++;
		temp=temp->next;
	}

}
int main()
{
	insertEnd(50);
	insertEnd(60);
	insertEnd(10);
	insertEnd(70);
	insertEnd(40);
	get_nth_node(2);

	return 0;
}
