#include <stdio.h>

void accept_matrix(int r, int c, int a[10][10])
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("Matrix[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void compact_matrix(int r, int c, int a[10][10], int b[20][3])
{
    b[0][0] = r;
    b[0][1] = c;

    int k = 1;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
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
    int rows = b[0][2] + 1;

    printf("\nRow\tCol\tValue\n");

    for(int i = 0; i < rows; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

void add_sparse(int b[20][3], int d[20][3], int e[20][3])
{
    int i = 1, j = 1, k = 1;

    if(b[0][0] != d[0][0] || b[0][1] != d[0][1])
    {
        printf("\nAddition not possible!\n");
        return;
    }

    e[0][0] = b[0][0];
    e[0][1] = b[0][1];

    while(i <= b[0][2] && j <= d[0][2])
    {
        if(b[i][0] == d[j][0] && b[i][1] == d[j][1])
        {
            e[k][0] = b[i][0];
            e[k][1] = b[i][1];
            e[k][2] = b[i][2] + d[j][2];
            i++;
            j++;
            k++;
        }
        else if((b[i][0] < d[j][0]) ||
               (b[i][0] == d[j][0] && b[i][1] < d[j][1]))
        {
            e[k][0] = b[i][0];
            e[k][1] = b[i][1];
            e[k][2] = b[i][2];
            i++;
            k++;
        }
        else
        {
            e[k][0] = d[j][0];
            e[k][1] = d[j][1];
            e[k][2] = d[j][2];
            j++;
            k++;
        }
    }

    while(i <= b[0][2])
    {
        e[k][0] = b[i][0];
        e[k][1] = b[i][1];
        e[k][2] = b[i][2];
        i++;
        k++;
    }

    while(j <= d[0][2])
    {
        e[k][0] = d[j][0];
        e[k][1] = d[j][1];
        e[k][2] = d[j][2];
        j++;
        k++;
    }

    e[0][2] = k - 1;
}

int main()
{
    int a[10][10], c[10][10];
    int b[20][3], d[20][3], e[20][3];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter Matrix 1:\n");
    accept_matrix(r1, c1, a);

    printf("Enter rows and columns for Matrix 2: ");
    scanf("%d%d", &r2, &c2);

    printf("Enter Matrix 2:\n");
    accept_matrix(r2, c2, c);

    compact_matrix(r1, c1, a, b);
    compact_matrix(r2, c2, c, d);

    printf("\nCompact Matrix 1:");
    display_compact(b);

    printf("\nCompact Matrix 2:");
    display_compact(d);

    add_sparse(b, d, e);

    printf("\nAddition of Sparse Matrices:");
    display_compact(e);

    return 0;
}
/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./sparse_matrix_addition
Enter rows and columns for Matrix 1:
3

3
Enter Matrix 1:
Matrix[0][0] : 0
Matrix[0][1] : 0
Matrix[0][2] : 0
Matrix[1][0] : 0
Matrix[1][1] : -2
Matrix[1][2] : 0
Matrix[2][0] : 0
Matrix[2][1] : 0
Matrix[2][2] : 0
Enter rows and columns for Matrix 2: 3
3
Enter Matrix 2:
Matrix[0][0] : 11
Matrix[0][1] : 0
Matrix[0][2] : 0
Matrix[1][0] : 0
Matrix[1][1] : -11
Matrix[1][2] : 0
Matrix[2][0] : 0
Matrix[2][1] : -5
Matrix[2][2] : 0

Compact Matrix 1:
Row     Col     Value
3       3       1
1       1       -2

Compact Matrix 2:
Row     Col     Value
3       3       3
0       0       11
1       1       -11
2       1       -5

Addition of Sparse Matrices:
Row     Col     Value
3       3       3
0       0       11
1       1       -13
2       1       -5
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$*/

