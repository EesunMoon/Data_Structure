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
int member(NODE *h, int x);
int subset(NODE *a, NODE *b);

int main() { //헤드를 직접 움직이는 것은 위험! 포인터 사용하기
	NODE *a; NODE *b;
	getNode(&a); getNode(&b); 
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

	printf("%d", subset(a, b));
	return 0;
}

void getNode(NODE **p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
	(*p)->next = NULL;
} //공간할당함수

void addNode(NODE *h, int x) {
	NODE *tmp, *p=h; //tmp는 새로운 노드, p는 헤드부터 가리키는 포인터
	getNode(&tmp); tmp->elem = x; //새로운 노드 생성
	while (p->next != NULL) 
		p = p->next;
	p->next = tmp; 
	//반복문 부분 p!=NULL로 쓰고 p=tmp로 하면 안됨!
} //노드를 추가해주는 함수

int member(NODE *h, int x) {
	NODE *p = h;
	p = p->next; //p가 헤더를 가리키고 있으므로 헤더 그 다음으로 옮겨주기
	int y, cnt=0;
	if (p == NULL)
		return 0;
	while (1) {
		y = p->elem;
		//printf("%d:%d\n", cnt++, y); :확인하려고 쓴 거임
		if (y < x) {
			if (p->next == NULL) return 0;
			else p = p->next;
		}
		else if (y > x)	return 0;
		else return 1; //같으면 true(1)반환
	}
} //원소가 집합 안에 있는가 확인하는 함수

int subset(NODE *a, NODE *b) {
	NODE *p=a;
	p = p->next; //p가 a의 헤더를 나타내므로 헤더 다음으로 옮겨주기
	if (a ->next== NULL) //a가 공집합인 경우는 0을 반환
		return 0;
	while (1) {
		if (member(b, p->elem) == 1) { //b에 a의 원소가 있으면
			if (p->next == NULL) return 0; //마지막 원소
			else p = p->next;
		}
		else //없으면 그 원소 반환
			return p->elem;
	}
} //a가 b의 부분집합인지 검사하는 함수
