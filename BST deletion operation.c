//BST insertion operation
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int key;
	struct node *right;
};
struct node *root=NULL;
struct node *getNewNode(int val)
{
	struct node *newNode=malloc(sizeof(struct node));
	newNode->key=val;
	newNode->left=newNode->right=NULL;
	return newNode;
}
struct node *insert(struct node *root, int val)
{
	if(root==NULL)
		  return getNewNode(val);
	if(root->key<val)
		root->right= insert(root->right,val);
	else if(root->key>val)
		root->left= insert(root->left,val);
		return root;
}
void inorder(struct node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	printf("%d \t",root->key);
	inorder(root->right);
}
int getRightMin(struct node *root)
{
	struct node *temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->key;
}

struct node *removeNode(struct node *root,int val)
{
	if(root==NULL)
return NULL;
if(root->key<val)
root->right=removeNode(root->right,val);
else if(root->key>val)
root->left=removeNode(root->left,val);
else
{
	if(root->left==NULL && root->right==NULL)//leaf node
	{
		free(root);
		return NULL;
	}
	else if(root->left==NULL)//right child
	{
		struct node *temp=root->right;
		free(root);
		return temp;
	}
	else if(root->right==NULL)//left child
	{
		struct node *temp=root->left;
		free(root);
		return temp;
	}
	else{
		int rightmin=getRightMin(root->right);
		root->key=rightmin;
		root->right=removeNode(root->right,rightmin);	}
}
return root;
}

int main()
{

root=insert(root,100);
root=insert(root,50);
root=insert(root,200);
root=insert(root,150);
root=insert(root,300);
inorder(root);
removeNode(root,200);
printf("\n After deletion\n");
inorder(root);
return 0;

}

