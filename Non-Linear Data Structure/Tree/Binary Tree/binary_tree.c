#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root,*temp;
struct node *return_new_node(int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    return new_node;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        printf("1\n");
        return return_new_node(data);
    }
    else if(root->left == NULL)
    {
        printf("2\n");
        root->left = insert(root->left,data);
        return root;
        // root->left = return_new_node(data);
        // return root;
    }
    else if(root->right == NULL)
    {
        printf("3\n");
        root->right = insert(root->right,data);
        return root;
        // root->right == return_new_node(data);
        // return root;
    }
    else if(root->left != NULL)
    {
        root->left->left = insert(temp,data);
    }
    else if(root->right != NULL)
    {
        root->right->right = insert(root->right,data);
    }
    else
    {
        return root;
    }
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void main()
{
    int data = 1;
    while (1)
    {
        printf("Enter: ");
        scanf("%d", &data);
        if (data < 0)
            break;
        root = insert(root, data);
    }
    inorder(root);
}