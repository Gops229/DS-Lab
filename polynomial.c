#include<stdio.h>
#include<math.h>

void polynomial(int P[],int n)
{
  
  for(int i=n;i>=0;i--)
  { 
   if(P[i]!=0)
   {
    if(i==n)
      printf(" %2dx^%d",P[i],i);
    else if(i==0)
      printf(" +%2d ",P[i]); 
    else if(i==1)
      printf(" +%2dx",P[i]); 
    else 
      printf(" +%2dx^%d",P[i],i);
    
   }
  }
  
}

int main()
{
  int i,P[5],n;
  
  printf("Enter the degree of the polynomial\n");
  scanf("%d",&n);
  printf("Enter the terms in the order of their decreasing degree\n");
  for(i=n;i>=0;i--)
  {
   scanf("%d",&P[i]);
  }
  printf("The polynomial is \n");
  polynomial(P,n);

}