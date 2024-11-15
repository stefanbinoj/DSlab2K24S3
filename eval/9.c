#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

char infix[MAX];
char prefix[MAX];
char stack[MAX];
int top = -1;

bool is_operator(char a) {
    return (a == '/' || a == '*' || a == '^' || a == '+' || a == '-');
}

void push(char a) {
    if (top == MAX - 1) {
        printf("Overflow \n");
        exit(0);  // Exit if the stack overflows
    }
    stack[++top] = a;
}

char pop() {
    if (top == -1) {
        printf("Underflow \n");
        exit(0);  // Exit if the stack underflows
    }
    return stack[top--];
}

int precedence(char a) {
    if (a == '^') return 3;
    if (a == '*' || a == '/') return 2;
    if (a == '+' || a == '-') return 1;
    return 0;
}

char *strrev(char *str) {
    if (!str || !*str) return str;
    int i = strlen(str) - 1, j = 0;
    while (i > j) {
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

void infix_to_prefix() {
    int i = 0, j = 0;
    char x;
    strrev(infix);  // Reverse the infix expression
    char item = infix[i];

    while (item != '\0') {
        if (isalnum(item)) {  // If the item is an operand, add it to the result
            prefix[j++] = item;
        } else if (is_operator(item)) {  // If the item is an operator
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                prefix[j++] = pop();  // Pop operators with higher or equal precedence
            }
            push(item);  // Push the current operator onto the stack
        } else if (item == ')' || item == '}' || item == ']') {
            push(item);  // Push closing parentheses onto the stack
        } else if (item == '(' || item == '[' || item == '{') {  // When opening parentheses are encountered
            while (top != -1 && stack[top] != '(' && stack[top] != '[' && stack[top] != '{') {
                prefix[j++] = pop();  // Pop operators until matching opening parentheses
            }
            pop();  // Pop the opening parentheses
        }
        i++;
        item = infix[i];
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        prefix[j++] = pop();
    }

    // Reverse the final string before output
    prefix[j] = '\0';
    strrev(prefix);
    printf("Equivalent Prefix Notation: %s\n", prefix);
}

int main() {
    printf("Input the infix expression: ");
    scanf("%s", infix);
    infix_to_prefix();
    return 0;
}
