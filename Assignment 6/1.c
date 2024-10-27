//Write a Menu driven C program to accomplish the following functionalities in Stack using
//an Array:
//a. Insert an element into the stack using an array (Push Operation).
//b. Delete an element from the stack using an array (Pop Operation).
//c. Return the value of the topmost element of the stack (without deleting it from the
//stack) using an array.
//d. Display the elements of a stack using an array.


#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

// Function to create a queue and initialize its attributes
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is full
int isFull(Queue* q) {
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Enqueue operation
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // First element to be added
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Dequeue operation
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            // Reset the queue
            q->front = -1;
            q->rear = -1;
        }
        return item;
    }
}

// Peep operation
int peep(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    } else {
        return q->items[q->front];
    }
}

// Display operation
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Main function to drive the menu
int main() {
    Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Menu:\n");
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
