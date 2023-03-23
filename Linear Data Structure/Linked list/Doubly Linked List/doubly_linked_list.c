#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*head,*tail;
int node_count = 0;
void insert(int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
        node_count++;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        node_count++;
    }
}
void delete_at_pos(int pos)
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(pos == 0)
    {
        head = head->next;
        node_count--;
    }
    else
    {
        struct node *temp = head;
        for(int i = 0;i < pos - 1;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp->next->prev = temp;
        node_count--;
    }
}
void insert_at_pos(int data,int pos)
{
    if(head == NULL || pos >= node_count)
    {
        insert(data);
    }
    else if(pos == 0)
    {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->prev = NULL;
        new_node->data = data;
        new_node->next = NULL;
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
        node_count++;
    }
    else
    {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->prev = NULL;
        new_node->data = data;
        new_node->next = NULL;
        struct node *temp = head;
        for(int i = 0 ;i < pos-1;i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        node_count++;
    }
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = head;
        printf("Elements in list:\n");
        while(temp != NULL)
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
    int pos;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Insert at position\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n");
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(data);
            printf("\n");
            break;
        case 2:
            printf("\n");
            display();
            printf("Enter position to delete element: ");
            scanf("%d", &pos);
            delete_at_pos(pos);
            printf("\n");
            break;
        case 3:
            printf("\n");
            printf("Enter data to insert: ");
            scanf("%d",&data);
            printf("Enter position to insert: ");
            scanf("%d",&pos);
            insert_at_pos(data,pos);
            printf("\n");
            break;
        case 4:
            printf("\n");
            display();
            printf("\n");
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nPlease enter a valid choice!!!\n\n");
            break;
        }
    }
}