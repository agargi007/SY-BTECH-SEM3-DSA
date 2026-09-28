#include <stdio.h>
#include <string.h>
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

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    int i = 0, j = 0;
    char c;
    
    reverse(infix);
    for (int k = 0; infix[k] != '\0'; k++) {
        if (infix[k] == '(') infix[k] = ')';
        else if (infix[k] == ')') infix[k] = '(';
    }

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            prefix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                prefix[j++] = stack[top--];
            }
            if (top != -1) top--; 
        } else {
            while (top != -1 && prec(stack[top]) >= prec(c)) {
                if (prec(stack[top]) == prec(c) && c != '^') break;
                prefix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        prefix[j++] = stack[top--];
    }
    prefix[j] = '\0';
    
    reverse(prefix);
}

void prefixEval(char* prefix) {
    int i = strlen(prefix) - 1;
    float L, R, result, val;
    char tkn;
    
    while (i >= 0) {
        tkn = prefix[i];
        
        if (isalpha(tkn)) {
            printf("Enter the value of %c: ", tkn);
            scanf("%f", &val);
            evalStack[++evalTop] = val;
        } 
        else if (isdigit(tkn)) {
            evalStack[++evalTop] = tkn - '0';
        } 
        else {
            L = evalStack[evalTop--];
            R = evalStack[evalTop--];
            
            switch(tkn) {
                case '+': result = L + R; break;
                case '-': result = L - R; break;
                case '*': result = L * R; break;
                case '/': result = L / R; break;
                case '^': result = pow(L, R); break;
            }
            evalStack[++evalTop] = result;
        }
        i--;
    }
    printf("Result of evaluation: %.2f\n", evalStack[evalTop]);
}

int main() {
    char infix[100], prefix[100];
    
    printf("Enter infix: ");
    scanf("%s", infix);
    
    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);
    
    prefixEval(prefix);
    
    return 0;
}

/*

(base) vyaas128@VY030-26 ~ % gedit infix_to_prefix.c
^C
(base) vyaas128@VY030-26 ~ % gcc infix_to_prefix.c -o prefix  
(base) vyaas128@VY030-26 ~ % ./prefix
Enter infix: a+b-c(e*(d+f)/g)
Prefix: -+abc/*e+dfg
Enter the value of g: 1
Enter the value of f: 4
Enter the value of d: 2
Enter the value of e: 10
Enter the value of c: 15
Enter the value of b: 3
Enter the value of a: 9 
Result of evaluation: -3.00
(base) vyaas128@VY030-26 ~ % 



*/
