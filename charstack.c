#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct Stack {
    char arr[MAX];
    int top;
};

struct Stack* s;

int isFull(struct Stack* s) {
    return (s -> top == MAX - 1);
}

int isEmpty(struct Stack* s) {
    return (s -> top == -1);
}

void push(struct Stack* s, char data) {
    if(isFull(s)) {
        printf("Overflow...!");
        return;
    }
    s -> top++;
    s -> arr[s -> top] = data;
}

char pop(struct Stack* s) {
    if(isEmpty(s)) {
        printf("Underflow...!");
        return -1;
    }
    char val = s -> arr[s -> top];
    s -> top--;

    return val;
}

char peek(struct Stack* s) {
    if(isEmpty(s)) {
        printf("Underflow...!");
        return -1 ;
    }
    char elem = s -> arr[s -> top];
    return elem;
}

void display(struct Stack* s) {
    if(isEmpty(s)){
        printf("Empty Stack...!");
        return;
    } 
    printf("Stack [top - bottom] : \n");
    for(int i = s -> top; i >= 0; i--) {
        printf("%c\n", s -> arr[i]);
    }
}

int main() {
    
    int choice;
    char data;

    s = (struct Stack*) malloc (sizeof(struct Stack));
    if(s == NULL) {
        printf("Memory not allocated...!");
        return -1;
    }
    else {
        s -> top = -1;
    }

    do {

        printf("1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit \nEnter choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to push : ");
                scanf(" %c", &data);
                push(s, data);

                display(s);
                break;
            case 2:
                char val = pop(s);
                printf("Element popped : %c\n", val);
                break;
            case 3 :
                char elem = peek(s);
                printf("Element at top : %c\n", elem);
                break;
            case 4:
                display(s);
                break;
            case 5:
                printf("Program exited...\n");
                break;
            default:
                printf("Invalid choice...\n");
        }
    } while (choice != 5);
    return 0;
}
