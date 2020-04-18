//To find no of nodes of BST
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
int *create(void);
void inorder(struct node *);
int totalnodes(struct node *);
int main()
{
    root=create();
    printf("entered data are:\n");
    inorder(root);
    printf("No of nodes are %d",totalnodes(root));

}

int *create()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the root data(-1 is for no data entered) :");
    scanf("%d",&newnode->data);
    if(newnode->data==-1)
    {

     printf("You have not entered any data\n");

     return NULL;

      }
    printf("Enter the left child data rooted at %d\n",newnode->data);
    newnode->left=create();
    printf("Enter the right child data rooted at %d\n",newnode->data);
     newnode->right=create();
     return newnode;
}


int totalnodes(struct node *p)
{
    p=root;
     if(p= NULL)
     {
         return 0;
     }
     else
    {
       return 1+ totalnodes(p->left)+totalnodes(p->right);
    }
}


void inorder(struct node *t)
{
    if(t)
    {
        inorder(t->left);
      printf("%d\n",t->data);
      inorder(t->right);
    }
}
