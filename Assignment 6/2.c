//Write a Menu driven C program to accomplish the following functionalities in Stack using
//Linked List:
//a. Insert an element into the stack using a Linked List (Push Operation).
//b. Delete an element from the stack using a Linked List (Pop Operation).
//c. Return the value of the topmost element of the stack (without deleting it from the
//stack) using a Linked List.
//d. Display the elements of the stack using a Linked List.



#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Function to initialize the stack
void initStack(struct Stack* s) {
    s->top = NULL;  // Stack is initially empty
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;  // Point new node to the previous top
    s->top = newNode;         // Update top to the new node
    printf("%d pushed onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return -1;  // Return -1 to indicate failure
    }
    struct Node* temp = s->top;
    int poppedValue = temp->data; // Get the value to return
    s->top = s->top->next;        // Move top to the next node
    free(temp);                   // Free the old top node
    return poppedValue;
}

// Function to peek at the top element of the stack
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No top element\n");
        return -1;  // Return -1 to indicate no element
    }
    return s->top->data;
}

// Function to display the elements of the stack
void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* current = s->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function with menu-driven interface
int main() {
    struct Stack s;
    initStack(&s);
    
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("%d popped from the stack\n", value);
                }
                break;
            case 3:
                value = peek(&s);
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
