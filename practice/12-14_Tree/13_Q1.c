#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int data; // 정보
	int id; // id
	struct Node *left;
	struct Node *right;
}Node; //노드

void getNode(Node **cur)
{
	(*cur) = (Node *)malloc(sizeof(Node));
	(*cur)->left = NULL;
	(*cur)->right = NULL;
}

void getRoot(Node **Root, int root_data, int l_data, int r_data) //root생성
{
	(*Root)->data = root_data;	(*Root)->id = 1;

	Node *lchild; getNode(&lchild);
	lchild->data = l_data;	 lchild->id = 2;

	Node *rchild; getNode(&rchild);
	rchild->data = r_data;	rchild->id = 3;

	(*Root)->left = lchild;	(*Root)->right = rchild;
}

void addTree(Node **cur, int data, int l_data, int r_data, int l_id, int r_id)
{
	if ((*cur) == NULL) return;
	if ((*cur)->data == data)
	{
		if (l_data != 0)
		{
			Node *lchild; getNode(&lchild);
			lchild->data = l_data; lchild->id = l_id;
			(*cur)->left = lchild;
		}

		if (r_data != 0)
		{
			Node *rchild; getNode(&rchild);
			rchild->data = r_data; rchild->id = r_id;
			(*cur)->right = rchild;
		}
	}
	addTree(&((*cur)->left), data, l_data, r_data, l_id, r_id);
	addTree(&((*cur)->right), data, l_data, r_data, l_id, r_id); //재귀를 이용해 찾기
}

void preorder(Node *cur) //전위순회
{
	if (cur != NULL)
	{
		printf(" %d", cur->data);
		preorder(cur->left);
		preorder(cur->right);
	}
}

void inorder(Node *cur) //중위순회
{
	if (cur != NULL)
	{

		inorder(cur->left);
		printf(" %d", cur->data);
		inorder(cur->right);
	}
}

void postorder(Node *cur) //후위순회
{
	if (cur != NULL)
	{

		postorder(cur->left);
		postorder(cur->right);
		printf(" %d", cur->data);
	}
}

void findRoot(Node *cur, int id, int index)
{
	if (cur == NULL) return;
	else
	{
		if (cur->id == id)
		{
			if (index == 1)
				preorder(cur);
			else if (index == 2)
				inorder(cur);
			else if (index == 3)
				postorder(cur);
		}
		else
		{
			findRoot(cur->left, id, index);
			findRoot(cur->right, id, index);
		}
	}
}

int main() {
	Node *root; getNode(&root); getRoot(&root, 20, 30, 50); //root생성
	addTree(&root, 30, 70, 90, 4, 5);
	addTree(&root, 50, 0, 120, 0, 6);
	addTree(&root, 120, 130, 80, 7, 8); //tree 생성

	int N, n; //순회 방법
	scanf("%d %d", &N, &n);
	if (n >= 1 && n <= 8)
		findRoot(root, n, N);
	else
		printf("-1");

	return 0;
}
