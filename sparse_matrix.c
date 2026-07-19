#include <stdio.h>

void accept_matrix(int r, int c, int a[10][10])
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("Matrix[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void compact_matrix(int r, int c, int a[10][10], int b[20][3])
{
    int i, j;
    int k = 1;

    b[0][0] = r;
    b[0][1] = c;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }

    b[0][2] = k - 1;
}

void display_compact(int b[20][3])
{
    int i;
    int rows = b[0][2] + 1;

    printf("\nRow\tCol\tValue\n");

    for(i = 0; i < rows; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

int main()
{
    int a1[10][10], a2[10][10];
    int b[20][3], d[20][3];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter Matrix 1:\n");
    accept_matrix(r1, c1, a1);

    printf("Enter rows and columns for Matrix 2: ");
    scanf("%d%d", &r2, &c2);

    printf("Enter Matrix 2:\n");
    accept_matrix(r2, c2, a2);

    compact_matrix(r1, c1, a1, b);
    compact_matrix(r2, c2, a2, d);

    printf("\nCompact Matrix 1\n");
    display_compact(b);

    printf("\nCompact Matrix 2\n");
    display_compact(d);

    return 0;
}

/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./sparse_matrix
Enter rows and columns for Matrix 1: 3
3
Enter Matrix 1:
Matrix[0][0] : 12
Matrix[0][1] : 0
Matrix[0][2] : 0
Matrix[1][0] : 0
Matrix[1][1] : 0
Matrix[1][2] : 0
Matrix[2][0] : 0
Matrix[2][1] : -11
Matrix[2][2] : 0
Enter rows and columns for Matrix 2: 4
3
Enter Matrix 2:
Matrix[0][0] : 0
Matrix[0][1] : 0
Matrix[0][2] : 0
Matrix[1][0] : 0
Matrix[1][1] : 0
Matrix[1][2] : 0
Matrix[2][0] : 0
Matrix[2][1] : 0
Matrix[2][2] : -9
Matrix[3][0] : 0
Matrix[3][1] : 0
Matrix[3][2] : 0

Compact Matrix 1

Row     Col     Value
3       3       2
0       0       12
2       1       -11

Compact Matrix 2

Row     Col     Value
4       3       1
2       2       -9
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$*/
