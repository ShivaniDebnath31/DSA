#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int main()
{
	struct node *first,*middle,*last,*temp=first;
	//creatio of nodes
	first=(struct node*)malloc(sizeof(struct node));
	middle=(struct node*)malloc(sizeof(struct node));
	last=(struct node*)malloc(sizeof(struct node));
	//assigning the values
	first->data=10;
	middle->data=20;
	last->data=30;
	//linking
	first->next=middle;
	middle->next=last;
	last->next=first;
//display
	do{
		printf("%d\n",temp->data);
		temp=temp->next;
	}while(temp->next!=first);

return 0;
}