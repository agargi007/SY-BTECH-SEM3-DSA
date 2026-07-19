#include <stdio.h>

void add(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, sum[10][10];

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nAddition of Matrix:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ", sum[i][j]);
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

    add(a,b,r,c);

    return 0;
}/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit matrix_add.c &
[1] 441
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc matrix_add.c -o martix_add
[1]+  Done                    gedit matrix_add.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./matrix_add
-bash: ./matrix_add: No such file or directory
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./martix_add
Enter rows and columns: 3
4
Enter first matrix:
12
13
1
5
0
-1
4
5
6
22
0
11
Enter second matrix:
54
7
91
6
0
0
1
12
0
5
3
13

Addition of Matrix:
66 20 92 11
0 -1 5 17
6 27 3 24
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$*/
