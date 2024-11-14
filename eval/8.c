#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

bool is_operator(char a) {
    return (a == '+' || a == '-' || a == '*' || a == '/' || a == '^');
}

int precedence(char a) {
    if (a == '^') return 3;
    if (a == '*' || a == '/') return 2;
    if (a == '+' || a == '-') return 1;
    return -1;
}

void push(char a) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1); // Exit if stack overflows
    }
    stack[++top] = a;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow: Invalid\n");
        exit(1); // Exit if stack is empty
    }
    return stack[top--];
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char item, x;

    // Add a right parenthesis at the end to help process the whole expression
    push('(');
    strcat(infix, ")");
    
    item = infix[i]; // First character of infix expression

    while (item != '\0') {
        if (item == '(') {
            push(item);
        }
        else if (is_operator(item)) {
            x = pop();
            while (is_operator(x) && precedence(x) >= precedence(item)) {
                postfix[j++] = x;
                x = pop();
            }
            push(x); // push the operator back onto the stack
            push(item);
        }
        else if (isalnum(item)) { // Operand (variable or number)
            postfix[j++] = item;
        }
        else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix[j++] = x;
                x = pop();
            }
        }
        else {
            printf("Invalid symbol encountered: %c\n", item);
            exit(1); // Exit if an invalid symbol is encountered
        }

        i++; // Move to the next character in the infix expression
        item = infix[i]; // Update item with the new character
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression

    // Check if the stack has any remaining operators
    if (top >= 0) {
        printf("\nInvalid infix expression.\n");
        exit(1); // Exit if the expression is not valid
    }
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
    printf("\nEnter Infix expression: ");
    scanf("%s", infix); // Read the infix expression

    // Make sure the infix string is properly null-terminated
    infix[strlen(infix)] = '\0'; // Null terminate the string manually if necessary

    infixToPostfix(infix, postfix);  // Convert to postfix
    printf("Postfix Expression: ");
    puts(postfix);  // Output the postfix expression

    return 0;
}
