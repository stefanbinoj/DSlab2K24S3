#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100
int stack[MAX];
char postfix[MAX];
int top = -1;

// Function to check if a character is an operator
bool is_operator(char a) {
    return (a == '/' || a == '+' || a == '-' || a == '*');
}

// Push a value onto the stack
void push(int a) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(1);  // Exit if the stack is full
    }
    stack[++top] = a;
}

// Pop a value from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);  // Exit if the stack is empty
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
void calc(char postfix[]) {
    int i = 0;
    int val;
    int A, B;
    char item = postfix[i];

    while (item != '$') {
        if (isdigit(item)) {
            // If the item is a digit, push its integer value onto the stack
            push(item - '0');
        }
        else if (is_operator(item)) {
            // If the item is an operator, pop two operands and perform the operation
            A = pop();
            B = pop();
            switch (item) {
                case '*': val = B * A; break;
                case '/': val = B / A; break;
                case '+': val = B + A; break;
                case '-': val = B - A; break;
                default: 
                    printf("Invalid operator\n"); 
                    exit(1);  // Exit if an invalid operator is encountered
            }
            // Push the result back onto the stack
            push(val);
        }
        i++;
        item = postfix[i];  // Move to the next character in the postfix expression
    }

    // The result should be the only value remaining in the stack
    printf("\nResult of expression evaluation: %d\n", pop());
}

int main() {
    int i;

    // Declare an array to store the postfix expression
    printf("ASSUMPTION: There are only four operators (*, /, +, -) in an expression and operand is a single digit only.\n");
    printf("\nEnter postfix expression, press right parenthesis '$' for end expression: ");

    // Take input of the postfix expression from the user
    // This will also consume the newline character after input
    for (i = 0; i < MAX - 1; i++) {
        // Read each character, skipping newline characters
        postfix[i] = getchar();
        
        if (postfix[i] == '$') {
            break;  // End of expression
        }
    }
    postfix[i] = '\0';  // Null-terminate the string

    // Call function to evaluate the postfix expression
    calc(postfix);

    return 0;
}
