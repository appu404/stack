#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct Queue {
    int front, rear;
    char arr[MAX];
};

struct Queue* q;

int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

void enqueue(struct Queue* q, char data) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
    printf("'%c' enqueued successfully.\n", data);
}

char dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return '\0';  // Return null character if empty
    }
    char data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return data;
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%c\t", q->arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    char data;

    q = (struct Queue*) malloc(sizeof(struct Queue));

    if (q == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    } else {
        q->front = -1;
        q->rear = -1;
    }

    do {
        printf("\n--- Character Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to enqueue: ");
                scanf(" %c", &data); // space before %c to ignore newline
                enqueue(q, data);
                display(q);
                break;

            case 2:
                data = dequeue(q);
                if (data != '\0')
                    printf("Dequeued character: %c\n", data);
                break;

            case 3:
                display(q);
                break;

            case 4:
                printf("Program exited...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (choice != 4);

    free(q);
    return 0;
}
