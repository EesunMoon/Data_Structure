#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int *elem;
	int front;
	int rear;
	int size;
}Node;

void initQ(Node *p) {
	p->front = 0;
	p->rear = 0;
}

int isEmpty(Node *p) {
	if (p->front==p->rear) return 1;
	else return 0;
}

int isFull(Node *p) {
	if (p->front == (p->rear + 1) % (p->size)) return 1;
	else return 0;
}

void enque(Node *p, int x) {
	p->rear=(p->rear+1)%(p->size);
	p->elem[p->rear] = x;
}

void deque(Node *p) {
	p->front = (p->front + 1) % (p->size);
	p->elem[p->front]=0;
}

void print(Node *p) {
	int i;
	for (i = 0; i < p->size; i++)
		printf(" %d", p->elem[i]);
	printf("\n");
}

int main() {
	Node Q; initQ(&Q);
	int n, i, x;
	char anl;
	scanf("%d", &(Q.size)); Q.elem = (int*)malloc(sizeof(int)*(Q.size));
	for (i = 0; i < Q.size; i++) 
		Q.elem[i] = 0;
	scanf("%d", &n); getchar();
	for (i = 0; i < n; i++) {
		scanf("%c", &anl); getchar();

		if (anl == 'I') {
			if (isFull(&Q) == 1) {
				printf("overflow");
				print(&Q);
				return 0;
			}
			scanf("%d", &x); getchar();
			enque(&Q, x);
		}
		else if (anl == 'D') {
			if (isEmpty(&Q) == 1) {
				printf("underflow"); 
				return 0;
			}
			deque(&Q);
		}
		else if (anl == 'P')
			print(&Q);
	}

	return 0;
}
