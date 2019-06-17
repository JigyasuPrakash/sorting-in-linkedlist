#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
 struct node* left;
 int data;
 struct node* right;
};

struct node* front=NULL;
struct node* temp=NULL;
struct node* hold=NULL;
struct node* temp1=NULL;
int num=0;
clock_t start,end;
double timeis;


void insert();
void travr();
void travl();
void sortlink();

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
   case 2: sortlink(); break;
   case 3: printf("Your Right traversed list is: ");
           travr(); break;
   case 4: printf("Your Left traversed list is: ");
           travl(); break;
   case 5: exit(0);
   default: printf("\nINVALID INPUT");
  }
 }
}

void insert()
{
 int b,i;
 printf("Enter number of elements required: ");
 scanf("%d",&num);
 for(i=0;i<num;i++)
 {
  b=rand()%1000;
  //memory allocation for elements
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=b;
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
 temp=front;
 if(temp==NULL)
 {
  printf("List is Empty!");
  return;
 }
 while(temp!=NULL)
 {
  printf("%d\t",temp->data);
  temp=temp->right;
 }
}

void travl()
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
  printf("%d \t",temp->data);
  temp=temp->left;
 }
}

void sortlink()
{
 int i;
 start=clock();
 temp=front;
 if(temp==NULL)
 {
  printf("List is Empty!");
  return;
 }
 for(i=0;i<num-1;i++)
 {
  if((front->data)>(front->right->data))
   {
    hold=temp->right;
    if(hold->right!=NULL)
    {
     hold->right->left=temp;
    }
    temp->right=hold->right;
    hold->right=temp;
    hold->left=temp->left;
    temp->left=hold;
    front=hold;
    temp=front;
   }
   temp1=temp;
   temp=temp->right;
  while(temp->right!=NULL)
  {
   if((temp->data)>(temp->right->data))
   {
    hold=temp->right;
    if(hold->right!=NULL)
    {
     hold->right->left=temp;
    }
    temp->right=hold->right;
    hold->right=temp;
    temp1->right=hold;
    temp->left=hold;
    hold->left=temp1;
    temp1=hold;
   }
   else
   {
    temp1=temp;
    temp=temp->right;
   }
  }
  temp=front;
  hold=NULL;
  temp1=NULL;
 }
 end=clock();
 //printf("\nYour List has been Sorted.");
 //printf("\nSorted List from Right is: ");
 //travr();
 //printf("\nSorted List fron Left is: ");
 //travl();
 timeis=(double)(end-start)/CLOCKS_PER_SEC;
 printf("\nTime taken in Sorting using Link Swapping is: %f\n",timeis);
}
