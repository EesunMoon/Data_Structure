#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int elem;
	struct Node* next;
}NODE;

void getNode(NODE **p);
void addNode(NODE *h, int x);
NODE* Union(NODE *a, NODE *b);
NODE* Intersect(NODE *a, NODE *b);
void display(NODE *p);

int main() { //헤드를 직접 움직이는 것은 위험! 포인터 사용하기
	NODE *a; NODE *b; getNode(&a); getNode(&b); //원래 있는 A,B집합
	NODE *u; NODE *e; //getNode(&u); getNode(&e); //합집합, 교집합
	int n, i, x;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		addNode(a, x);
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		addNode(b, x);
	}
	u=Union(a, b); e=Intersect(a, b);
	display(u); display(e);

	return 0;
}

void getNode(NODE **p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
	(*p)->next = NULL;
} //공간할당함수

void addNode(NODE *h, int x) {
	NODE *tmp, *p = h; //tmp는 새로운 노드, p는 헤드부터 가리키는 포인터
	getNode(&tmp); tmp->elem = x; //새로운 노드 생성
	while (p->next != NULL)
		p = p->next;
	p->next = tmp;
	//반복문 부분 p!=NULL로 쓰고 p=tmp로 하면 안됨!
} //노드를 추가해주는 함수

NODE* Union(NODE *a, NODE *b) {
	NODE *p = a, *q = b, *tmp;	getNode(&tmp);
	int x, y;
	p = p->next; q = q->next;
	while (p != NULL && q != NULL) {
		x = p->elem; y = q->elem;
		if (x < y) {
			addNode(tmp, x);
			p = p->next;
		}
		else if (x > y) {
			addNode(tmp, y);
			q = q->next;
		}
		else {
			addNode(tmp, x);
			p = p->next; q = q->next;
		}
	}
	while (p != NULL) {
		addNode(tmp, p->elem);
		p = p->next;
	}
	while (q != NULL) {
		addNode(tmp, q->elem);
		q = q->next;
	}
	return tmp;
}

NODE* Intersect(NODE *a, NODE *b) {
	NODE *p = a, *q = b, *tmp;	getNode(&tmp);
	int x, y;
	p = p->next; q = q->next;
	while (p != NULL&&q != NULL) {
		x = p->elem; y = q->elem;
		if (x < y)
			p = p->next;
		else if (x > y)
			q = q->next;
		else {
			addNode(tmp, x);
			q = q->next;
			p = p->next;
		}
	}
	return tmp;
}

void display(NODE *p) {
	p = p->next;
	if (p == NULL) printf(" 0\n");
	else{
		while (p != NULL) {
			printf(" %d", p->elem);
			p = p->next;
		}
		printf("\n");
	}
}
