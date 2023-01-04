// #include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char stk[20];
int top = -1;

int isEmpty(){
    return top == -1;
}
int isFull(){
    return top == MAX - 1;
}

char peek(){
    return stk[top];
}

char pop(){
    if(isEmpty())
        return -1;

    char ch = stk[top];
    top--;
    return(ch);
}

void push(char oper){
    if(isFull())
        printf("Stack Full!!!!");
   
    else{
        top++;
        stk[top] = oper;
    }
}

int checkIfOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

int toPostfix(char* exp) 
{ 
    int i, j;

    for (i = 0, j = -1; exp[i]; ++i) 
    { 
       if (checkIfOperand(exp[i])) 
            exp[++j] = exp[i]; 

        else if (exp[i] == '(') 
            push(exp[i]); 

        else if (exp[i] == ')') 
        { 
            while (!isEmpty() && peek() != '(') 
                exp[++j] = pop(); 
            if (!isEmpty() && peek() != '(') 
                return -1; // invalid expression              
            else
                pop(); 
        }
        else // if an opertor
        { 
            while (!isEmpty() && precedence(exp[i]) <= precedence(peek())) 
                exp[++j] = pop(); 
            push(exp[i]); 
        } 

    } 

    while (!isEmpty()) 
        exp[++j] = pop(); 

    exp[++j] = '\0'; 
    printf( "%s", exp); 
} 

int main()
{
// char expression[] = "((p+(q*r))-s)"; 
    char exp[MAX];
    char *e;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    toPostfix(e);

    return 0; 
}
 

