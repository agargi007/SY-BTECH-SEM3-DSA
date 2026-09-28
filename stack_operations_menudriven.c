#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char stack[100];
int top = -1;

float evalStack[100];
int evalTop = -1;

char strStack[100][100];
int strTop = -1;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;
    top = -1;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') postfix[j++] = stack[top--];
            if (top != -1) top--; 
        } else {
            while (top != -1 && prec(stack[top]) >= prec(c)) {
                if (c == '^' && stack[top] == '^') break;
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) postfix[j++] = stack[top--];
    postfix[j] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    int i = 0, j = 0;
    char c;
    top = -1;
    char temp[100];
    
    strcpy(temp, infix);
    reverse(temp);
    for (int k = 0; temp[k] != '\0'; k++) {
        if (temp[k] == '(') temp[k] = ')';
        else if (temp[k] == ')') temp[k] = '(';
    }

    while ((c = temp[i++]) != '\0') {
        if (isalnum(c)) {
            prefix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') prefix[j++] = stack[top--];
            if (top != -1) top--; 
        } else {
            while (top != -1 && prec(stack[top]) >= prec(c)) {
                if (prec(stack[top]) == prec(c) && c != '^') break;
                prefix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) prefix[j++] = stack[top--];
    prefix[j] = '\0';
    reverse(prefix);
}

void postfixEval(char* postfix) {
    evalTop = -1;
    float L, R, val;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char tkn = postfix[i];
        if (isalpha(tkn)) {
            printf("Enter value of %c: ", tkn);
            scanf("%f", &val);
            evalStack[++evalTop] = val;
        } else if (isdigit(tkn)) {
            evalStack[++evalTop] = tkn - '0';
        } else {
            R = evalStack[evalTop--];
            L = evalStack[evalTop--];
            switch(tkn) {
                case '+': evalStack[++evalTop] = L + R; break;
                case '-': evalStack[++evalTop] = L - R; break;
                case '*': evalStack[++evalTop] = L * R; break;
                case '/': evalStack[++evalTop] = L / R; break;
                case '^': evalStack[++evalTop] = pow(L, R); break;
            }
        }
    }
    printf("Result: %.2f\n", evalStack[evalTop]);
}

void prefixEval(char* prefix) {
    evalTop = -1;
    float L, R, val;
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char tkn = prefix[i];
        if (isalpha(tkn)) {
            printf("Enter value of %c: ", tkn);
            scanf("%f", &val);
            evalStack[++evalTop] = val;
        } else if (isdigit(tkn)) {
            evalStack[++evalTop] = tkn - '0';
        } else {
            L = evalStack[evalTop--];
            R = evalStack[evalTop--];
            switch(tkn) {
                case '+': evalStack[++evalTop] = L + R; break;
                case '-': evalStack[++evalTop] = L - R; break;
                case '*': evalStack[++evalTop] = L * R; break;
                case '/': evalStack[++evalTop] = L / R; break;
                case '^': evalStack[++evalTop] = pow(L, R); break;
            }
        }
    }
    printf("Result: %.2f\n", evalStack[evalTop]);
}

void prefixToPostfix(char* prefix, char* postfix) {
    strTop = -1;
    char op1[100], op2[100], temp[100];
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            temp[0] = c; temp[1] = '\0';
            strcpy(strStack[++strTop], temp);
        } else {
            strcpy(op1, strStack[strTop--]);
            strcpy(op2, strStack[strTop--]);
            strcpy(temp, op1);
            strcat(temp, op2);
            int len = strlen(temp);
            temp[len] = c; temp[len + 1] = '\0';
            strcpy(strStack[++strTop], temp);
        }
    }
    strcpy(postfix, strStack[strTop--]);
}

void postfixToPrefix(char* postfix, char* prefix) {
    strTop = -1;
    char op1[100], op2[100], temp[100];
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            temp[0] = c; temp[1] = '\0';
            strcpy(strStack[++strTop], temp);
        } else {
            strcpy(op2, strStack[strTop--]);
            strcpy(op1, strStack[strTop--]);
            temp[0] = c; temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);
            strcpy(strStack[++strTop], temp);
        }
    }
    strcpy(prefix, strStack[strTop--]);
}

void prefixToInfix(char* prefix, char* infix) {
    strTop = -1;
    char op1[100], op2[100], temp[100];
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            temp[0] = c; temp[1] = '\0';
            strcpy(strStack[++strTop], temp);
        } else {
            strcpy(op1, strStack[strTop--]);
            strcpy(op2, strStack[strTop--]);
            strcpy(temp, "(");
            strcat(temp, op1);
            int len = strlen(temp);
            temp[len] = c; temp[len + 1] = '\0';
            strcat(temp, op2);
            strcat(temp, ")");
            strcpy(strStack[++strTop], temp);
        }
    }
    strcpy(infix, strStack[strTop--]);
}

