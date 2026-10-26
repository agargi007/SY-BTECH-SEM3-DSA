
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

void shell_sort(student s[10], int n)
{
    int gap, i, j;
    student temp;

    for(gap=n/2;gap>0;gap=gap/2)
    {
        for(i=gap;i<n;i++)
        {
            temp=s[i];
            j=i;

            while(j>=gap && s[j-gap].roll>temp.roll)
            {
                s[j]=s[j-gap];
                j=j-gap;
            }

            s[j]=temp;
        }
    }
}

void selection_sort(student s[10], int n)
{
    int i, j, min;
    student temp;

    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
        {
            if(s[j].roll<s[min].roll)
                min=j;
        }

        if(min!=i)
        {
            temp=s[i];
            s[i]=s[min];
            s[min]=temp;
        }
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
        printf("\n1. Display Students\n");
        printf("2. Linear Search\n");
        printf("3. Bubble Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Binary Search\n");
        printf("6. Shell Sort\n");
        printf("7. Selection Sort\n");
        printf("8. Exit\n");

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
                shell_sort(s,n);
                printf("\nStudents Sorted Using Shell Sort\n");
                display(s,n);
                break;

            case 7:
                selection_sort(s,n);
                printf("\nStudents Sorted Using Selection Sort\n");
                display(s,n);
                break;

            case 8:
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit dsa_search_sort.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc dsa_search_sort.c -o search
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./search
Enter Number of Students: 5

Student 1
Enter Name: leanor
Enter Roll Number: 24

Student 2
Enter Name: sammy
Enter Roll Number: 11

Student 3
Enter Name: hannah
Enter Roll Number: 13

Student 4
Enter Name: ken
Enter Roll Number: 31

Student 5
Enter Name: sheba
Enter Roll Number: 9

1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Shell Sort
7. Selection Sort
8. Exit
Enter Choice: 1

Student Details:

Name : leanor
Roll : 24

Name : sammy
Roll : 11

Name : hannah
Roll : 13

Name : ken
Roll : 31

Name : sheba
Roll : 9

1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Shell Sort
7. Selection Sort
8. Exit
Enter Choice: 2
Enter Roll Number to Search: 11

Student Found
Name : sammy
Roll : 11

1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Shell Sort
7. Selection Sort
8. Exit
Enter Choice: 4

Students Sorted Using Insertion Sort

Student Details:

Name : sheba
Roll : 9

Name : sammy
Roll : 11

Name : hannah
Roll : 13

Name : leanor
Roll : 24

Name : ken
Roll : 31

1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Shell Sort
7. Selection Sort
8. Exit
Enter Choice: 5
Enter Roll Number to Search: 3

Student Not Found

1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Shell Sort
7. Selection Sort
8. Exit
Enter Choice: 6

Students Sorted Using Shell Sort

Student Details:

Name : sheba
Roll : 9

Name : sammy
Roll : 11

Name : hannah
Roll : 13

Name : leanor
Roll : 24

Name : ken
Roll : 31

1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Shell Sort
7. Selection Sort
8. Exit
Enter Choice: 7

Students Sorted Using Selection Sort

Student Details:

Name : sheba
Roll : 9

Name : sammy
Roll : 11

Name : hannah
Roll : 13

Name : leanor
Roll : 24

Name : ken
Roll : 31

1. Display Students
2. Linear Search
3. Bubble Sort
4. Insertion Sort
5. Binary Search
6. Shell Sort
7. Selection Sort
8. Exit
Enter Choice: 8
Program Ended.
*/
