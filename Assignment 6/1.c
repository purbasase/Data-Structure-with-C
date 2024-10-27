//Write a Menu driven C program to accomplish the following functionalities in Stack using
//an Array:
//a. Insert an element into the stack using an array (Push Operation).
//b. Delete an element from the stack using an array (Pop Operation).
//c. Return the value of the topmost element of the stack (without deleting it from the
//stack) using an array.
//d. Display the elements of a stack using an array.


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;  // Stack is initially empty
}

// Function to check if the stack is full
bool isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
    printf("%d pushed onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return -1;  // Return -1 to indicate failure
    }
    return s->arr[s->top--];
}

// Function to peek at the top element of the stack
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No top element\n");
        return -1;  // Return -1 to indicate no element
    }
    return s->arr[s->top];
}

// Function to display the elements of the stack
void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
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
