#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 50

int stack[SIZE];
int top = -1;

void pushval(int val)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = val;
}

int popval()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int calc(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
            {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            return a / b;
        case '^':
            return (int)pow(a, b);
        default:
            return 0;
    }
}

void eval(char post[SIZE])
{
    int i = 0, z, op1, op2, ans;

    for (i = 0; post[i] != '\0'; i++)
    {
        if (post[i] == ' ' || post[i] == '\t')
            continue;

        if (isalpha(post[i]))
        {
            printf("Enter value for %c: ", post[i]);
            scanf("%d", &z);
            pushval(z);
        }
        else if (isdigit(post[i]))
        {
            int num = 0;
            while (isdigit(post[i]))
            {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            i--;
            pushval(num);
        }
        else
        {
            op2 = popval();
            op1 = popval();
            ans = calc(op1, op2, post[i]);
            pushval(ans);
        }
    }

    printf("\nEvaluation Result = %d\n", stack[top]);
}

int main()
{
    char postfix[SIZE];

    printf("--- Postfix Expression Evaluation ---\n");
    printf("Enter Postfix expression (e.g., '623+-382/+*2^3+' or '3 5 + 4 *'): ");
    scanf("%[^\n]s", postfix);

    eval(postfix);

    return 0;
}