#include <stdio.h>
#include <stdlib.h>
  
struct node {
    int data;
    struct node *next;
}*top;
 
int isEmpty() {
    if (top == NULL) 
        return 1;
    else
        return 0;
}
 
int peek() {
    return top->data;
}
  
void push(int n)
{
    struct node *temp;
    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->data = n;
     
    if (top == NULL) 
    {
        top = temp;
        top->next = NULL;
    } 
    else 
    {
        temp->next = top;
        top = temp;
    }
}
 
void pop() {
    struct node *temp;
    if (isEmpty(top)) 
    {
        printf("\nStack is Empty\n");
        return;
    } 
    else 
    {
        temp = top;
        top = top->next;
        printf("Removed  Element : %d\n", temp->data);   
        free(temp); 
    }
}
 
void display(struct node *nodePtr) 
{ 
  if (isEmpty(top)) 
    {
      printf("\nStack is Empty\n");
      return;
    } 
  else
  {  
  printf("\nSTACK IS\n");
  while (nodePtr != NULL) 
  {
     printf("%d\n", nodePtr->data);
     nodePtr = nodePtr->next;
  }
  printf("\n");
  }
}
 
void main() 
{
  top = NULL;
  int num,choice;
  printf("STACK OPERATION\n");
  while(1)
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
      printf("\nEnter element to be pushed: ");
      scanf("%d",&num);
      push(num);
      break;
    case 2:
      pop();
      break;  
    case 3:
      display(top);
      break; 
    case 4:
      return;  
    default: printf("\nInvalid Choice!\n");   
  }

 }
return;
}