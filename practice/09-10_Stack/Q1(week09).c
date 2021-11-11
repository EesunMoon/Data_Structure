#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct stack {
	int size;
	int top;
	char *s;
}sta;

void push(sta *st, char data);
char pop(sta *st);
void peek(sta *st);
void duplicate(sta *st);
void upRotate(sta *st, int n);
void downRotate(sta *st, int n);
void print(sta *st);

int main() {
	sta st;
	int Size, N, i, n;
	char anl[6] = "", data;

	scanf("%d", &Size); //stack의 크기
	st.size = Size; 	st.s = (char *)malloc(sizeof(char)*Size); 	st.top = -1; //스택 초기화

	scanf("%d", &N); //연산의 개수
	for (i = 0; i < N; i++) {
		scanf("%s", anl); getchar(); //연산 이름 입력
		if (strcmp(anl, "POP") == 0)
			pop(&st);
		else if (strcmp(anl, "PUSH") == 0) {
			scanf("%c", &data); getchar();
			push(&st, data);
		}
		else if (strcmp(anl, "PEEK") == 0)
			peek(&st);
		else if (strcmp(anl, "DUP") == 0)
			duplicate(&st);
		else if (strcmp(anl, "UpR") == 0) {
			scanf("%d", &n); getchar();
			upRotate(&st, n);
		}
		else if (strcmp(anl, "DownR") == 0) {
			scanf("%d", &n); getchar();
			downRotate(&st, n);
		}
		else if (strcmp(anl, "PRINT") == 0)
			print(&st);
	}

	return 0;
}

void push(sta *st, char data) { //top에 데이터 추가
	if (st->top >= st->size - 1)
		printf("Stack FULL\n");
	else {
		st->top++;
		st->s[st->top] = data;
	}
}
char pop(sta *st) { //top데이터 반환 후 stack에서 제거
	char x;
	if (st->top == -1) {
		printf("Stack Empty\n");
		return 0;
	}
	else {
		x = st->s[st->top];
		st->top--;
		return x;
	}
}
void peek(sta *st) {
	if (st->top == -1)
		printf("Stack Empty\n");
	else
		printf("%c\n", st->s[st->top]);
}
void duplicate(sta *st) {
	char x;
	if (st->top >= st->size - 1)
		printf("Stack FULL\n");
	else {
		x = pop(st);
		push(st, x);	push(st, x);
	}
}
void upRotate(sta *st, int n) {
	char tmp;
	int i, index = st->top;
	if (n > st->top+1) return; //범위가 잘못 됐었음
	else {
		for (i = index; i > index - n + 1; i--) {
			tmp = st->s[i];
			st->s[i] = st->s[i - 1];
			st->s[i - 1] = tmp;
		}
	}
}
void downRotate(sta *st, int n) {
	char tmp;
	int i, index = st->top;
	if (n > st->top+1) return; //범위가 잘못 됐었음
	else {
		for (i = index - n + 1; i < index; i++) {
			tmp = st->s[i];
			st->s[i] = st->s[i + 1];
			st->s[i + 1] = tmp;
		}
	}
}
void print(sta *st) {
	int i;
	for (i = st->top; i >= 0; i--)
		printf("%c", st->s[i]);
	printf("\n");
}
