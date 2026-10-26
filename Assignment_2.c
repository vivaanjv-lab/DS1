#include<stdio.h>
void accept(int a[10][10], int r, int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void display(int a[10][10], int r, int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void comp(int a[10][10], int r, int c, int com[10][10])
{
    int row=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                com[row][0]=i;
                com[row][1]=j;
                com[row][2]=a[i][j];
                row++;
            }
        }
    }
    com[0][0]=r;
    com[0][1]=c;
    com[0][2]=row-1;
}
void simp(int mb[10][10], int mb1[10][10])
{
    mb1[0][0]=mb[0][1];
    mb1[0][1]=mb[0][0];
    mb1[0][2]=mb[0][2];
    int k=1;
    int n=mb[0][2];
    for(int i=0;i<mb[0][1];i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==mb[j][1])
            {
                mb1[k][0]=mb[j][1];
                mb1[k][1]=mb[j][0];
                mb1[k][2]=mb[j][2];
                k++;
            }
        }
    }
}
void fasttrans(int mb[10][10], int mb1[10][10])
{
    mb1[0][0] = mb[0][1];
    mb1[0][1] = mb[0][0];
    mb1[0][2] = mb[0][2];

    int count[50] = {0};
    int pos[50] = {0};
    pos[0] = 1;
    int m;

    for(int i = 1; i<=mb[0][2]; i++)
    {
        m = mb[i][1];
        count[m]++;
    }
    for(int i = 1; i<mb[0][1]; i++)
    {
        pos[i] = pos[i-1] + count[i-1];
    }
    for(int i = 1; i<= mb[0][2]; i++)
    {
        m = mb[i][1];
        mb1[pos[m]][0] = mb[i][1];
        mb1[pos[m]][1] = mb[i][0];
        mb1[pos[m]][2] = mb[i][2];
        pos[m]++;
    }
    mb1[0][0] = mb[0][1];
    mb1[0][1] = mb[0][0];
    mb1[0][2] = mb[0][2];
}
int main()
{
    int a[10][10],r,c;
    printf("Enter row and column of Matrix A: ");
    scanf("%d%d",&r,&c);
    printf("Enter elements of Matrix A:\n");
    accept(a,r,c);
    printf("\nMatrix A:\n");
    display(a,r,c);
    int com[10][10],trans[10][10], fast[10][10];
    comp(a,r,c,com);
    printf("\nCompact Matrix:\n");
    display(com,com[0][2]+1,3);
    simp(com,trans);
    printf("\nSimple Transpose:\n");
    display(trans,trans[0][2]+1,3);
    fasttrans(com,fast);
    printf("\nFast Transpose:\n");
    display(fast, fast[0][2]+1, 3);
    return 0;
}