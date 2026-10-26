#include <stdio.h>

void printSparseMatrix(int rows,int mat[rows][3])
{
    printf("i (Row)\tj (Col)\tValue\n");
    for (int idx=0;idx<rows;idx++)
    {
        printf("%d\t%d\t%d\n",mat[idx][0],mat[idx][1],mat[idx][2]);
    }
}

void createSparseMatrix(int rows,int cols,int matrix[rows][cols],int sparse[][3])
{
    int nonZeroCount=0;
    
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            if (matrix[i][j]!=0)
            {
                nonZeroCount++;
            }
        }
    }

    sparse[0][0]=rows;
    sparse[0][1]=cols;
    sparse[0][2]=nonZeroCount;

    int k=1;
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            if (matrix[i][j]!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=matrix[i][j];
                k++;
            }
        }
    }
}

void simpleTranspose(int b[][3],int c[][3])
{
    int cols=b[0][1];
    int nonZeroCount=b[0][2];

    c[0][0]=b[0][1];
    c[0][1]=b[0][0];
    c[0][2]=b[0][2];

    int index=1;
    for (int j=0;j<cols;j++)
    {
        for (int i=1;i<=nonZeroCount;i++)
        {
            if (b[i][1]==j)
            {
                c[index][0]=b[i][1];
                c[index][1]=b[i][0];
                c[index][2]=b[i][2];
                index++;
            }
        }
    }
}

void fastTranspose(int b[][3],int c[][3])
{
    int cols=b[0][1];
    int nonZeroCount=b[0][2];

    c[0][0]=b[0][1];
    c[0][1]=b[0][0];
    c[0][2]=b[0][2];

    if (nonZeroCount>0)
    {
        int row_terms[cols];
        int starting_pos[cols];

        for (int j=0;j<cols;j++)
        {
            row_terms[j]=0;
        }

        for (int i=1;i<=nonZeroCount;i++)
        {
            row_terms[b[i][1]]++;
        }

        starting_pos[0]=1;
        for (int j=1;j<cols;j++)
        {
            starting_pos[j]=starting_pos[j-1]+row_terms[j-1];
        }

        for (int i=1;i<=nonZeroCount;i++)
        {
            int col=b[i][1];
            int pos=starting_pos[col];

            c[pos][0]=b[i][1];
            c[pos][1]=b[i][0];
            c[pos][2]=b[i][2];

            starting_pos[col]++;
        }
    }
}

int main() {
    int rows,cols;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d",&rows,&cols)!=2) return 1;

    int a[rows][cols];
    int nonZeroCount=0;

    printf("\nEnter elements of matrix (%dx%d):\n",rows,cols);
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j]!=0)
            {
                nonZeroCount++;
            }
        }
    }
    int b[nonZeroCount+1][3];
    int c_simple[nonZeroCount+1][3];
    int c_fast[nonZeroCount+1][3];
    createSparseMatrix(rows,cols,a,b);

    printf("\n--Original Compact Matrix (b)--\n");
    printSparseMatrix(nonZeroCount+1,b);
    simpleTranspose(b,c_simple);
    printf("\n--Simple Transposed Compact Matrix--\n");
    printSparseMatrix(nonZeroCount+1,c_simple);
    fastTranspose(b,c_fast);
    printf("\n--Fast Transposed Compact Matrix--\n");
    printSparseMatrix(nonZeroCount+1,c_fast);

    return 0;
}
