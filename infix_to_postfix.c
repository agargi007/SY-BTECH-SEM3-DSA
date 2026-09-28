#include <stdio.h>
#include <ctype.h>
#include <math.h>

char stack[100];
int top = -1;

float evalStack[100];
int evalTop = -1;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1) top--; 
        } else {
            while (top != -1 && prec(stack[top]) >= prec(c)) {
                if (c == '^' && stack[top] == '^') break;
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

void postfixEval(char* postfix) {
    int i = 0;
    float L, R, result, val;
    char tkn;
    
    // Note: use single quotes '\0' for characters, not "\0"
    while (postfix[i] != '\0') {
        tkn = postfix[i];
        
        if (isalpha(tkn)) {
            printf("Enter the value of %c: ", tkn);
            scanf("%f", &val);
            evalStack[++evalTop] = val;
        } 
        else if (isdigit(tkn)) {
            evalStack[++evalTop] = tkn - '0'; // Convert char digit to integer value
        } 
        else {
            R = evalStack[evalTop--];
            L = evalStack[evalTop--];
            
            switch(tkn) {
                case '+': result = L + R; break;
                case '-': result = L - R; break;
                case '*': result = L * R; break;
                case '/': result = L / R; break;
                case '^': result = pow(L, R); break;
            }
            evalStack[++evalTop] = result;
        }
        i++;
    }
    printf("Result of evaluation: %.2f\n", evalStack[evalTop]);
}

int main() {
    char infix[100], postfix[100];
    
    printf("Enter infix: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    
    postfixEval(postfix);
    
    return 0;
}


/*
(base) vyaas128@VY030-26 ~ % gedit infix_to_postfix.c
^C
(base) vyaas128@VY030-26 ~ % gcc infix_to_postfix.c -o postfix
(base) vyaas128@VY030-26 ~ % ./postfix
Enter infix: a+b(c/d*e)-f+g
Postfix: abcd/e*+f-g+
Enter the value of a: 11
Enter the value of b: 4
Enter the value of c: 9
Enter the value of d: 2
Enter the value of e: 4
Enter the value of f: 13
Enter the value of g: 2
Result of evaluation: 11.00
(base) vyaas128@VY030-26 ~ % 

*/
