#include <stdio.h>

void readMatrix(int r,int c,int mat[ ][c],const char *name) 
{
    printf("\nEnter elements for %s:\n",name);
    for (int i=0;i<r;i++) 
    {
        for (int j=0;j<c;j++) 
        {
            printf("Element [%d][%d]: ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
}

void printMatrix(int r,int c,int mat[r][c]) 
{
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void addMatrices(int r,int c,int m1[r][c],int m2[r][c]) 
{
    int result[r][c];
    printf("\nAddition of Matrices:\n");
    for (int i=0;i<r;i++) 
    {
        for (int j=0;j<c;j++) 
        {
            result[i][j]=m1[i][j]+m2[i][j];
        }
    }
    printMatrix(r,c,result);
}

void subtractMatrices(int r,int c,int m1[r][c],int m2[r][c]) 
{
    int result[r][c];
    printf("\nSubtraction of Matrices:\n");
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            result[i][j]=m1[i][j]-m2[i][j];
        }
    }
    printMatrix(r,c,result);
}

void multiplyMatrices(int r,int c,int m1[r][c],int m2[r][c]) 
{
    int result[r][c];
    printf("\nMultiplication of Matrices:\n");
    for (int i=0;i<r;i++) 
    {
        for (int j=0;j<c;j++) 
        {
            result[i][j]=0;
            for (int k=0;k<c;k++) 
            {
                result[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    printMatrix(r,c,result);
}

void transposeMatrix(int r,int c,int mat[r][c]) 
{
    int result[c][r];
    printf("\nTranspose of the 1st Matrix:\n");
    for (int i=0;i<r;i++) 
    {
        for (int j=0;j<c;j++) 
        {
            result[j][i]=mat[i][j];
        }
    }
    printMatrix(c,r,result);
}

int main() 
{
    int rows,cols;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    printf("Enter the number of columns: ");
    scanf("%d",&cols);

    int matrix1[rows][cols],matrix2[rows][cols];

    readMatrix(rows,cols,matrix1,"1st matrix");
    readMatrix(rows,cols,matrix2,"2nd matrix");

    printf("\nThe 1st Matrix is:\n");
    printMatrix(rows,cols,matrix1);
    printf("\nThe 2nd Matrix is:\n");
    printMatrix(rows,cols,matrix2);

    addMatrices(rows,cols,matrix1,matrix2);
    subtractMatrices(rows,cols,matrix1,matrix2);

    if (rows==cols) 
    {
        multiplyMatrices(rows,cols,matrix1,matrix2);
    } else 
    {
        printf("\nMultiplication requires square matrices for identical dimensions (%dx%d).\n",rows,cols);
    }

    transposeMatrix(rows,cols,matrix1);
    return 0;
}