//To create Trees and traverse with preorder,inorder and postorder
#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
int *create();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node *t);
int main()
{
   root=create();
   printf("Inorder traversal is \n:" );
   inorder(root);
    printf("preorder traversal is \n:" );
    preorder(root);
     printf("postorder traversal is \n:" );
     postorder(root);
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
void preorder(struct node *t)
{
    if(t)
    {
        printf("%d\n",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(struct node *t)
{
    if(t)
    {
     postorder(t->left);
     postorder(t->right);
     printf("%d\n",t->data);
    }
}
