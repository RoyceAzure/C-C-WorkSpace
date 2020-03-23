#ifndef BTS_H
#define BTS_H
#include <stdio.h>
#include <stdlib.h>
#include "../general\MDataStruct.h"

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
unsigned int NodeHeight(Nptr node) //在RInsert中使用的  計算每個節點高度
{
	unsigned int left,right;
	left = node && node->left ? node->left->height : 0;
	right = node && node->right ? node->right->height : 0;
	return left > right ? left + 1 : right + 1;
}
Nptr RInsert(int key, Nptr root)
{
	if (!root)
	{
		Nptr temp = (Nptr)malloc(sizeof(Node));
		temp->data = key;
		temp->left = temp->right = NULL;
		temp->height = 1;
		return temp;
	}
	if (root->data > key)
		root->left = RInsert(key, root->left);
	else if (root->data < key)
		root->right = RInsert(key, root->right);
	root->height = NodeHeight(root);
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

int FindLeftRightHeight(Nptr node) // function內無法回傳靜態array, 只用把動態array位置 傳給每個Rcursive function
{
	unsigned int left = 0, right = 0;
	left = Height(node->left);
	right = Height(node->right);
	printf("ptr->data : %d, left : %d, right : %d\n",node->data ,left, right);
	return left - right;
}
void FindAllBalance(Nptr node)
{
    if(node)
        printf("ptr data: %d balance : %d", node->data, FindLeftRightHeight(node));
    if(node->left)
        FindAllBalance(node->left);
    if(node->right)
        FindAllBalance(node->right);
}

void Inored(Nptr p)
{
	if (p)
	{
		Inored(p->left);
		printf("%d ", p->data);
		Inored(p->right);
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

void LLRotations(Nptr root)
{
    Nptr tempN = root;
    Nptr right = (Nptr)calloc(1, sizeof(Node));
    int temp = 0;
    right->data = root->data;
    root->data = root->left->data;
    root->right = right;
    tempN = root->left;
    temp = tempN->left->data;
    tempN->left = NULL;
    tempN->data = temp;
}

void RRRotations(Nptr root)
{
    Nptr tempN = root;
    Nptr left = (Nptr)calloc(1, sizeof(Node));
    left->data = root->data;
    root->left = left;
    root->data = root->right->data;
    tempN = root->right;
    tempN->data = tempN->right->data;
    tempN->right = NULL;
}

// void printTreeLevel(Nptr root, Mqueue Mq)
// {
// 	Nptr temp = NULL;
// 	PushQueue(Mq, root);
// 	while(!isQueueEmpty(Mq))
// 	{
// 		temp = PopQueue(Mq);
// 		if(temp->left)
// 		{
// 			/* 拿出資料做處理*/
// 			PushQueue(Mq, temp->left);
// 		}
// 		if(temp->right)
// 		{
// 			/* 拿出資料做處理*/
// 			PushQueue(Mq, temp->right);
// 		}
// 	}
// }

#endif