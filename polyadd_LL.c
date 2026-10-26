#include <stdio.h>
#include <stdlib.h>

// 1. Structure for a Polynomial Node
struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

// 2. Helper to create a new node
struct Node* createNode(int c, int e) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// 3. Insert term at the end of the Circular Linked List
void insertTerm(struct Node **head, int c, int e) {
    if (c == 0) return; // Do not store terms with coefficient zero

    struct Node *newNode = createNode(c, e);
    
    if (*head == NULL) { // If list is empty
        *head = newNode;
        newNode->next = *head; // Point to itself to make it circular
        return;
    }
    
    struct Node *temp = *head;
    // Traverse until the last node
    while (temp->next != *head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = *head; // Last node points back to head
}

// 4. Display the polynomial
void displayPoly(struct Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    
    struct Node *temp = head;
    do {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != head) {
            printf(" + "); // Print + between terms
        }
    } while (temp != head); // Stop when we return to the start
    printf("\n");
}

// 5. Add two polynomials
struct Node* addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    
    if (poly1 == NULL) return poly2;
    if (poly2 == NULL) return poly1;

    struct Node *p1 = poly1;
    struct Node *p2 = poly2;
    
    // We use a do-while loop because it's a circular list
    do {
        if (p1->exp == p2->exp) {
            insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } 
        else if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } 
        else { // p2->exp > p1->exp
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        
        // Stop the loop if we have completed a full circle for BOTH lists.
        // (A fully robust version handles different length polynomials with extra loops, 
        // but this simplified version assumes we break when we hit the head again).
    } while (p1 != poly1 && p2 != poly2); 

    // Handle leftover terms for poly1
    while(p1 != poly1) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    // Handle leftover terms for poly2
     while(p2 != poly2) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// 6. Main function to test
int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *polySum = NULL;

    // Creating Poly 1: 6x^4 + 3x^2 + 2x^1 + 1x^0
    insertTerm(&poly1, 6, 4);
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);
    insertTerm(&poly1, 1, 0);

    // Creating Poly 2: 4x^3 + -3x^2 + 5x^0
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, -3, 2);
    insertTerm(&poly2, 5, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    polySum = addPolynomials(poly1, poly2);

    printf("Sum Result:   ");
    displayPoly(polySum);

    return 0;
}

/*

gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit polyadd_LL.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc polyadd_LL.c -o polyadd
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./polyadd
Polynomial 1: 6x^4 + 3x^2 + 2x^1 + 1x^0
Polynomial 2: 4x^3 + -3x^2 + 5x^0
Sum Result:   6x^4 + 3x^2 + 2x^1 + 1x^0
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$

*/
