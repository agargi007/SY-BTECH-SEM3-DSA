#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() 
{
    int val;
    if (rear == MAX - 1) 
    {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
    } 
    else 
    {
        if (front == -1) 
            front = 0;
            
        printf("Enter value to insert: ");
        scanf("%d", &val);
        
        rear++;               
        queue[rear] = val;    
        printf("\n%d inserted into the queue.\n", val);
    }
}

void dequeue() 
{
    if (front == -1 || front > rear) 
    {
        printf("\nQueue Underflow! The queue is empty.\n");
    } 
    else 
    {
        printf("\n%d deleted from the queue.\n", queue[front]);
        front++;  
        
        if (front > rear) 
        {
            front = -1;
            rear = -1;
        }
    }
}

void display() 
{
    int i;
    if (front == -1 || front > rear) 
    {
        printf("\nQueue is empty!\n");
    } 
    else 
    {
        printf("\nQueue elements: ");
        for (i = front; i <= rear; i++) 
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int choice;

    while (1) 
    {
       
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
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
                printf("\nProgram Ended.\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

/*
(base) vyaas192@VY030-06 ~ % gedit linear_queue.cpp
^C
(base) vyaas192@VY030-06 ~ % 
(base) vyaas192@VY030-06 ~ % gcc linear_queue.cpp -o lq
(base) vyaas192@VY030-06 ~ % ./lq
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 12

12 inserted into the queue.
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 65

65 inserted into the queue.
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 45

45 inserted into the queue.
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 3

Queue elements: 12 65 45 
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 2

12 deleted from the queue.
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 3

Queue elements: 65 45 
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display
4. Exit
Enter your choice: 
*/
