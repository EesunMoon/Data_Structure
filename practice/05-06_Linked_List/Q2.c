#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	int coef, exp; //항의 계수와 차수
	struct Node *next; //다음 노드를 가리키는 링크
};

void getNode(struct Node **p);
void appendTerm(struct Node *k, int c, int e);
void addPoly(struct Node *result, struct Node *x, struct Node *y);
//void Display(struct Node *p);

int main() {
	int n, i, c, e;
	struct Node *h1; struct Node *p1;
	struct Node *h2; struct Node *p2;
	struct Node *h; struct Node *p;
	getNode(&h1); getNode(&h2); getNode(&h);
	p1 = h1; p2 = h2; p = h;
	//처음을 가리키는 헤더와 돌아다니면서 가리키는 포인터

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d ", &c, &e);
		appendTerm(p1, c, e);
		p1 = p1->next;
	}

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		appendTerm(p2, c, e);
		p2 = p2->next;
	}

	//h1 = h1->next; h2 = h2->next;
	//Display(h1); Display(h2);

	addPoly(h, h1, h2);
	p = p->next; //헤더 다음노드부터 값이 있으므로 옮겨줘야함
	while (p != NULL) { //p로 이동시켜주고 있으므로 h!=NULL이 아니라 p!=NULL임
		printf(" %d %d", p->coef, p->exp);
		p = p->next;
	}

	return 0;
}

void getNode(struct Node **p) {
	(*p) = (struct Node*)malloc(sizeof(struct Node));
	(*p)->next = NULL;
}

void appendTerm(struct Node *k, int c, int e) {
	struct Node *t;	getNode(&t);
	t->coef = c; t->exp = e; //변수를 담은 노드 생성

	k->next = t; //실질적으로는 헤더 다음에 넣었으니까 출력할 때 h=h->next해야함
	k = t;
}

void addPoly(struct Node *result, struct Node *x, struct Node *y) {
	int sum;
	x = x->next; y = y->next; //실질적으로는 헤더 다음부터 값이 넣어진 노드가 있으므로 next로 옮겨주기

	while (x != NULL && y != NULL) {
		if (x->exp > y->exp) {
			appendTerm(result, x->coef, x->exp);
			x = x->next;
			result = result->next;
		}
		else if (x->exp < y->exp) {
			appendTerm(result, y->coef, y->exp);
			y = y->next;
			result = result->next;
		}
		else {
			sum = x->coef + y->coef;
			if (sum != 0) {
				appendTerm(result, sum, x->exp);
				result = result->next;
			}
			x = x->next;
			y = y->next;
		}
	}
	while (x != NULL) {
		appendTerm(result, x->coef, x->exp);
		x = x->next;
		result = result->next;
	}
	while (y != NULL) {
		appendTerm(result, y->coef, y->exp);
		y = y->next;
		result = result->next;
	}
}

/*void Display(struct Node *p) {
while (p != NULL) {
printf(" %d %d", p->coef, p->exp);
p = p->next;
}
printf("\n");
}*/
