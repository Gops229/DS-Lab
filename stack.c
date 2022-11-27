#include<stdio.h>
#define MAXSIZE 5

typedef struct stack
{
  int top;
  int A[MAXSIZE];
}STACK;

STACK S;
void push(struct stack STACK)
{
  int x;
  if(S.top==MAXSIZE-1)
  {
    printf("Stack is full\n");
    return;
  }
  else{
    printf("Enter the element to be pushed\n");
    scanf("%d",&x);
    S.top=S.top +1;
    S.A[S.top]=x;
  }
  return;
}

int pop(struct stack STACK)
{
  int x;
  if(S.top==-1)
  {
    printf("Stack is empty\n");
    return(S.top);
  }
  else
  {
    x=S.A[S.top];
    printf("Popped element is= %d\n", S.A[S.top]);
    S.top=S.top-1;
  }
  return(x);
}

void display(struct stack STACK)
{
  int i;
  if(S.top==-1)
  {
    printf("Stack is empty\n");
    return;
  }
  else
  {
    printf("\n The stack is \n");
    for(i=S.top;i>=0;i--)
    {
      printf("%d\n",S.A[i]);
    }
    printf("\n");
  }
}

void main()
{
  int choice;
  int option=1;
  S.top=-1;
  printf("STACK OPERATION\n");
  while(option)
  {
  printf("  1 --> PUSH  \n");
  printf("  2 --> POP  \n");
  printf("  3 --> DISPLAY  \n");
  printf("  4 --> EXIT  \n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
      push(S);
      break;
    case 2:
      pop(S);
      break;  
    case 3:
      display(S);
      break; 
    case 4:
      return;  
    default: printf("\nInvalid Choice!\n");   
  }
  fflush(stdin);
  
  printf("Do you want to continue?(0:NO 1:YES)\n");
  scanf("%d",&option);
}
}