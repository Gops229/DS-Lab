#include<stdio.h>
#define SIZE 5

typedef struct deque
{
  int front;
  int rear;
  int A[SIZE];
  int size;
}DEQUE;

DEQUE q;

void insertfront(struct deque DEQUE)
{
  int x;
  if((q.front==0 && q.rear==SIZE-1) || (q.front==q.rear + 1))
     printf("\nThe Queue is Full\n");
  
  else if(q.front==-1 && q.rear==-1)
  { 
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&x);
    q.front=0;
    q.rear=0;
    q.A[q.front]=x;
  }   
  else if(q.front==0)
  { 
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&x);
    q.front=SIZE-1;
    q.A[q.front]=x;
  }
  else
  { 
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&x);
    q.front--;
    q.A[q.front]=x;
  }
}

void insertrear(struct deque DEQUE)
{
  int x;
  if((q.front==0 && q.rear==SIZE-1) || (q.front==q.rear +1))
    printf("\nQueue is full\n");
  else if(q.front==-1 && q.rear==-1)
  {
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&x);
    q.front=0;
    q.rear=0;
    q.A[q.rear]=x;
  } 
  else if(q.rear==SIZE-1)
  { 
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&x);
    q.rear=0;
    q.A[q.rear]=x;
  }
  else
  { 
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&x);
    q.rear++;
    q.A[q.rear]=x;
  } 
}

int deletefront(struct deque DEQUE)
{
  int x;
  if(q.front==-1 && q.rear==-1)
  {
    printf("\nQueue is empty \n");
    return -1;
  }
  else if(q.front==q.rear)
  {
    x=q.A[q.front];
    q.front=-1;
    q.rear=-1;
  }  
  else if(q.front==SIZE-1)
  {
    x=q.A[q.front];
    q.front=0;
  }
  else
  {
    x=q.A[q.front];
    q.front++;
  }
  return(x);
}

int deleterear(struct deque DEQUE)
{ 
  int x;
  if(q.front==-1 && q.rear==-1)
  {
    printf("\nQueue is empty \n");
    return -1;
  }  
  
  else if(q.front==q.rear)
  {
    x=q.A[q.rear];
    q.front=-1;
    q.rear=-1;
  } 

  else if(q.rear==0)
  {
    x=q.A[q.rear];
    q.rear=SIZE-1;
  } 
  else
  {
    x=q.A[q.rear];
    q.rear--;
  }
  return(x);
}

void display(struct deque DEQUE)
{
  int i;
  if(q.front==-1 && q.rear==-1)
    printf("\nQueue is empty \n");
  else
  {  
  printf("\nThe Double Ended Queue is: \n");
  for(i=q.front; i!=q.rear; i=(i +1 )% SIZE)
   {
    printf(" %3d ",q.A[i]);
   }
  printf(" %3d \n", q.A[q.rear]);
  }
}

int main()
{
  int choice,x,d;
  int option=1;
  q.front=-1;
  q.rear=-1;
  printf(" DOUBLE ENDED QUEUE USING CIRCULAR ARRAY -- VARIOUS OPERATIONS \n");
  while(option)
  {
  printf("  1 --> ENQUEUE_FRONT  \n");
  printf("  2 --> ENQUEUE_REAR  \n");
  printf("  3 --> DEQUEUE_FRONT  \n");
  printf("  4 --> DEQUEUE_REAR  \n");
  printf("  5 --> DISPLAY_QUEUE  \n");
  printf("  6 --> EXIT  \n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
      insertfront(q);
      break;
    
    case 2:
      insertrear(q);
      break;  
    
    case 3:
      d=deletefront(q);
      if(d!=-1) printf("\n Deleted %d \n\n",d);
      else printf("");
      break;  
    
    case 4:
      x=deleterear(q);
      if(x!=-1) printf("\n Deleted %d \n\n",x);
      else printf("");
      break;  
       
    case 5:
      display(q);
      break;

    case 6:
      return;  
    default: printf("\nInvalid Choice!\n");    
  }
  fflush(stdin);
  printf("Do you want to continue?(0:NO 1:YES)\n");
  scanf("%d",&option);
}
}