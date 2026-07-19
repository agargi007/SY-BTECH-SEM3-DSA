#include <stdio.h>

void subtract(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, sub[10][10];

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("\nSubtraction of Matrix:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10], r, c, i, j;

    printf("Enter rows and columns: ");
    scanf("%d%d",&r,&c);

    printf("Enter first matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    printf("Enter second matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&b[i][j]);

    subtract(a,b,r,c);

    return 0;
}
/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./matrix_sub
Enter rows and columns: 3
3
Enter first matrix:
12
11
0
-1
15
-11
5
31
13
Enter second matrix:
0
12
65
-7
3
-4
1
0
33

Subtraction of Matrix:
12 -1 -65
6 12 -7
4 31 -20
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$
*/
