#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* head;
void createnode(int n);
void deletenode(head);
void printnode(head);
void main()
{
    int n;
    printf("enter the number of node:");
    scanf("%d",&n);
    createnode(n);
    printnode(head);
    deletenode(head);
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
    scanf("%d",&head->data);               //Here we create first node only and enter element in first node
    head->link=NULL;   //we assign null pointer in first node
    temp=head;
    for(i=2;i<=n;i++)
    {
         newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data of %d node: ",i);
        scanf("%d",&newnode->data);
        newnode->link=NULL;
        temp->link=newnode;
        temp=temp->link;
    }}
}

void printnode(struct node*p)
{
    if(head==NULL)
        printf("list is empty");
    else
        {
          p=head;
          printf("The data in nodes are:\n");
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->link;
    }
        }
}

void deletenode()
{
    struct node *temp;
    int loc;
    printf("enter the location from which you want to delete:");
    scanf("%d",&loc);
    if(loc==1)
    {
     temp=head;
     head=head->link;
     free(temp);
    }
    else
    {
        struct node*p,*q;
        p=head;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
}
