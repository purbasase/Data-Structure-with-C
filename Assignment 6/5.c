//Write a program to evaluate a postfix expression.



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return 0; // Return 0 if stack is empty (error handling)
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char* postfix) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];

        // If the character is a digit, push it onto the stack
        if (isdigit(current)) {
            push(&s, current - '0'); // Convert char to int
        } 
        // If the character is an operator
        else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;

            switch (current) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Error: Division by zero\n");
                        return 0; // Error handling
                    }
                    break;
                case '^':
                    result = 1;
                    for (int j = 0; j < operand2; j++) {
                        result *= operand1;
                    }
                    break;
                default:
                    printf("Error: Unknown operator %c\n", current);
                    return 0; // Error handling
            }
            push(&s, result);
        }
    }

    return pop(&s); // The result is the last element in the stack
}

// Main function
int main() {
    char postfix[MAX];

    printf("Enter a postfix expression (e.g., 23*54*+): ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strcspn(postfix, "\n")] = 0;

    int result = evaluatePostfix(postfix);
    
    printf("Result of the postfix expression: %d\n",result);
    
    return 0;
}
//OUTPUT
//Enter a postfix expression (e.g., 23*54*+): 23*54*+
//Result of the postfix expression: 26
