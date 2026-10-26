#include <stdio.h>

struct poly
{
    int coeff;
    int exp;
};

void display(struct poly p[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%dx^%d", p[i].coeff, p[i].exp);

        if(i < n - 1)
            printf(" + ");
    }
    printf("\n");
}

int main()
{
    struct poly p1[10], p2[10], p3[20];
    int n1, n2, i, j, k = 0;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    for(i = 0; i < n1; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &p1[i].coeff, &p1[i].exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    for(i = 0; i < n2; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &p2[i].coeff, &p2[i].exp);
    }

    printf("\nFirst polynomial: ");
    display(p1, n1);

    printf("Second polynomial: ");
    display(p2, n2);

    i = 0;
    j = 0;

    while(i < n1 && j < n2)
    {
        if(p1[i].exp == p2[j].exp)
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(p1[i].exp > p2[j].exp)
            p3[k++] = p1[i++];
        else
            p3[k++] = p2[j++];
    }

    while(i < n1)
        p3[k++] = p1[i++];

    while(j < n2)
        p3[k++] = p2[j++];

    printf("Sum of polynomials: ");
    display(p3, k);

    return 0;
}

/*

gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit poly_addition_using_array.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc  poly_addition_using_array.c -o array_poly
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./array_poly
Enter number of terms in first polynomial: 3
Enter coefficient and exponent: 2
3
Enter coefficient and exponent: 4
2
Enter coefficient and exponent: 6
0
Enter number of terms in second polynomial: 2
Enter coefficient and exponent: 6
3
Enter coefficient and exponent: 8
0

First polynomial: 2x^3 + 4x^2 + 6x^0
Second polynomial: 6x^3 + 8x^0
Sum of polynomials: 8x^3 + 4x^2 + 14x^0

*/
