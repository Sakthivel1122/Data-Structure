#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *tail;
int node_count = 0;
void insert(int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        node_count++;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
        node_count++;
    }
}
void delete(int pos)
{
    if (pos == 0)
    {
        if (head != NULL)
        {
            head = head->next;
            node_count--;
        }
    }
    else
    {
        struct node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        node_count--;
    }
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n\n");
        return;
    }
    printf("Elements in list:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_pos(int data,int pos){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(pos == 0){
        new_node->next = head;
        head = new_node;
        node_count++;
    }
    else
    {
        struct node *temp = head;
        for(int i = 0;i < pos - 1;i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        node_count++;
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
            delete (pos);
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