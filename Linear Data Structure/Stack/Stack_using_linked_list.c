#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *top;

void push(int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (top == NULL)
    {
        top = new_node;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Poped element: %d\n", top->data);
        top = top->next;
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *temp = top;
        printf("Elements in stack:\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main()
{
    int choice;
    int data;
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n");
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(data);
            printf("\n");
            break;
        case 2:
            printf("\n");
            pop();
            printf("\n");
            break;
        case 3:
            printf("\n");
            peek();
            printf("\n");
            break;
        case 4:
            printf("\n");
            display();
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("\nPlease enter a valid choice!!!\n\n");
        }
    }
}