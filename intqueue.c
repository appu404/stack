#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct Queue {
    int front, rear;
    int arr[MAX];
};

struct Queue* q;

int isFull(struct Queue* q) {
    return (q -> rear == MAX - 1);
}

int isEmpty(struct Queue* q) {
    return (q -> front == -1 && q -> rear == -1);
}

void enqueue(struct Queue* q, int data) {
    if(isFull(q)) {
        printf("Queue Overflow...!");
        return;
    }
    if(isEmpty(q)) {
        q -> front = 0;
    }
    q -> rear++;
    q -> arr[q -> rear] = data;
}

int dequeue(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue Underflow...!");
        return -1;
    }
    int data = q -> arr[q -> front];
    if(q -> front == q -> rear) {
        q -> front = -1;
        q -> rear = -1;
    }
    else {
        q -> front++;
    }
    return data;
}

void display(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is Empty...!");
        return;
    }
    printf("Queue elements : ");
    for(int i = q -> front; i <= q -> rear; i++) {
        printf("%d \t", q -> arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    q = (struct Queue*) malloc (sizeof(struct Queue));

    if(q == NULL) {
        printf("Memory allocation failed...!");
        return -1;
    }
    else {
        q -> front = -1;
        q -> rear = -1;
    }

    do {
        printf("1. Enqueue \n2. Dequeue \n3. Display \n4. Exit\nChoice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1 :
                printf("Enter element to enqueue : ");
                scanf("%d", &data);

                enqueue(q, data);
                display(q);
                break;
            case 2 :
                int val = dequeue(q);
                printf("Element dequeued : %d\n", val);
                break;
            case 3 :
                display(q);
                break;
            case 4 :
                printf("Prgrm exited...!");
                break;
            default :
                printf("Invalid choice...!");
                break;
        }
    }while(choice != 4);

    return 0;
}
