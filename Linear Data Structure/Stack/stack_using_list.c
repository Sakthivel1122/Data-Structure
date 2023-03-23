#include<stdio.h>
#include<stdlib.h>
int size = 5;
int stack[5];
int top = -1;

void push(int data)
{
    if(top == size - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        top--;
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Top element: %d\n",stack[top]);
    }
}
void display()
{
    if(top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Elements in stack:\n");
        for(int i = top;i >= 0; i--)
        {
            printf("%d ",stack[i]);
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