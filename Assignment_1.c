#include <stdio.h>

void accept(int a[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void add(int a[10][10], int b[10][10], int sum[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract(int a[10][10], int b[10][10], int sub[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }
}

void transpose(int a[10][10], int t[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            t[j][i] = a[i][j];
        }
    }
}

void multiply(int a[10][10], int b[10][10], int mul[10][10], int r1, int c1, int c2)
{
    int i, j, k;
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            mul[i][j] = 0;
            for(k = 0; k < c1; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int a[10][10], b[10][10];
    int sum[10][10], sub[10][10], t[10][10], mul[10][10];
    int r1, c1, r2, c2;
    int ch;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter elements of first matrix:\n");
    accept(a, r1, c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);
    printf("Enter elements of second matrix:\n");
    accept(b, r2, c2);
    do
    {
        printf("\n\n----- MENU -----");
        printf("\n1. Display Matrices");
        printf("\n2. Addition");
        printf("\n3. Subtraction");
        printf("\n4. Transpose of First Matrix");
        printf("\n5. Transpose of Second Matrix");
        printf("\n6. Multiplication");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nFirst Matrix:\n");
                display(a, r1, c1);
                printf("\nSecond Matrix:\n");
                display(b, r2, c2);
                break;
            case 2:
                if(r1 == r2 && c1 == c2)
                {
                    add(a, b, sum, r1, c1);
                    display(sum, r1, c1);
                }
                else
                    printf("\nAddition not possible.");
                break;
            case 3:
                if(r1 == r2 && c1 == c2)
                {
                    subtract(a, b, sub, r1, c1);
                    display(sub, r1, c1);
                }
                else
                    printf("\nSubtraction not possible.");
                break;
            case 4:
                printf("\nTranspose of First Matrix:");
                transpose(a, t, r1, c1);
                printf("\nTranspose:\n");
                display(t, c1, r1);
                break;
            case 5:
                printf("\nTranspose of Second Matrix:");
                transpose(b, t, r2, c2);
                printf("\nTranspose:\n");
                display(t, c2, r2);
                break;
            case 6:
                if(c1 == r2)
                {
                    multiply(a, b, mul, r1, c1, c2);
                    printf("\nMultiplication:\n");
                    display(mul, r1, c2);
                }
                else
                    printf("\nMultiplication not possible.");
                break;
            case 7:
                printf("\nProgram Ended.");
                break;
            default:
                printf("\nInvalid Choice.");
        }
    } while(ch != 7);
    return 0;
}