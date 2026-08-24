#include <stdio.h>

#define MAX 5

struct Job {
    int id;
    char title[50];
};

struct Job queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Queue is full.\n");
        return;
    }

    struct Job job;

    printf("Enter Job ID: ");
    scanf("%d", &job.id);

    printf("Enter Document Title: ");
    scanf(" %[^\n]", job.title);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = job;

    printf("Print job added successfully.\n");
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No print jobs available.\n");
        return;
    }

    printf("Processing Job ID: %d, Document: %s\n",
           queue[front].id, queue[front].title);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void display() {
    if (front == -1) {
        printf("No Pending Print Jobs.\n");
        return;
    }

    printf("\nPending Print Jobs:\n");

    for (int i = front; i <= rear; i++)
        printf("Job ID: %d | Document: %s\n",
               queue[i].id, queue[i].title);
}

int main() {
    int choice;

    do {
        printf("\nPrinter Queue Manager \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program terminated successfully.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}

/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit linear_queue.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc linear_queue.c -o lq
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./lq

Printer Queue Manager
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter Job ID: 111
Enter Document Title: hhsj
Print job added successfully.

Printer Queue Manager
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter Job ID: 222
Enter Document Title: sjklw
Print job added successfully.

Printer Queue Manager
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3

Pending Print Jobs:
Job ID: 111 | Document: hhsj
Job ID: 222 | Document: sjklw

Printer Queue Manager
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 2
Processing Job ID: 111, Document: hhsj

Printer Queue Manager
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3

Pending Print Jobs:
Job ID: 222 | Document: sjklw

Printer Queue Manager
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 4
Program terminated successfully.
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$

*/
