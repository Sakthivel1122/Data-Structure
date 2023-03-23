#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root;

struct node* return_new_node(int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
struct node *insert(struct node *root, int data)
{
    if(root == NULL)
    {
        return return_new_node(data);
    }
    else if(data < root->data)
    {
        root->left = insert(root->left,data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right,data);
    }
    else
    {
        return root;
    }
}

void inorder(struct node *root)
{
    if(root == NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void main()
{
    int data = 1;
    while (1)
    {
        printf("Enter: ");
        scanf("%d",&data);
        if(data < 0)break;
        root = insert(root,data);
    }
    inorder(root);
}