void postfixToInfix(char* postfix, char* infix) {
    strTop = -1;
    char op1[100], op2[100], temp[100];
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            temp[0] = c; temp[1] = '\0';
            strcpy(strStack[++strTop], temp);
        } else {
            strcpy(op2, strStack[strTop--]);
            strcpy(op1, strStack[strTop--]);
            strcpy(temp, "(");
            strcat(temp, op1);
            int len = strlen(temp);
            temp[len] = c; temp[len + 1] = '\0';
            strcat(temp, op2);
            strcat(temp, ")");
            strcpy(strStack[++strTop], temp);
        }
    }
    strcpy(infix, strStack[strTop--]);
}

int main() {
    int choice;
    char exp[100], res[100];

    while (1) {
        printf("\n--- Expression Converter & Evaluator ---\n");
        printf("1. Infix to Postfix\n2. Infix to Prefix\n");
        printf("3. Postfix Evaluation\n4. Prefix Evaluation\n");
        printf("5. Prefix to Postfix\n6. Postfix to Prefix\n");
        printf("7. Prefix to Infix\n8. Postfix to Infix\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 9) break;

        printf("Enter expression: ");
        scanf("%s", exp);

        switch(choice) {
            case 1:
                infixToPostfix(exp, res);
                printf("Postfix: %s\n", res);
                break;
            case 2:
                infixToPrefix(exp, res);
                printf("Prefix: %s\n", res);
                break;
            case 3:
                postfixEval(exp);
                break;
            case 4:
                prefixEval(exp);
                break;
            case 5:
                prefixToPostfix(exp, res);
                printf("Postfix: %s\n", res);
                break;
            case 6:
                postfixToPrefix(exp, res);
                printf("Prefix: %s\n", res);
                break;
            case 7:
                prefixToInfix(exp, res);
                printf("Infix: %s\n", res);
                break;
            case 8:
                postfixToInfix(exp, res);
                printf("Infix: %s\n", res);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

/*
(base) vyaas128@VY030-26 ~ % gedit stack_operations_menudriven.c       
^C
(base) vyaas128@VY030-26 ~ % gcc stack_operations_menudriven.c -o exp67
(base) vyaas128@VY030-26 ~ % ./exp67                                   

--- Expression Converter & Evaluator ---
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Prefix to Postfix
6. Postfix to Prefix
7. Prefix to Infix
8. Postfix to Infix
9. Exit
Enter choice: 1
Enter expression: a+b-c
Postfix: ab+c-

--- Expression Converter & Evaluator ---
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Prefix to Postfix
6. Postfix to Prefix
7. Prefix to Infix
8. Postfix to Infix
9. Exit
Enter choice: 2
Enter expression: a*b+c
Prefix: +*abc

--- Expression Converter & Evaluator ---
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Prefix to Postfix
6. Postfix to Prefix
7. Prefix to Infix
8. Postfix to Infix
9. Exit
Enter choice: 3
Enter expression: ab+c-
Enter value of a: 2
Enter value of b: 6
Enter value of c: 9
Result: -1.00

--- Expression Converter & Evaluator ---
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Prefix to Postfix
6. Postfix to Prefix
7. Prefix to Infix
8. Postfix to Infix
9. Exit
Enter choice: 4
Enter expression: +*abc
Enter value of c: 4
Enter value of b: 9
Enter value of a: 11
Result: 103.00

--- Expression Converter & Evaluator ---
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Prefix to Postfix
6. Postfix to Prefix
7. Prefix to Infix
8. Postfix to Infix
9. Exit
Enter choice: 5
Enter expression: -*d/abc
Postfix: dab/*c-

--- Expression Converter & Evaluator ---
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Prefix to Postfix
6. Postfix to Prefix
7. Prefix to Infix
8. Postfix to Infix
9. Exit
Enter choice: 6
Enter expression: dab/*c-
Prefix: -*d/abc

--- Expression Converter & Evaluator ---
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Prefix to Postfix
6. Postfix to Prefix
7. Prefix to Infix
8. Postfix to Infix
9. Exit
Enter choice: 7
Enter expression: -*+abcd
Infix: (((a+b)*c)-d)

--- Expression Converter & Evaluator ---
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Prefix to Postfix
6. Postfix to Prefix
7. Prefix to Infix
8. Postfix to Infix
9. Exit
Enter choice: 8
Enter expression: abc/-de*+
Infix: ((a-(b/c))+(d*e))

--- Expression Converter & Evaluator ---
1. Infix to Postfix
2. Infix to Prefix
3. Postfix Evaluation
4. Prefix Evaluation
5. Prefix to Postfix
6. Postfix to Prefix
7. Prefix to Infix
8. Postfix to Infix
9. Exit
Enter choice: 9
(base) vyaas128@VY030-26 ~ % 

*/
