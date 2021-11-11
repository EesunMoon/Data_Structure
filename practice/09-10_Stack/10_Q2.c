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

int cal(char anl, char a, char b) {
	if (anl == '+') return a + b;
	else if (anl == '*') return a*b;
	else if (anl == '-') return a - b;
	else if (anl == '/') return a / b;
}

int evaluate(char anl[]) {
	Node *t=NULL;
	char a, b;
	int i;
	for (i = 0; i < strlen(anl); i++) {
		if (anl[i] >='0' && anl[i]<='9') 
			push(&t, anl[i]-'0');
		else if (anl[i] == '*' || anl[i] == '/' || anl[i] == '+'||anl[i]=='-') {
			b = pop(&t); a = pop(&t);
			push(&t, cal(anl[i], a, b));
		}
	}
	return pop(&t);
}


int main() {
	int n, i, j;
	char anl[100] = ""; //수식문장
	scanf("%d", &n); getchar();
	for (i = 0; i < n; i++) {
		gets(anl);
		printf("%d\n", evaluate(anl));
	}
	
	return 0;
}
