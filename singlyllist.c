#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node* next;
}NODE;

void insertlast(struct node** H,int x)
{
  struct node* current= *H;
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data =x;
  temp->next = NULL;
  if(*H==NULL)
  {
   *H=temp;
   return;
  }
  else{
    while(current->next!=NULL)
    {
      current = current->next;
    }
   current->next = temp; 
  } 
return;  
}

int search(struct node** H,int key)
{
  struct node* current= *H;
  while(current!=NULL)
  {
    if(current->data == key)
      return 1;
    current= current->next;  
  }
 return 0; 
}

void delnode(struct node** H,int key)
{
  if(*H==NULL)
   return;
  struct node* current= *H;
  struct node* todelete;
  if(current->data==key)
  {
    *H= current->next;
    current->next=NULL;
    free(current);
    return;
  }
  while(current->next!=NULL && current->next->data !=key)
  {
    current = current->next;
  }
  if(current->next != NULL)
  {
    todelete = current->next;
    current->next = todelete->next;
    todelete->next = NULL;
  }
  current=NULL;
  return;
}

void printlist(struct node* n)
{
  while(n!=NULL)
  {
    printf(" %2d ",n->data);
    n= n->next;
  }
}

int main()
{
  struct node* head= NULL;
  int choice;
  int option=1;
  int x,key,item;
printf("LINKED LIST OPERATION\n");
while(option)
  {
  printf("  1 --> INSERT_NODE  \n");
  printf("  2 --> DELETE_NODE  \n");
  printf("  3 --> PRINT_LIST  \n");
  printf("  4 --> SEARCH_LIST  \n");
  printf("  5 --> EXIT  \n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
      printf("Enter the data to be inserted\n");
      scanf("%d",&x);
      insertlast(&head,x);
      break;
    case 2:
      printf("Enter the data to be deleted\n");
      scanf("%d",&key);
      delnode(&head,key);
      printf("\nEdited list:\n");
      printlist(head);
      break;  
    case 3:
      printf("Linked list is \n");
      printlist(head);
      break; 
    case 4:
      printf("Enter element to be searched : ");
      scanf("%d",&item);
      if(search(&head,item))
        printf("\nElement %d is found in the list",item);
      else
        printf("\nElement %d is not found in the list",item); 
      break;     
    case 5:
      return;
    default: printf("\nInvalid Choice!\n");     
  }
  fflush(stdin);
  
  printf("\nDo you want to continue?(0:NO 1:YES)\n");
  scanf("%d",&option);
}
}
