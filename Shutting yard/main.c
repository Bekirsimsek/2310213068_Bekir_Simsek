
#include <stdio.h>
#include <ctype.h>

#define MAX 200

typedef struct {
    char data[MAX];
    int top;
} CharStack;

void stInit(CharStack* s){ s->top = -1; }
int stEmpty(CharStack* s){ return s->top == -1; }
int stPush(CharStack* s, char c){
    if (s->top >= MAX - 1) return 0;
    s->data[++s->top] = c;
    return 1;
}
char stPop(CharStack* s){ return s->data[s->top--]; }
char stPeek(CharStack* s){ return s->data[s->top]; }

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main(void) {
    char infix[MAX] = "a+(b*c-d)/e";
    char postfix[MAX];
    int k = 0;

    CharStack ops;
    stInit(&ops);

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isspace((unsigned char)c)) continue;

        if (isalnum((unsigned char)c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            stPush(&ops, c);
        } else if (c == ')') {
            while (!stEmpty(&ops) && stPeek(&ops) != '(')
                postfix[k++] = stPop(&ops);
            if (!stEmpty(&ops) && stPeek(&ops) == '(') stPop(&ops);
        } else {
            while (!stEmpty(&ops) && prec(stPeek(&ops)) >= prec(c))
                postfix[k++] = stPop(&ops);
            stPush(&ops, c);
        }
    }

    while (!stEmpty(&ops))
        postfix[k++] = stPop(&ops);

    postfix[k] = '\0';
    printf("Infix : %s\n", infix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
