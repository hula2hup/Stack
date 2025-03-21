#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmptyStack(Stack *s) {
    return s->top == -1;
}

int isFullStack(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (!isFullStack(s)) {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (!isEmptyStack(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

void decimalToBinary(int n) {
    Stack s;
    initStack(&s);
    while (n > 0) {
        push(&s, n % 2);
        n /= 2;
    }
    while (!isEmptyStack(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int num;
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &num);
    printf("Biner: ");
    decimalToBinary(num);
    return 0;
}
