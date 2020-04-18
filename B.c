//To create doubly link list,delete and display
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node* head;
void createnode(int);
void printnode(head);
void deletenode(int);
void main()
{
    int n,a;
    printf("enter the number of node:");
    scanf("%d",&n);
    createnode(n);
    printnode(head);
    deletenode(n);
    printnode(head);
}
void createnode(int n)
{
    struct node *temp,*newnode;
    head=(struct node*)malloc(sizeof(struct node));
    int i;
    if(head==NULL)
    {
        printf("Data not found");
    }
    else
    {
    printf("enter the first node data:");
    scanf("%d",&head->data);
    head->next=NULL;
    head->prev=NULL;
    temp=head;
    for(i=2;i<=n;i++)
    {
         newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data of %d node: ",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
    }}
}

void printnode(struct node*p)
{
    if(head==NULL)
        printf("list is empty");
    else
        {
          p=head;
           printf("The data in the node are\n");
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
        }
}

void deletenode(int n)
{
    int loc,i=1;
    printf("Enter the location where you want to delete:\n");
    scanf("%d",&loc);
    if(loc==1)
    {
       struct node *p,*q;
       p=head;
       head=head->next;
       p->next=NULL;
       head->prev=NULL;
       free(p);
    }
   else
    if(loc==n)
   {
       struct node *p,*q;
       p=head;
       if(p->next->next==NULL)
       {
           p=p->next;
       }
       q=p->next;
       p->next=NULL;
       q->next=NULL;q->prev=NULL;
       free(q);
   }
   else
    {
        struct node *p,*q,*r;
        p=head;
       while(i<loc-1)
        {
          p=p->next;
          i++;
        }
        q=p->next;
        r=q->next;
        p->next=q->next;
        r->prev=q->prev;
        q->next=NULL;q->prev=NULL;
        free(q);
    }
}
