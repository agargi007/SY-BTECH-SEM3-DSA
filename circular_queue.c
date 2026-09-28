#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1, size;

void enqueue(int val) {
    if ((rear + 1) % size == front) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    queue[rear] = val;
    printf("Inserted: %d\n", val);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Reset when the last element is deleted
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i != rear; i = (i + 1) % size) {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]); // Print the last element
}

int main() {
    int choice, val;
    
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    
    queue = (int *)malloc(size * sizeof(int)); // Dynamically allocate memory

    while (1) {
        printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                free(queue); // Free memory before exiting
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

/*
(base) vyaas128@VY030-26 ~ % gedit circular_queue.c
^C
(base) vyaas128@VY030-26 ~ % gcc circular_queue.c -o circular
(base) vyaas128@VY030-26 ~ % ./circular
Enter the size of the queue: 5

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 1
Enter value: 11
Inserted: 11

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 1
Enter value: 54
Inserted: 54

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 2
Deleted: 11

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 1
Enter value: 87
Inserted: 87

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 1
Enter value: 34
Inserted: 34

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 1
Enter value: 24
Inserted: 24

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 1
Enter value: 9
Inserted: 9

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 1
Enter value: 32
Queue is Full!

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 2
Deleted: 54

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 3
Queue elements: 87 34 24 9

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 1
Enter value: 54
Inserted: 54

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 3
Queue elements: 87 34 24 9 54

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 2
Deleted: 87

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 3
Queue elements: 34 24 9 54

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: 4
(base) vyaas128@VY030-26 ~ % 

*/

