#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char elem;
	struct node *prev, *next; //typedef로 재정의 하기 전에 prev,next를 선언하므로 원래대로 쓰기
}node;

node *h = NULL, *t = NULL;

int count(node *p);
void add(node *p, int position, int item);
void delete(node *p, int position);
char get_entry(node *p, int position);
void print(node *p);

int main() {
	h = (node *)malloc(sizeof(node));
	t = (node *)malloc(sizeof(node));
	h->next = t;
	t->prev = h;
	h->prev = NULL;
	t->next = NULL;

	char ch, item;
	int num, i, position;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		getchar();
		scanf("%c", &ch);

		if (ch == 'A') {
			scanf("%d %c", &position, &item);
			add(h, position, item);
		}
		else if (ch == 'D') {
			scanf("%d", &position);
			delete(h, position);
		}
		else if (ch == 'G') {
			scanf("%d", &position);
			if (position > count(h))
				printf("invalid position\n");
			else
				printf("%c\n", get_entry(h, position));
		}
		else if (ch == 'P') 
			print(h);
	}

	return 0;
}

int count(node *p) {
	int c = 0;
	p = p->next; //head에서 node로 옮겨줌
	while (p != t) {
		c++;
		p = p->next;
	}
	return c;
} //이중리스트 개수 세기

void add(node *p, int position, int item) {
	node *tmp = (node*)malloc(sizeof(node));
	int i;
	if (position>count(p)+1) //추가할 때는 범위가 노드개수보다 하나 더 추가됨
		printf("invalid position\n");
	else {
		for (i = 1; i < position; i++)
			p = p->next; //p는 넣고자 하는 위치의 전 노드가 됨
						 //head와 연결 시켜야 하기 때문에 p=p->next쓰지 x
		tmp->elem = item;
		tmp->prev = p;
		tmp->next = p->next;
		(p->next)->prev = tmp;
		p->next = tmp;
	}
}
void delete(node *p, int position) {
	int i;
	if (position>count(p))
		printf("invalid position\n");
	else {
		for (i = 1; i <= position; i++)
			p = p->next; //p는 삭제하는 노드가 됨
		(p->prev)->next = p->next;
		(p->next)->prev = p->prev;
		free(p);
	}
}

char get_entry(node *p, int position) {
	int n = 1;

	p = p->next; //head에서 node로 옮겨줌
	while (p != t) {
		if (position == n)
			return p->elem;
		p = p->next;
		n++;
	}
}

void print(node *p) {
	p = p->next; //head다음 node를 가리킴
	while (p != t) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}
