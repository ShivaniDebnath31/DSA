#include<stdio.h>
#include<stdlib.h>
 typedef struct Node{
	struct Node *left;
	int key;
	struct Node *right;
	int height;
}AVL;
int max(int a, int b)
{
	return (a>b)?a:b;
}
int height(struct Node *n)
{
	if(n==NULL)
	{
		return 0;
	}
	return 1+max(height(n->left),height(n->right));
}
AVL *newNode(int key)
{
	AVL *node=(AVL*)malloc(sizeof(AVL));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=0;
	return (node);
}
AVL *rightRotate(AVL *y)
{
	AVL *x=y->left;
	AVL *T2= x->right;
	//perform rotation
	x->right=y;
	y->left=T2;
	//updating heights
	y->height=height(y);
	x->height=height(x);
	//return new root
	return x;
}
AVL *leftRotate(AVL *x)
{
	AVL *y=x->right;
	AVL *T2= y->left;
	//perform rotation
	y->left=x;
	x->right=T2;
	
	//updating heights
	x->height=height(y);
	y->height=height(x);

	//return new root
	return y;

}
int getBalFac(AVL *N)
{
	if (N==NULL)
	return 0;
	return height(N->left)-height(N->right);
}
AVL *insert(AVL *node, int key)
{
	if(node==NULL)
	return(newNode(key));
	if(key<node->key)
	node->left=insert(node->left,key);
	else if(key>node->key)
	node->right=insert(node->right,key);
	else
	return node;
	node->height=height(node);
	int balance=getBalFac(node);
	//LEFT LEFT ROTATION
	if(balance>1 && key<node->left->key)
	return rightRotate(node);
	//RIGHT RIGHT ROTATION
	if(balance<-1 && key>node->right->key)
	return leftRotate(node);
	// LEFT RIGHT ROTATION
	if(balance >1 && key>node->left->key)
	{
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	// RIGHT LEFT ROTATION
		if(balance <-1 && key<node->right->key)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
	
}
//inorder traversal
void inorder(struct node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	printf("%d \t",root->key);
	inorder(root->right);
}
int main()
{
	AVL *root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);
	root=insert(root,25);
	printf("Inorder traversal of AVL tree is \n");
	inorder(root);
	return 0;
}
