#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int elem;
	struct Node *prev;
	struct Node *next;
}Node;

typedef struct Que {
	Node *f;
	Node *r;
}Que;

void initQ(Que *Q) {
	Q->f = NULL;
	Q->r = NULL;
}

void getNode(Node **p) {
	(*p) = (Node*)malloc(sizeof(Node));
	(*p)->next = NULL;
	(*p)->prev = NULL;
}

int isEmpty(Que *Q) {
	if (Q->f==NULL) return 1;
	else return 0;
}

void add_front(Que *Q, int x) {
	Node *p; getNode(&p); p->elem = x;
	if (isEmpty(Q) == 1) {
		Q->f = p;
		Q->r = p;
	}
	else {
		p->next = Q->f;
		Q->f->prev= p;
		Q->f = p;
	}
}

void add_rear(Que *Q, int x) {
	Node *p; getNode(&p); p->elem = x;
	if (isEmpty(Q) == 1) {
		Q->f = p;
		Q->r = p;
	}
	else {
		p->prev = Q->r;
		Q->r->next = p;
		Q->r = p;
	}
}

void delete_front(Que *Q) {
	Node *tmp=Q->f;
	if (Q->r == Q->f) {
		free(tmp);
		initQ(Q);
	}
	else {
		Q->f = Q->f->next;
		Q->f->prev = NULL;
		free(tmp);
	}
}

void delete_rear(Que *Q) {
	Node *tmp=Q->r;
	if (Q->r == Q->f) {
		free(tmp);
		initQ(Q);
	}
	else {
		Q->r = Q->r->prev;
		Q->r->next = NULL;
		free(tmp);
	}
}

void print(Que *Q) {
	Node *cur=Q->f;
	while (cur != NULL) {
		printf(" %d", cur->elem);
		cur = cur->next;
	}
	printf("\n");

}

int main() {
	Que *Q; Q = (Que*)malloc(sizeof(Que)); initQ(Q);
	int n, i, x;
	char anl[3] = "";
	scanf("%d", &n); getchar();
	for (i = 0; i < n; i++) {
		scanf("%s", anl); getchar();
		if (strcmp(anl, "AF") == 0) {
			scanf("%d", &x); getchar();
			add_front(Q, x);
		}
		else if (strcmp(anl, "AR") == 0) {
			scanf("%d", &x); getchar();
			add_rear(Q, x);
		}
		else if (strcmp(anl, "DF") == 0) {
			if (isEmpty(Q) == 1) {
				printf("underflow");
				return 0;
			}
			delete_front(Q);
		}
		else if (strcmp(anl, "DR") == 0) {
			if (isEmpty(Q) == 1) {
				printf("underflow");
				return 0;
			}
			delete_rear(Q);
		}
		else if (strcmp(anl, "P") == 0)
			print(Q);
	}


	return 0;
}
