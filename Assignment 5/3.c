//Write a Menu driven C program to accomplish the following functionalities in Circular
//Queue using Array:
//i. Insert an element into the circular queue.
//j. Delete an element from the circular queue.
//k. Return the value of the FRONT element of the circular queue (without deleting it
//from the queue).
//l. Display the elements of a circular queue using the circular queue.




#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the circular queue

typedef struct CircularQueue {
    int items[MAX];
    int front, rear;
} CircularQueue;

// Function to create a circular queue and initialize its attributes
CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is full
int isFull(CircularQueue* q) {
    return (q->front == (q->rear + 1) % MAX);
}

// Check if the queue is empty
int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

// Enqueue operation
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Circular Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0; // First element to be added
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Dequeue operation
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int item = q->items[q->front];
        if (q->front == q->rear) {
            // Reset the queue if the last element is dequeued
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return item;
    }
}

// Peep operation
int peep(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty. No front element.\n");
        return -1;
    } else {
        return q->items[q->front];
    }
}

// Display operation
void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

// Main function to drive the menu
int main() {
    CircularQueue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                value = peep(q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                display(q);
                break;
            case 5:
                free(q);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
