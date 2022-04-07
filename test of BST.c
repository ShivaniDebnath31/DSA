#include<stdio.h>
#include<stdlib.h>
 typedef struct unihs{
	int key;
	struct unihs *left;
	struct unihs *right;
}sd;
sd *root=NULL;

sd *getNewNode(int val)
{
	sd *newNode=malloc(sizeof(sd));
	newNode->key=val;
	newNode->left=newNode->right=NULL;
	return newNode;
}
//insertion
 sd *insert(sd *root, int val)
{
	if(root==NULL)
		  return getNewNode(val);
	if(root->key<val)
		root->right= insert(root->right,val);
	else if(root->key>val)
		root->left= insert(root->left,val);
		return root;
}
//traversal in inorder
void inorder(sd *root)
{
	if(root!=NULL){

	inorder(root->left);
	printf("%d \t",root->key);
	inorder(root->right);
}

}
//traversal in preorder
void Preorder(sd *root)
{
	if(root!=NULL)
	{
		printf("%d \t",root->key);
		Preorder(root->left);
		Preorder(root->right);
		
	}
}
//traversal in postorder
void Postorder(sd *root)
{
	if(root!=NULL)
{
	Postorder(root->left);
	Postorder(root->right);
	printf("%d \t",root->key);
}
}
//deletion operation
sd *removeNode(sd *root,int val)
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
		sd *temp=root->right;
		free(root);
		return temp;
	}
	else if(root->right==NULL)//left child
	{
		sd *temp=root->left;
		free(root);
		return temp;
	}
}
}
//searching operation
int search(sd *root, int val)
{
	if(root==NULL)
	return 0;
	if(root->key==val)
	return 1;
	else if(root->key<val)
	return search(root->right,val);
	else
	return search(root->left,val);
}

int main()
{

root=insert(root,100);
root=insert(root,50);
root=insert(root,200);
root=insert(root,150);
root=insert(root,300);
printf("\nBST in inorder traversal\n");
inorder(root);
printf("\nBST in Postorder traversal\n");
Postorder(root);
printf("\nBST in Preorder traversal\n");
Preorder(root);
removeNode(root,50);
printf("\n After deletion\n");
printf("\nBST in inorder traversal\n");
inorder(root);
printf("\nBST in Postorder traversal\n");
Postorder(root);
printf("\nBST in Preorder traversal\n");
Preorder(root);
int data;
data=search(root,300);
if(data==1)
{
	printf("\nsearch sucessful\n");
}
else
{
	printf("\nsearch failure\n");
}
return 0;

}

