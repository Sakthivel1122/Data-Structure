#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL, *temp;
struct node *return_new_node(int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    return new_node;
}
int count = 0;
struct node *insert(struct node *root, int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    int flag = 0;
    if (root == NULL)
    {
        return new_node;
    }
    else if (root->left == NULL)
    {
        root->left = new_node;
        return root;
    }
    else if (root->right == NULL)
    {
        root->right = new_node;
        return root;
    }
    else if (root->left != NULL && count < 2)
    {
        root->left = insert(root->left, data);
        count++;
        return root;
    }
    else if (root->right != NULL)
    {
        root->right = insert(root->right, data);
        // count++;
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
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}