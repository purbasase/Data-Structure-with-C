//Write a Menu driven C program to accomplish the following functionalities in Queue using
//Linked List:
//e. Insert an element into the queue using a Linked List (Enqueue Operation).
//f. Delete an element from the queue using a Linked List (Dequeue Operation).
//g. Return the value of the FRONT element of the queue (without deleting it from the
//queue) using a Linked List (Peep operation).
//h. Display the elements of a queue using a Linked List.



#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Enqueue operation
void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Dequeue operation
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        Node* temp = q->front;
        int item = temp->data;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL; // Queue is now empty
        }
        free(temp);
        return item;
    }
}

// Peep operation
int peep(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    } else {
        return q->front->data;
    }
}

// Display operation
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        Node* temp = q->front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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
                // Free the queue and its nodes
                while (!isEmpty(q)) {
                    dequeue(q);
                }
                free(q);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
