#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 10

struct node
{
 struct node* left;
 int data[max];
 struct node* right;
};

struct node* front=NULL;
struct node* temp=NULL;
int num=0;
clock_t start,end;
double timeis;

void insert();
void travr();
//void travl();
void sortval();

void main()
{
 int n;
 printf("\n---------BY DEFAULT INSERTION IS CARRIED OUT AT BEGINING----------");
 while(1)
 {
  printf("\nChoose one of the following:\n1.Insertion\n2.Sorting\n3.Traverse Right\n4.Traverse Left\n5.Exit\n");
  scanf("%d",&n);
  switch(n)
  {
   case 1: insert(); break;
   case 2: sortval(); break;
   case 3: printf("Your Right traversed list is: ");
           travr(); break;
   /*case 4: printf("Your Left traversed list is: ");
           travl(); break;*/
   case 5: exit(0);
   default: printf("\nINVALID INPUT");
  }
 }
}

void insert()
{
 int b,i,j;
 printf("Enter number of elements required: ");
 scanf("%d",&num);
 for(i=0;i<num;i++)
 {
  //memory allocation for elements
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  for(j=0;j<max;j++)
  {
   b=rand()%1000;
   newnode->data[j]=b;
  }
  newnode->left=NULL;
  if(front==NULL)
  {
   newnode->right=NULL;
   front=newnode;
  }
  else
  {
   newnode->right=front;
   front->left=newnode;
   front=newnode;
  }
 }
 printf("Your %d element is generated in list",num);
 //travr();
}

void travr()
{
 int j;
 temp=front;
 if(temp==NULL)
 {
  printf("List is Empty!");
  return;
 }
 while(temp!=NULL)
 {
  for(j=0;j<max;j++)
  {
   printf("%d\t",temp->data[j]);
  }
  temp=temp->right;
  printf("\n");
 }
}

/*void travl()
{
 temp=front;
 if(temp==NULL)
 {
  printf("List is Empty!");
  return;
 }
 while(temp->right!=NULL)
 {
  temp=temp->right;
 }
 while(temp!=NULL)
 {
  printf("%d \t",temp->data[j]);
  temp=temp->left;
 }
}*/

void sortval()
{ 
 int t,i,j; 
 start=clock();
 temp=front;
 for(i=0;i<num-1;i++)
 {
  while(temp->right!=NULL)
  {
   if((temp->data[0])>((temp->right)->data[0]))
   {
    for(j=0;j<max;j++)
    {
     t=temp->data[j];
     temp->data[j]=(temp->right)->data[j];
     (temp->right)->data[j]=t;
    }
   }
   temp=temp->right;
  }
  temp=front;
 }
 end=clock(); 
 //printf("\nYour List has been Sorted by exchanging values.");
 //printf("\nSorted List from Right is: ");
 //travr();
 //printf("\nSorted List fron Left is: ");
 //travl();
 timeis=(double)(end-start)/CLOCKS_PER_SEC;
 printf("\nTime taken in Sorting using Value Swap is: %f\n",timeis);
} 
