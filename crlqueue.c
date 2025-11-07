#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;
    
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No element to delete\n");
        return;
    }

    printf("%d deleted from queue\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
