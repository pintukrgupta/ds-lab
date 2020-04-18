//To create BST ,the height of the tree and  traversing inorder
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
int *create();
void inorder(struct node*);
int height(struct node *);
int main()
{
   root=create();
   printf("Inorder traversal is :\n" );
   inorder(root);
   printf("The height of the tree is %d",height(root));
   return 0;
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
void inorder(struct node *t)
{
    if(t)
    {
        inorder(t->left);
      printf("%d\n",t->data);
      inorder(t->right);
    }
}

int height(struct node *t)
{
    int l,r;
    if(!t)
    {
        return 0;
    }
    if(!t->left&&!t->right)
    {
        return 0;
    }
     l=height(t->left);
     r=height(t->right);
     return (1+(l>r)?l:r);
}
