#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
typedef struct {
    char items[SIZE][SIZE];
    int top;
} Stack;
Stack s;
void init() {
    s.top = -1;
}
int isEmpty() {
    return s.top == -1;
}
int isFull() {
    return s.top == SIZE - 1;
}
void push(char str[]) {
    if (!isFull())
        strcpy(s.items[++s.top], str);
}
int pop(char str[]) {
    if (!isEmpty()) {
        strcpy(str, s.items[s.top--]);
        return 1;
    }
    return 0;
}
char charStack[SIZE];
int charTop = -1;
void charInit() {
    charTop = -1;
}
void charPush(char ch) {
    if (charTop < SIZE - 1)
        charStack[++charTop] = ch;
}
char charPop() {
    if (charTop != -1)
        return charStack[charTop--];
    return '\0';
}
char charPeek() {
    if (charTop != -1)
        return charStack[charTop];
    return '\0';
}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
int precedence(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}
void prefixToInfix(char prefix[]) {
    char op1[SIZE], op2[SIZE], temp[SIZE], operand[2];
    int i;
    init();
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (prefix[i] == ' ' || prefix[i] == '\t')
            continue;
        if (isalnum(prefix[i])) {
            operand[0] = prefix[i];
            operand[1] = '\0';
            push(operand);
        }
        else if (isOperator(prefix[i])) {
            if (!pop(op1) || !pop(op2)) {
                printf("Invalid prefix expression\n");
                return;
            }
            temp[0] = '\0';
            strcat(temp, "(");
            strcat(temp, op1);
            operand[0] = prefix[i];
            operand[1] = '\0';
            strcat(temp, operand);
            strcat(temp, op2);
            strcat(temp, ")");
            push(temp);
        }
        else {
            printf("Invalid prefix expression\n");
            return;
        }
    }
    if (s.top != 0) {
        printf("Invalid prefix expression\n");
        return;
    }
    pop(temp);
    printf("Infix expression: %s\n", temp);
}
void postfixToPrefix(char postfix[]) {
    char op1[SIZE], op2[SIZE], temp[SIZE], operand[2];
    int i;
    init();
    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] == ' ' || postfix[i] == '\t')
            continue;
        if (isalnum(postfix[i])) {
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(operand);
        }
        else if (isOperator(postfix[i])) {
            if (!pop(op2) || !pop(op1)) {
                printf("Invalid postfix expression\n");
                return;
            }
            temp[0] = postfix[i];
            temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);
            push(temp);
        }
        else {
            printf("Invalid postfix expression\n");
            return;
        }
    }
    if (s.top != 0) {
        printf("Invalid postfix expression\n");
        return;
    }
    pop(temp);
    printf("Prefix expression: %s\n", temp);
}
void infixToPostfix(char infix[]) {
    char postfix[SIZE];
    int i, j = 0;
    char ch;
    charInit();
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (ch == ' ' || ch == '\t')
            continue;
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            charPush(ch);
        }
        else if (ch == ')') {
            while (charTop != -1 && charPeek() != '(') {
                postfix[j++] = charPop();
            }
            if (charTop != -1 && charPeek() == '(') {
                charPop();
            } else {
                printf("Invalid infix expression\n");
                return;
            }
        }
        else if (isOperator(ch)) {
            while (charTop != -1 && charPeek() != '(' && 
                  ((precedence(charPeek()) > precedence(ch)) || 
                   (precedence(charPeek()) == precedence(ch) && ch != '^'))) {
                postfix[j++] = charPop();
            }
            charPush(ch);
        }
        else {
            printf("Invalid infix expression\n");
            return;
        }
    }
    while (charTop != -1) {
        if (charPeek() == '(') {
            printf("Invalid infix expression\n");
            return;
        }
        postfix[j++] = charPop();
    }   
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}
int main() {
    int choice;
    char expr[SIZE];
    printf("Choose conversion type:\n");
    printf("1. Infix to Postfix\n");
    printf("2. Prefix to Infix\n");
    printf("3. Postfix to Prefix\n");
    printf("Enter your choice (1-3): ");   
    if (scanf("%d", &choice) != 1) {
        return 0;
    }
    getchar();
    printf("Enter the expression: ");
    if (fgets(expr, sizeof(expr), stdin) != NULL) {
        expr[strcspn(expr, "\n")] = '\0';
    }
    switch (choice) {
        case 1:
            infixToPostfix(expr);
            break;
        case 2:
            prefixToInfix(expr);
            break;
        case 3:
            postfixToPrefix(expr);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}