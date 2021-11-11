#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	char elem;
	struct Node *next;
}Node;

void getNode(Node **p) {
	(*p) = (Node *)malloc(sizeof(Node));
	(*p)->next = NULL;
}

void push(Node **t, char ch) {
	if ((*t) == NULL) {
		getNode(t); (*t)->elem = ch;
		return;
	}
	Node *p; getNode(&p); p->elem = ch; //새로운 노드 생성
	p->next = (*t);
	(*t) = p;
}

char pop(Node **t) {
	Node *tmp; char temp;

	tmp = (*t);
	(*t) = (*t)->next;
	temp = tmp->elem;
	free(tmp);
	return temp;
}

int isEmpty(Node *t) {
	if (t == NULL) return 1;
	else return 0;
}

int count(char anl[]) {
	int cnt = 0;
	for (int i = 0; i < strlen(anl); i++) {
		if (anl[i] == '(' || anl[i] == ')' || anl[i] == '{' || anl[i] == '}' || anl[i] == '[' || anl[i] == ']')
			cnt++;
	}
	return  cnt;
}

int isCounter(char a, char b) {
	if (a == '(') {
		if (b == ')')	return 1;
		else return 0;
	}
	else if (a == '{') {
		if (b == '}') return 1;
		else return 0;
	}
	else if (a == '[') {
		if (b == ']') return 1;
		else return 0;
	}
	return 0;
}

int isBalanced(char anl[]) {
	Node *t=NULL;
	char a, b;
	int i;
	for (i = 0; i < strlen(anl); i++) {
		if (anl[i] == '(' || anl[i] == '[' || anl[i] == '{') 
			push(&t, anl[i]);
		else if (anl[i] == ')' || anl[i] == ']' || anl[i] == '}') {
			if (isEmpty(t) == 1) return 0;
			else {
				a = t->elem; b = anl[i];
				if (isCounter(a, b) == 1)	pop(&t);
				else return 0;
			}
		}
	}
	if (isEmpty(t) == 1) return 1;
	else return 0;
}


int main() {
	char anl[1000] = ""; //수식문장
	gets(anl);
	
	if (isBalanced(anl) == 1)
		printf("OK_%d", count(anl));
	else if (isBalanced(anl) == 0)
		printf("Wrong_%d", count(anl));

	return 0;
}
