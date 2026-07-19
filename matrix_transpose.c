#include <stdio.h>

void transpose(int a[10][10], int r, int c)
{
    int i, j, t[10][10];

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            t[j][i] = a[i][j];
        }
    }

    printf("\nTranspose Matrix:\n");
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10], r, c, i, j;

    printf("Enter rows and columns: ");
    scanf("%d%d",&r,&c);

    printf("Enter matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    transpose(a,r,c);

    return 0;
}
/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./matrix_transpose
Enter rows and columns: 3
3
Enter matrix:
12
5
2
9
-3
-11
0
0
45

Transpose Matrix:
12 9 0
5 -3 0
2 -11 45
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$*/
