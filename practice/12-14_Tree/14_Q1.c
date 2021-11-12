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

void getNode(Node **cur)
{
	(*cur) = (Node *)malloc(sizeof(Node));
	(*cur)->left = NULL;
	(*cur)->right = NULL;
} // 노드 생성

void getRoot(Node **Root, int root_data, int l_data, int r_data) //root생성
{
	(*Root)->data = root_data;

	Node *lchild; getNode(&lchild);
	lchild->data = l_data;

	Node *rchild; getNode(&rchild);
	rchild->data = r_data;

	(*Root)->left = lchild;	(*Root)->right = rchild;
} // 루트 생성

void addTree(Node **cur, int data, int l_data, int r_data)
{
	if ((*cur) == NULL) return;
	if ((*cur)->data == data)
	{
		if (l_data != 0)
		{
			Node *lchild; getNode(&lchild);
			lchild->data = l_data;
			(*cur)->left = lchild;
		}

		if (r_data != 0)
		{
			Node *rchild; getNode(&rchild);
			rchild->data = r_data; 
			(*cur)->right = rchild;
		}
	}
	addTree(&((*cur)->left), data, l_data, r_data);
	addTree(&((*cur)->right), data, l_data, r_data); //재귀를 이용해 찾기
} // 트리 노드 추가

void print(Node *cur, char ss[])
{
	char ch[100] = "";
	if (cur == NULL) return;
	else
	{
		printf(" %d", cur->data);
		strcpy(ch, ss + 1);
		if (ss[0] == 'R')
			print(cur->right, ch);
		else if (ss[0] == 'L')
			print(cur->left, ch);
	}
}

int main() {
	int x, y, z, n, s, i, j;
	char ch, ss[100] = "";
	Node *root; getNode(&root); 
	
	scanf("%d", &n); //노드의 개수 입력

	scanf("%d %d %d", &x, &y, &z);
	getRoot(&root, x, y, z); //root 생성

	for (i = 0; i < n-1; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		addTree(&root, x, y, z); //트리 생성
	}

	scanf("%d", &s); getchar(); //탐색 횟수
	for (i = 0; i < s; i++)
	{
		scanf("%s", ss); getchar();
		print(root, ss);
		printf("\n");
	}

	return 0;
}
