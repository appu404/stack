#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 5
#define MAX_LEN 50

typedef struct {
    int top;
    char names[SIZE][MAX_LEN];
} Stack;

bool isFull(Stack *s) {
    return s->top == SIZE - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, const char *name) {
    if (isFull(s))
        printf("Stack Overflow! Cannot push '%s'\n", name);
    else {
        s->top++;
        strcpy(s->names[s->top], name);
    }
}

void pop(Stack *s) {
    if (isEmpty(s))
        printf("Stack Underflow! Nothing to pop\n");
    else {
        printf("Popped name: %s\n", s->names[s->top]);
        s->top--;
    }
}

void display(Stack *s) {
    if (isEmpty(s))
        printf("Stack is empty!\n");
    else {
        printf("Stack contents (top to bottom): ");
        for (int i = s->top; i >= 0; i--)
            printf("%s ", s->names[i]);
        printf("\n");
    }
}

int main() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;

    int n;
    char name[MAX_LEN];

    printf("Enter how many names to push (max %d): ", SIZE);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", name);
        push(s, name);
    }

    display(s);
    pop(s);
    display(s);

    free(s);
    return 0;
}
