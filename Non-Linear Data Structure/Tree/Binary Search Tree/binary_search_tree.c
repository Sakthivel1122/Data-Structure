#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
} *root;
struct node *return_new_node(int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->key = data;
    return new_node;
}
struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return return_new_node(data);

    if (data < node->key)
        node->left = insert(node->left, data);
    else if (data > node->key)
        node->right = insert(node->right, data);

    return node;
}
struct node* min_val_node()
{
    struct node *temp = root;
    while(temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
struct node* delete(struct node *root,int data)
{
    if(root == NULL)
        return root;
    
    if(data < root->key)
        root->left = delete(root->left,data);
    else if(data > root->key)
        root->right = delete(root->right,data);
    else
    {
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = min_val_node(root);
            root->key = temp->key;
            root->right = delete(root->right,temp->key);
        }
    }
    return root;
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}
void main()
{
    int choice;
    int data;
    int pos;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n");
            inorder(root);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root,data);
            printf("\n");
            break;
        case 2:
            printf("\n");
            inorder(root);
            printf("Enter element to delete: ");
            scanf("%d", &data);
            delete(root,data);
            printf("\n");
            break;
        case 3:
            printf("\n");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("\n");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("\n");
            postorder(root);
            printf("\n");
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nPlease enter a valid choice!!!\n\n");
            break;
        }
    }
}