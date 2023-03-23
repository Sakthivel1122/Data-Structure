#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front,*rear;

void enqueue(int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(front == NULL)
    {
        front = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = rear->next;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Dequeued element: %d\n",front->data);
        front = front->next;
    }
}
void display()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp = front;
        printf("Elements in Queue:\n");
        while (temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main()
{
    int choice;
    int data;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your  choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\n");
            printf("Enter data to enqueue: ");
            scanf("%d",&data);
            enqueue(data);
            printf("\n");
            break;
        case 2:
            printf("\n");
            dequeue();
            printf("\n");
            break;
        case 3:
            printf("\n");
            display();
            printf("\n");
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please enter a valid choice!!!");
            break;
        }
    }
}