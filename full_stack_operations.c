
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

char st[MAX][MAX];
int t = -1;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void reverse(char s[]) {
    int i, j = strlen(s) - 1;
    for (i = 0; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// 1. Infix to Postfix
void infixToPostfix(char in[], char out[]) {
    int i, j = 0;
    top = -1;

    for (i = 0; in[i]; i++) {
        char c = in[i];

        if (isalnum(c)) out[j++] = c;
        else if (c == '(') stack[++top] = c;
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(')
                out[j++] = stack[top--];
            if (top >= 0) top--;
        } else {
            while (top >= 0 && stack[top] != '(' &&
                  (prec(stack[top]) > prec(c) ||
                  (prec(stack[top]) == prec(c) && c != '^')))
                out[j++] = stack[top--];
            stack[++top] = c;
        }
    }

    while (top >= 0) out[j++] = stack[top--];
    out[j] = '\0';
}

// 2. Infix to Prefix
void infixToPrefix(char in[], char out[]) {
    char temp[MAX];
    strcpy(temp, in);
    reverse(temp);

    for (int i = 0; temp[i]; i++) {
        if (temp[i] == '(') temp[i] = ')';
        else if (temp[i] == ')') temp[i] = '(';
    }

    top = -1;
    int j = 0;

    for (int i = 0; temp[i]; i++) {
        char c = temp[i];

        if (isalnum(c)) out[j++] = c;
        else if (c == '(') stack[++top] = c;
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(')
                out[j++] = stack[top--];
            if (top >= 0) top--;
        } else {
            while (top >= 0 && stack[top] != '(' &&
                  (prec(stack[top]) > prec(c) ||
                  (prec(stack[top]) == prec(c) && c == '^')))
                out[j++] = stack[top--];
            stack[++top] = c;
        }
    }

    while (top >= 0) out[j++] = stack[top--];
    out[j] = '\0';
    reverse(out);
}

// 3. Postfix Evaluation
void postfixEval(char exp[]) {
    float s[MAX], a, b;
    int t = -1;

    for (int i = 0; exp[i]; i++) {
        char c = exp[i];

        if (isdigit(c)) s[++t] = c - '0';
        else if (isalpha(c)) {
            printf("Enter value of %c: ", c);
            scanf("%f", &s[++t]);
        } else {
            b = s[t--];
            a = s[t--];

            switch (c) {
                case '+': s[++t] = a + b; break;
                case '-': s[++t] = a - b; break;
                case '*': s[++t] = a * b; break;
                case '/': s[++t] = a / b; break;
                case '^': s[++t] = pow(a, b); break;
            }
        }
    }

    printf("Result: %.2f\n", s[t]);
}

// 4. Prefix Evaluation
void prefixEval(char exp[]) {
    float s[MAX], a, b;
    int t = -1;

    for (int i = strlen(exp) - 1; i >= 0; i--) {
        char c = exp[i];

        if (isdigit(c)) s[++t] = c - '0';
        else if (isalpha(c)) {
            printf("Enter value of %c: ", c);
            scanf("%f", &s[++t]);
        } else {
            a = s[t--];
            b = s[t--];

            switch (c) {
                case '+': s[++t] = a + b; break;
                case '-': s[++t] = a - b; break;
                case '*': s[++t] = a * b; break;
                case '/': s[++t] = a / b; break;
                case '^': s[++t] = pow(a, b); break;
            }
        }
    }

    printf("Result: %.2f\n", s[t]);
}

// 5. Prefix to Postfix
void prefixToPostfix(char in[], char out[]) {
    t = -1;

    for (int i = strlen(in) - 1; i >= 0; i--) {
        char c = in[i];
        char a[MAX], b[MAX];

        if (isalnum(c)) {
            a[0] = c; a[1] = '\0';
            strcpy(st[++t], a);
        } else {
            strcpy(a, st[t--]);
            strcpy(b, st[t--]);
            strcpy(a + strlen(a), b);
            int n = strlen(a);
            a[n] = c; a[n+1] = '\0';
            strcpy(st[++t], a);
        }
    }

    strcpy(out, st[t]);
}

// 6. Postfix to Prefix
void postfixToPrefix(char in[], char out[]) {
    t = -1;

    for (int i = 0; in[i]; i++) {
        char c = in[i];
        char a[MAX], b[MAX];

        if (isalnum(c)) {
            a[0] = c; a[1] = '\0';
            strcpy(st[++t], a);
        } else {
            strcpy(b, st[t--]);
            strcpy(a, st[t--]);

            char temp[MAX] = {c};
            strcat(temp, a);
            strcat(temp, b);
            strcpy(st[++t], temp);
        }
    }

    strcpy(out, st[t]);
}

// 7. Prefix to Infix
void prefixToInfix(char in[], char out[]) {
    t = -1;

    for (int i = strlen(in) - 1; i >= 0; i--) {
        char c = in[i];
        char a[MAX], b[MAX], temp[MAX];

        if (isalnum(c)) {
            a[0] = c; a[1] = '\0';
            strcpy(st[++t], a);
        } else {
            strcpy(a, st[t--]);
            strcpy(b, st[t--]);

            strcpy(temp, "(");
            strcat(temp, a);
            int n = strlen(temp);
            temp[n] = c; temp[n+1] = '\0';
            strcat(temp, b);
            strcat(temp, ")");
            strcpy(st[++t], temp);
        }
    }

    strcpy(out, st[t]);
}

// 8. Postfix to Infix
void postfixToInfix(char in[], char out[]) {
    t = -1;

    for (int i = 0; in[i]; i++) {
        char c = in[i];
        char a[MAX], b[MAX], temp[MAX];

        if (isalnum(c)) {
            a[0] = c; a[1] = '\0';
            strcpy(st[++t], a);
        } else {
            strcpy(b, st[t--]);
            strcpy(a, st[t--]);

            strcpy(temp, "(");
            strcat(temp, a);
            int n = strlen(temp);
            temp[n] = c; temp[n+1] = '\0';
            strcat(temp, b);
            strcat(temp, ")");
            strcpy(st[++t], temp);
        }
    }

    strcpy(out, st[t]);
}

// Main Menu
int main() {
    int ch;
    char exp[MAX], res[MAX];

    while (1) {
        printf("\n1.Infix to Postfix\n2.Infix to Prefix\n");
        printf("3.Postfix Evaluation\n4.Prefix Evaluation\n");
        printf("5.Prefix to Postfix\n6.Postfix to Prefix\n");
        printf("7.Prefix to Infix\n8.Postfix to Infix\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 9) break;
        if (ch < 1 || ch > 8) {
            printf("Invalid choice!\n");
            continue;
        }

        printf("Enter expression: ");
        scanf("%99s", exp);

        switch (ch) {
            case 1:
                infixToPostfix(exp, res);
                printf("Postfix: %s\n", res);
                break;
            case 2:
                infixToPrefix(exp, res);
                printf("Prefix: %s\n", res);
                break;
            case 3: postfixEval(exp); break;
            case 4: prefixEval(exp); break;
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
        }
    }

    return 0;
}



/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc full_stack_operations.c -o stacks -lm
./stacks

1.Infix to Postfix
2.Infix to Prefix
3.Postfix Evaluation
4.Prefix Evaluation
5.Prefix to Postfix
6.Postfix to Prefix
7.Prefix to Infix
8.Postfix to Infix
9.Exit
Enter choice: 1
Enter expression: a*(b+c)/(d-e+f)
Postfix: abc+*de-f+/

1.Infix to Postfix
2.Infix to Prefix
3.Postfix Evaluation
4.Prefix Evaluation
5.Prefix to Postfix
6.Postfix to Prefix
7.Prefix to Infix
8.Postfix to Infix
9.Exit
Enter choice: 2
Enter expression: a+b-c
Prefix: -+abc

1.Infix to Postfix
2.Infix to Prefix
3.Postfix Evaluation
4.Prefix Evaluation
5.Prefix to Postfix
6.Postfix to Prefix
7.Prefix to Infix
8.Postfix to Infix
9.Exit
Enter choice: 3
Enter expression: a-b+c/d
Enter value of a: 1
Enter value of b: 4
Enter value of c: 3
Enter value of d: 5
Result: 5.00

1.Infix to Postfix
2.Infix to Prefix
3.Postfix Evaluation
4.Prefix Evaluation
5.Prefix to Postfix
6.Postfix to Prefix
7.Prefix to Infix
8.Postfix to Infix
9.Exit
Enter choice: 4
Enter expression: a*b-c
Enter value of c: 11
Enter value of b: 3
Enter value of a: 9
Result: 9.00

1.Infix to Postfix
2.Infix to Prefix
3.Postfix Evaluation
4.Prefix Evaluation
5.Prefix to Postfix
6.Postfix to Prefix
7.Prefix to Infix
8.Postfix to Infix
9.Exit
Enter choice: 5
Enter expression: */abc
Postfix: ab/c*

1.Infix to Postfix
2.Infix to Prefix
3.Postfix Evaluation
4.Prefix Evaluation
5.Prefix to Postfix
6.Postfix to Prefix
7.Prefix to Infix
8.Postfix to Infix
9.Exit
Enter choice: 6
Enter expression: abc/*
Prefix: *a/bc

1.Infix to Postfix
2.Infix to Prefix
3.Postfix Evaluation
4.Prefix Evaluation
5.Prefix to Postfix
6.Postfix to Prefix
7.Prefix to Infix
8.Postfix to Infix
9.Exit
Enter choice: 7
Enter expression: -*abc
Infix: ((a*b)-c)

1.Infix to Postfix
2.Infix to Prefix
3.Postfix Evaluation
4.Prefix Evaluation
5.Prefix to Postfix
6.Postfix to Prefix
7.Prefix to Infix
8.Postfix to Infix
9.Exit
Enter choice: 8
Enter expression: abc*d/-
Infix: (a-((b*c)/d))

1.Infix to Postfix
2.Infix to Prefix
3.Postfix Evaluation
4.Prefix Evaluation
5.Prefix to Postfix
6.Postfix to Prefix
7.Prefix to Infix
8.Postfix to Infix
9.Exit
Enter choice: 9
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$
*/

