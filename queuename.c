#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 5
#define MAX_LEN 50

typedef struct {
    int front;
    int rear;
    char names[SIZE][MAX_LEN];
} Queue;

bool isFull(Queue *q) {
    return q->rear == SIZE - 1;
}

bool isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, const char *name) {
    if (isFull(q))
        printf("Queue is full! Cannot insert '%s'\n", name);
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        strcpy(q->names[q->rear], name);
        printf("'%s' enqueued successfully\n", name);
    }
}

void dequeue(Queue *q) {
    if (isEmpty(q))
        printf("Queue is empty! Nothing to dequeue\n");
    else {
        printf("Dequeued name: %s\n", q->names[q->front]);
        q->front++;
    }
}

void display(Queue *q) {
    if (isEmpty(q))
        printf("Queue is empty!\n");
    else {
        printf("Queue contents: ");
        for (int i = q->front; i <= q->rear; i++)
            printf("%s ", q->names[i]);
        printf("\n");
    }
}

int main() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    int n;
    char name[MAX_LEN];

    printf("Enter how many names to enqueue (max %d): ", SIZE);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", name);
        enqueue(q, name);
    }

    display(q);
    dequeue(q);
    display(q);

    free(q);
    return 0;
}
