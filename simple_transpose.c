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

void simple_transpose(int a[20][3], int b[20][3])
{
    int m = a[0][0];
    int n = a[0][1];
    int t = a[0][2];

    b[0][0] = n;
    b[0][1] = m;
    b[0][2] = t;

    if(t > 0)
    {
        int q = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= t; j++)
            {
                if(a[j][1] == i)
                {
                    b[q][0] = a[j][1];
                    b[q][1] = a[j][0];
                    b[q][2] = a[j][2];
                    q++;
                }
            }
        }
    }
}

int main()
{
    int a[10][10];
    int compact[20][3];
    int transpose[20][3];
    int r, c;

    printf("Enter rows and columns of the sparse matrix: ");
    scanf("%d%d", &r, &c);

    printf("Enter the sparse matrix:\n");
    accept_matrix(r, c, a);

    compact_matrix(r, c, a, compact);

    printf("\nCompact Matrix:");
    display_compact(compact);

    simple_transpose(compact, transpose);

    printf("\nSimple Transpose of the Compact Matrix:");
    display_compact(transpose);

    return 0;
}
