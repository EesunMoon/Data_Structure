#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node 
{
	char elem;
	struct Node *next;
	int rankk;
}Node; //노드

typedef struct Stack 
{
	Node *top;
}Stack; //스택

void init_stack(Stack **S)
{
	(*S) = (Stack *)malloc(sizeof(Stack));
	(*S)->top = NULL;
} //스택초기화

void getNode(Node **p)
{
	(*p) = (Node *)malloc(sizeof(Node));
	(*p)->next = NULL;
} //노드 공간할당

void push(Stack *S, char elem, int x)
{
	Node *get;	getNode(&get); get->elem = elem;
	get->next = S->top;
	S->top = get;
	S->top->rankk = x;
} //추가

char pop(Stack *S)
{
	Node *tmp;
	char ch;
	tmp = S->top;
	ch = tmp->elem;
	S->top = S->top->next;
	free(tmp);
	return ch;
} //삭제

int rank(char cal[], int x)
{
	if (cal[x] == ')') return 0; //괄호 닫음
	if (cal[x] == '|') return 1;
	if (cal[x] == '&') return 2;
	if (cal[x] == '>' || cal[x] == '<') return 3;
	if (cal[x] == '-' || cal[x]=='+')
	{
		if (cal[x - 1] == ')') return 4;
		else if ('A' <= cal[x - 1] && cal[x - 1] <= 'Z') return 4;
		else return 6;
	}
	if (cal[x] == '*' || cal[x] == '/') return 5;
	if (cal[x] == '!') return 6;
	if (cal[x] == '(') return 7;
}

int main() {
	Stack *S;	init_stack(&S); //스택
	int N, i, j, x, index=0;	char anl[100] = "", ch;
	scanf("%d", &N); //연산의 개수 입력
	for (i=0;i<N;i++)
	{
		scanf("%s", anl); getchar(); //문자열 입력
		for (j = 0; j < strlen(anl); j++)
		{
			if (anl[j] >= 'A'&&anl[j] <= 'Z')
			{
				printf("%c", anl[j]);
				index = 0;
			} //피연산자이면 그냥 출력
			else
			{
				x = rank(anl, j); //수식에 순위 부여
				while (1)
				{
					if (S->top == NULL || S->top->rankk < x || S->top->elem == '(')
						break;
					ch = pop(S);
					printf("%c", ch);
				}
				if (anl[j] == ')')
				{
					pop(S);
					continue;
				}
				if (x == 1 || x == 2)
				{
					push(S, anl[j], x);
					j++;
				}
				push(S, anl[j], x);
				index++;
			}
		}
		while (S->top != NULL)
		{
			printf("%c", S->top->elem);
			S->top = S->top->next;
		}
		printf("\n");
	}

	return 0;
}
