#include <stdio.h>

typedef struct student
{
    char name[10];
    int roll;
} student;

void accept(student s[10], int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("\nStudent %d\n",i+1);
        printf("Enter Name: ");
        scanf("%s",s[i].name);

        printf("Enter Roll Number: ");
        scanf("%d",&s[i].roll);
    }
}

void display(student s[10], int n)
{
    int i;

    printf("\nStudent Details:\n");

    for(i=0;i<n;i++)
    {
        printf("\nName : %s",s[i].name);
        printf("\nRoll : %d\n",s[i].roll);
    }
}

void linear_search(student s[10], int n, int target)
{
    int i, found=0;

    for(i=0;i<n;i++)
    {
        if(s[i].roll==target)
        {
            printf("\nStudent Found");
            printf("\nName : %s",s[i].name);
            printf("\nRoll : %d\n",s[i].roll);
            found=1;
            break;
        }
    }

    if(found==0)
        printf("\nStudent Not Found\n");
}

void bubble_sort(student s[10], int n)
{
    int i, j;
    student temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].roll>s[j+1].roll)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}

void insertion_sort(student s[10], int n)
{
    int i, j;
    student key;

    for(i=1;i<n;i++)
    {
        key=s[i];
        j=i-1;

        while(j>=0 && s[j].roll>key.roll)
        {
            s[j+1]=s[j];
            j--;
        }

        s[j+1]=key;
    }
}

void binary_search(student s[10], int n, int target)
{
    int low=0, high=n-1, mid;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(s[mid].roll==target)
        {
            printf("\nStudent Found");
            printf("\nName : %s",s[mid].name);
            printf("\nRoll : %d\n",s[mid].roll);
            return;
        }

        if(s[mid].roll<target)
            low=mid+1;
        else
            high=mid-1;
    }

    printf("\nStudent Not Found\n");
}

int main()
{
    student s[10];
    int n, choice, target;

    printf("Enter Number of Students: ");
    scanf("%d",&n);

    accept(s,n);

    while(1)
    {
   
        printf("1. Display Students\n");
        printf("2. Linear Search\n");
        printf("3. Bubble Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Binary Search\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                display(s,n);
                break;

            case 2:
                printf("Enter Roll Number to Search: ");
                scanf("%d",&target);
                linear_search(s,n,target);
                break;

            case 3:
                bubble_sort(s,n);
                printf("\nStudents Sorted Using Bubble Sort\n");
                display(s,n);
                break;

            case 4:
                insertion_sort(s,n);
                printf("\nStudents Sorted Using Insertion Sort\n");
                display(s,n);
                break;

            case 5:
                bubble_sort(s,n);
                printf("Enter Roll Number to Search: ");
                scanf("%d",&target);
                binary_search(s,n,target);
                break;

            case 6:
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit dsa_experiment3.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc dsa_experiment3.c -o exp3
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./exp3
Enter Number of Students: 2

Student 1
Enter Name: jjee
Enter Roll Number: 43

Student 2
Enter Name: jjenekwkl
Enter Roll Number: 12
1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Exit
Enter Choice: 1

Student Details:

Name : jjee
Roll : 43

Name : jjenekwkl
Roll : 12
1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Exit
Enter Choice: 2
Enter Roll Number to Search: 42

Student Not Found
1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Exit
Enter Choice: 3

Students Sorted Using Bubble Sort

Student Details:

Name : jjenekwkl
Roll : 12

Name : jjee
Roll : 43
1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Exit
Enter Choice: 4

Students Sorted Using Insertion Sort

Student Details:

Name : jjenekwkl
Roll : 12

Name : jjee
Roll : 43
1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Exit
Enter Choice: 5
Enter Roll Number to Search: 12

Student Found
Name : jjenekwkl
Roll : 12
1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Exit
Enter Choice: 6
Program Ended.
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$

*/
