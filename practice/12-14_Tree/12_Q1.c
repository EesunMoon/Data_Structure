#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
}Node; //노드

void getNode(Node **cur, int data)
{
	(*cur) = (Node *)malloc(sizeof(Node));
	(*cur)->data = data;
	(*cur)->left = NULL;
	(*cur)->right = NULL;
}

void add(Node *cur, Node *left, Node *right)
{
	if (left!=NULL)	cur->left = left;
	if (right!=NULL)	cur->right = right;
}

void print(Node *cur)
{
	printf("%d ", cur->data);
	if (cur->left != NULL) printf("%d ", cur->left->data);
	if (cur->right != NULL) printf("%d ", cur->right->data);
}

int main() {
	Node *f1, *f2, *f3, *f4, *f5, *f6, *f7, *f8;
	getNode(&f1, 20); getNode(&f2, 30); getNode(&f3,50); getNode(&f4, 70);
	getNode(&f5, 90); getNode(&f6, 120); getNode(&f7, 130); getNode(&f8, 80);

	add(f1, f2, f3); add(f2, f4, f5); add(f3, NULL, f6); add(f4, NULL, NULL);
	add(f5, NULL, NULL); add(f6, f7, f8); add(f7, NULL, NULL); add(f8, NULL, NULL);

	int N;
	scanf("%d", &N);

	if (N == 1) print(f1);
	else if (N == 2) print(f2);
	else if (N == 3) print(f3);
	else if (N == 4) print(f4);
	else if (N == 5) print(f5);
	else if (N == 6) print(f6);
	else if (N == 7) print(f7);
	else if (N == 8) print(f8);
	else printf("-1");

	return 0;
}
