#include<stdio.h>
#include<math.h>

int max(int a,int b)
{
 if(a>b)
   return (a);
 return (b);  
}

int min(int a,int b)
{
 if(a<b)
  return(a);
 return(b);
 }
 
  
void viewpolynomial(int P[],int n)
{ int i;
  printf("\nResultant polynomial is: \n");
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

void addpoly(int P1[],int n1,int P2[],int n2,int P[])
{ int i;
  int sn;
  sn=min(n1,n2);
  for(i=0;i<=sn;i++)
    P[i]=P1[i]+P2[i];
  for(i=sn+1;i<=n1;i++)
    P[i]=P1[i];
  for(i=sn+1;i<=n2;i++)
    P[i]=P2[i];
  viewpolynomial(P,max(n1,n2));      
 return;
 }

int main()
{
  int i,j,P1[5],P2[5],P[5],n1,n2;
  
  printf("Enter the degree of the first polynomial\n");
  scanf("%d",&n1);
  printf("Enter the terms in the order of their decreasing degree\n");
  for(i=n1;i>=0;i--)
    scanf("%d",&P1[i]);
 printf("\nEnter the degree of the second polynomial\n");
    scanf("%d",&n2);
 printf("Enter the terms in the order of their decreasing degree\n");
  for(j=n2;j>=0;j--)
   scanf("%d",&P2[j]);
addpoly(P1,n1,P2,n2,P);
  }

