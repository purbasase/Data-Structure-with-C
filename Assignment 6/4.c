//Write a program to convert an infix expression into its equivalent prefix notation.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
struct Stack {
    char arr[MAX];
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
void push(struct Stack* s, char value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to peek at the top element of the stack
char peek(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to check the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to reverse a string
void reverse(char* expr) {
    int n = strlen(expr);
    for (int i = 0; i < n / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[n - i - 1];
        expr[n - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(const char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int k = 0; // Index for postfix expression

    for (int i = 0; i < strlen(infix); i++) {
        char current = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(current)) {
            postfix[k++] = current;
        } 
        // If the character is '(', push it onto the stack
        else if (current == '(') {
            push(&s, current);
        } 
        // If the character is ')', pop from the stack until '(' is found
        else if (current == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // Remove '(' from the stack
        } 
        // If the character is an operator
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(current)) {
                postfix[k++] = pop(&s);
            }
            push(&s, current);
        }
    }

    // Pop all the operators from the stack
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0'; // Null-terminate the postfix expression
}

// Function to convert infix to prefix
void infixToPrefix(const char* infix, char* prefix) {
    // Reverse the infix expression
    char reversedInfix[MAX];
    int len = strlen(infix);
    for (int i = 0; i < len; i++) {
        if (infix[len - 1 - i] == '(') {
            reversedInfix[i] = ')';
        } else if (infix[len - 1 - i] == ')') {
            reversedInfix[i] = '(';
        } else {
            reversedInfix[i] = infix[len - 1 - i];
        }
    }
    reversedInfix[len] = '\0';

    // Convert the reversed infix to postfix
    char postfix[MAX];
    infixToPostfix(reversedInfix, postfix);

    // Reverse the postfix expression to get the prefix expression
    reverse(postfix);
    strcpy(prefix, postfix);
}

// Main function
int main() {
    char infix[MAX];
    char prefix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove newline character

    infixToPrefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}
//OUTPUT
//Enter an infix expression: A+B*(C^D-E)^(F+G*H)
//Prefix expression: +A*B^-^CDE+F*GH
