#include <stdio.h>
#include <stdlib.h>
#include "D:/WorkSpace/C++/C-C-WorkSpace/Queue/CLinkedQueue.h"
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} Node;
typedef Node *Nptr;

Nptr Insert(int key, Nptr root)
{
	if (!root)
	{
		Nptr root = (Nptr)malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->data = key;
		return root;
	}
	Nptr temptr = root, pre = NULL;

	while (temptr)
	{
		pre = temptr;
		if (key > temptr->data)
			temptr = temptr->right;
		else if (key < temptr->data)
			temptr = temptr->left;
		else
			return root;
	}
	temptr = (Nptr)malloc(sizeof(Node));
	temptr->left = NULL;
	temptr->right = NULL;
	temptr->data = key;
	if (pre->data > key)
		pre->left = temptr;
	else
		pre->right = temptr;
	return root;
}

Nptr RInsert(int key, Nptr root)
{
	if (!root)
	{
		Nptr temp = (Nptr)malloc(sizeof(Node));
		temp->data = key;
		temp->left = temp->right = NULL;
		return temp;
	}
	if (root->data > key)
		root->left = RInsert(key, root->left);
	else if (root->data < key)
		root->right = RInsert(key, root->right);
	return root;
}

unsigned int Height(Nptr p)
{
	unsigned int left, right;
	if (!p)
		return 0;
	left = Height(p->left);
	right = Height(p->right);
	return left > right ? left + 1 : right + 1;
}

void Inored(Nptr p)
{
	if (p)
	{
		Indored(p->left);
		printf("%d ", p->data);
		Indored(p->right);
	}
}

Nptr Search(Nptr root, int key)
{
	if (!root)
	{
		printf("root is empty\n");
		return 0;
	}
	Nptr temp = root;
	while (temp)
	{
		if (temp->data == key)
			return temp;
		if (temp->data > key)
			temp = temp->right;
		else
			temp = temp->left;
	}
	printf("root is empty\n");
	return 0;
}

Nptr InPre(Nptr p) //find max
{
	while (p && p->right)
		p = p->right;
	return p;
}
Nptr InSucc(Nptr p) //find min
{
	while (p && p->left)
		p = p->left;
	return p;
}

Nptr Delete(Nptr p, int key)
{
	Nptr q;
	if (p == NULL)
		return NULL;
	if (p->left == NULL && p->right == NULL)
	{
		// if (p == root)
		// 	root = NULL;
		free(p);
		return NULL;
	}
	if (key < p->data)
		p->left = Delete(p->left, key);
	else if (key > p->data)
		p->right = Delete(p->right, key);
	else
	{
		if (Height(p->left) > Height(p->right))
		{
			q = InPre(p->left);
			p->data = q->data;
			p->left = Delete(p->left, q->data);
		}
		else
		{
			q = InSucc(p->right);
			p->data = q->data;
			p->right = Delete(p->right, q->data);
		}
	}
	return p;
}
void printTreeLevel(Nptr root, Mqueue Mq)
{
	Nptr temp = NULL;
	PushQueue(Mq, root);
	while(!isQueueEmpty(Mq))
	{
		temp = PopQueue(Mq);
		if(temp->left)
		{
			/* 拿出資料做處理*/
			PushQueue(Mq, temp->left);
		}
		if(temp->right)
		{
			/* 拿出資料做處理*/
			PushQueue(Mq, temp->right);
		}
	}
}

int main()
{
	int temp;
	Nptr tree = NULL;
	Mqueue Mq = (Mqueue)calloc(1, sizeof(struct queue));
	while(scanf("%d", &temp) == 1)
	{
		tree = Insert(temp, tree);
	}


	return 0;
}
