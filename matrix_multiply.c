#include <stdio.h>

void multiply(int a[10][10], int b[10][10], int r1, int c1, int c2)
{
    int i, j, k, mul[10][10];

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            mul[i][j]=0;

            for(k=0;k<c1;k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMultiplication of Matrix:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10];
    int r1,c1,r2,c2,i,j;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d",&r1,&c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d",&r2,&c2);

    if(c1!=r2)
    {
        printf("Multiplication not possible");
        return 0;
    }

    printf("Enter first matrix:\n");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&a[i][j]);

    printf("Enter second matrix:\n");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&b[i][j]);

    multiply(a,b,r1,c1,c2);

    return 0;
}
/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./matrix_multiply
Enter rows and columns of first matrix: 2
2
Enter rows and columns of second matrix: 2
2
Enter first matrix:
12
-6
11
3
Enter second matrix:
-3
4
15
90

Multiplication of Matrix:
-126 -492
12 314
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$*/
