#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	node *p;
	node *left;
	node *right;
}node;

void In_order_Tree_Walk(node *x)
{
	if ((x->left && x->right) != NULL)
	{
		In_order_Tree_Walk(x->left);
		printf("%d\n", x->key);
		In_order_Tree_Walk(x->right);
	}
}

void Pre_order_Tree_Walk(node *x)
{
	if ((x->left && x->right) != NULL)
	{
		printf("%d\n", x->key);
		Pre_order_Tree_Walk(x->left);
		Pre_order_Tree_Walk(x->right);
	}
}

void Post_order_Tree_Walk(node *x)
{
	if ((x->left && x->right) != NULL)
	{
		Post_order_Tree_Walk(x->left);
		Post_order_Tree_Walk(x->right);
		printf("%d\n", x->key);
	}
}

node *InitiateTree(int data)
{
	node *x;
	x = (node*)malloc(sizeof(node));

	x->key = data;
	x->left = NULL;
	x->right = NULL;

	return x;
}

node *Tree_Search(node *x, int key)
{
	if ((x->left == NULL && x->right == NULL) || key == x->key)
		return x;
	if (key < x->key)
		return Tree_Search(x->left, key);
	else
		return Tree_Search(x->right, key);
}

node *Interative_Tree_Search(node *x, int key)
{
	while ((x->left && x->right) != NULL && key != x->key)
	{
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

node *Tree_Minimum(node *x)
{
	while (x->left != NULL)
		x = x->left;

	return x;
}

node *Tree_Maximum(node *x)
{
	while (x->right != NULL)
		x = x->right;

	return x;
}

node *Tree_Successor(node *x)
{
	node *y;

	if (x->right->left != NULL && x->right->right != NULL)
		return Tree_Minimum(x->right);

	y = x->p;

	while (y->left != NULL && y->right != NULL && x == y->right)
	{
		x = y;
		y = y->p;
	}

	return y;
}

node *Tree_Predecessor(node *x)
{
	node *y;

	if (x->left->left != NULL && x->left->right != NULL)
		return Tree_Maximum(x->left);

	y = x->p;

	while (y->left != NULL && y->right != NULL && x == y->left)
	{
		x = y;
		y = y->p;
	}

	return y;
}

void Tree_Insert(node *T, node *z)
{
	node *y;
	y = (node*)malloc(sizeof(node));

	node *x = T;
	while ((x->left != NULL && x->right) != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->p = y;
	if ((y->left == NULL && y->right) == NULL)
		T = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

void Transplant(node *T, node *u, node *v)
{
	if ((u->p->left && u->p->right) == NULL)
		T = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;

	if ((v->left && v->right) == NULL)
		v->p = u->p;
}

void Tree_Delete(node *T, node* z)
{
	node *y = (node*)malloc(sizeof(node));

	if ((z->left->left && z->left->right) == NULL)
		Transplant(T, z, z->right);

	else if ((z->right->left && z->right->right) == NULL)
		Transplant(T, z, z->left);

	else y = Tree_Minimum(z->right);

	if (y->p != z)
	{
		Transplant(T, y, y->right);
		y->right = z->right;
		y->right->p = y;
	}
	Transplant(T, z, y);
	y->left = z->left;
	y->left->p = y;
}

int main() //±×³É °Ë»ç
{
	node *parent = InitiateTree(6);
	node *insert = InitiateTree(10);

	parent->left = InitiateTree(5);
	parent->right = InitiateTree(7);
	parent->left->left = InitiateTree(2);
	parent->left->right = InitiateTree(3);
	parent->right->right = InitiateTree(8);
	Tree_Insert(parent, insert);

	  //ÁßÀ§ ÈÄÀ§ ÀüÀ§ Å½»ö
	printf("ÁßÀ§Å½»ö\n");
	In_order_Tree_Walk(parent);
	printf("\n");

	//printf("ÈÄÀ§Å½»ö\n");
	//Post_order_Tree_Walk(parent);
	//printf("\n");

	printf("ÀüÀ§Å½»ö\n");
	Pre_order_Tree_Walk(parent);
	printf("\n");
	

	parent = Tree_Maximum(parent);
	printf("The Maximum is %d\n", parent->key);
	return 0;
}