#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct Queue {
    int arr[MAX];
    int front, rear;
};

struct Queue* q;

int isFull(struct Queue* q) {
    return ((q -> rear + 1) % MAX == q -> front);
}

int isEmpty(struct Queue* q) {
    return ((q -> front == -1) && (q -> rear == -1));
}

void enqueue(struct Queue* q, int data) {
    if(isFull(q)) {
        printf("Queue Overflow...!");
        return;
    }
    if(isEmpty(q)) {
        q -> front = 0;
    }
    q -> rear = (q -> rear + 1) % MAX;
    q -> arr[q -> rear] = data;
}

int dequeue(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue Undeflow...!");
        return -1;
    }
    int val = q -> arr[q -> front];
    if(q -> front == q -> rear) {
        q -> front = -1;
        q -> rear = -1;
    }
    else {
        q -> front = (q -> front + 1) % MAX;
    }
    return val;
}

void display(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty...!");
        return;
    }
    printf("Elements [front to rear] : ");
    int  i = q -> front;

    do {
        printf("%d\t", q-> arr[i]);
        i = (i+1) % MAX;
    } while(i != (q -> rear + 1) % MAX);

    printf("\n");
   
}

int main() {
    int choice, data;

    q = (struct Queue*) malloc(sizeof(struct Queue));

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
