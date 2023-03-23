#include <stdio.h>
#include<stdlib.h>
int size = 5;
int queue[5];
int front = -1;
int rear = -1;
void enqueue(int data)
{
    if(rear == size-1)
    {
        printf("Queue is full\n");
    }
    else if(front == -1)
    {
        front++;
        rear++;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

void dequeue()
{
    if(front == -1 || rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i = 0;i < rear;i++)
        {
            queue[i] = queue[i+1];
        }
        rear--;
        if(rear == -1)front = -1;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements in queue:\n");
        for(int i = front;i <= rear;i++)
        {
            printf("%d ",queue[i]);
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
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your  choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n");
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
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