#include <stdio.h>
#define n 5

int queue[n];
int front = -1, rear = -1;

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else if ((rear + 1) % n == front) {
        printf("Queue is full\n");
    } else {
        rear = (rear + 1) % n;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Dequeued element is %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Dequeued element is %d\n", queue[front]);
        front = (front + 1) % n;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int ch;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to enqueue: ");
                int element;
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
