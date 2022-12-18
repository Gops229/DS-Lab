#include<stdio.h>
#define MAXSIZE 5

typedef struct queue
{
  int head;
  int tail;
  int A[MAXSIZE];
}QUEUE;

QUEUE q;


int isFull(struct queue QUEUE)
{ 
  if((q.head == q.tail +1) || (q.head ==0 && q.tail == MAXSIZE-1))
   return 1;
  return 0; 
}

int isEmpty(struct queue QUEUE)
{
  if(q.head==-1) return 1;
  return 0;
}


void enqueue(struct queue QUEUE)
{ int x;
  if (isFull(q))
  {
    printf("\nQueue is full\n");
  }
  else
  {
    printf("\nEnter element to be enqueued : ");
    scanf("%d",&x);
    if(q.head == -1) 
      q.head=0;
    q.tail=(q.tail+1)%MAXSIZE;
    q.A[q.tail]=x;  
  }
}

int dequeue(struct queue QUEUE)
{ int x;
  if(isEmpty(q))
  {
    printf("\nQueue is empty \n");
    return -1;
  }
  else
  {
   x=q.A[q.head];
   if(q.head != q.tail)
   {
    q.head=(q.head +1)%MAXSIZE;
   } 
   else
   {
    q.head=-1;
    q.tail=-1;
   }
  return x; 
  }
}

void display(struct queue QUEUE)
{
  int i;
  if(isEmpty(q)) 
     printf("\nQueue is empty\n");
  else
  { printf("\nQueue is: \n"); 
   for(i=q.head; i!=q.tail; i=(i +1 )% MAXSIZE)
   {
    printf(" %3d ",q.A[i]);
   }
  printf(" %3d \n", q.A[i]);
  
  }   
}

int main()
{
  int choice,x,d;
  
  q.head=-1;
  q.tail=-1;
  printf(" CIRCULAR QUEUE USING ARRAYS -- VARIOUS OPERATIONS \n");
  while(1)
  {
  printf("  1 --> ENQUEUE  \n");
  printf("  2 --> DEQUEUE  \n");
  printf("  3 --> DISPLAY  \n");
  printf("  4 --> EXIT  \n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
      enqueue(q);
      break;
    case 2:
      d=dequeue(q);
      if(d!=-1) printf("\n Deleted %d \n\n",d);
      else printf("");
      break;  
    case 3:
      display(q);
      break; 
    case 4:
      return; 
    default: printf("\nInvalid Choice!\n");    
  }
  
}
}
