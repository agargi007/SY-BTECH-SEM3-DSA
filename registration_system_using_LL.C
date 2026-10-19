#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int ID;
    char Name[50];
    struct Node* next;
};

struct Node* head = NULL;

struct Node* newNode(int id, const char* name) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->ID = id;
    strcpy(temp->Name, name);
    temp->next = NULL;
    return temp;
}

void insertAtBeginning(int id, const char* name) {
    struct Node* temp = newNode(id, name);
    temp->next = head;
    head = temp;
}

void insertAtEnd(int id, const char* name) {
    struct Node* temp = newNode(id, name);
    if (head == NULL) {
        head = temp;
        return;
    }
    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

void insertInMiddle(int id, const char* name, int pos) {
    if (pos <= 1 || head == NULL) {
        insertAtBeginning(id, name);
        return;
    }
    struct Node* temp = newNode(id, name);
    struct Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != NULL; i++) {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void deleteAtBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

void deleteInMiddle(int pos) {
    if (head == NULL) return;
    if (pos <= 1) {
        deleteAtBeginning();
        return;
    }
    struct Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != NULL; i++) {
        curr = curr->next;
    }
    if (curr->next == NULL) return;
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

int display() {
    int count = 0;
    struct Node* curr = head;
    printf("\n");
    while (curr != NULL) {
        printf("ID: %d, Name: %s\n", curr->ID, curr->Name);
        count++;
        curr = curr->next;
    }
    printf("Total Nodes: %d\n", count);
    return count;
}

void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    int choice, id, pos;
    char name[50];

    while (1) {
        printf("\n1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID and Name: ");
                scanf("%d %[^\n]s", &id, name);
                insertAtBeginning(id, name);
                break;
            case 2:
                printf("Enter ID and Name: ");
                scanf("%d %[^\n]s", &id, name);
                insertAtEnd(id, name);
                break;
            case 3:
                printf("Enter Position, ID and Name: ");
                scanf("%d %d %[^\n]s", &pos, &id, name);
                insertInMiddle(id, name, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter Position: ");
                scanf("%d", &pos);
                deleteInMiddle(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                reverseList();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

/*
(base) vyaas135@VY030-38 ~ % ./SLL

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 1
Enter ID and Name: 1 LEANOR           

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 2
Enter ID and Name: 5 SENNA

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 3
Enter Position, ID and Name: 2
2
LENOAE

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 1 
Enter ID and Name: 3 HAMN

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 7

ID: 3, Name: HAMN
ID: 1, Name: LEANOR
ID: 2, Name: LENOAE
ID: 5, Name: SENNA
Total Nodes: 4

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 4

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 7

ID: 1, Name: LEANOR
ID: 2, Name: LENOAE
ID: 5, Name: SENNA
Total Nodes: 3

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 5

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 7

ID: 1, Name: LEANOR
ID: 2, Name: LENOAE
Total Nodes: 2

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 8

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 7

ID: 2, Name: LENOAE
ID: 1, Name: LEANOR
Total Nodes: 2

1.Insert Begin 2.Insert End 3.Insert Middle 4.Delete Begin 5.Delete End 6.Delete Middle 7.Display 8.Reverse 9.Exit
Choice: 9
(base) vyaas135@VY030-38 ~ % 


*/
