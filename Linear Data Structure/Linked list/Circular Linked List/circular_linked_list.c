#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *tail;

struct node *insert_at_front(struct node *head, int data);
struct node *insert_at_end(struct node *head, int data);
struct node *insert_at_pos(struct node *head, int data, int pos);
struct node *delete_at_front(struct node *head);
struct node *delete_at_end(struct node *head);
struct node *deletion_at_pos(struct node *head, int pos);
void display(struct node *head);

void main()
{
    head = insert_at_end(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    // head = insert_at_pos(head,5,1);
    // head = deletion_at_pos(head,1);
    // head = delete_at_front(head);
    head = delete_at_end(head);
    display(head);
}

struct node *insert_at_front(struct node *head, int data)
{
    if (head == NULL)
    {
        head = insert_at_end(head, data);
        return head;
    }
    else
    {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = head;
        tail->next = new_node;
        head = new_node;
        return head;
    }
}

struct node *insert_at_end(struct node *head, int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return head;
    }
    else
    {
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
        return head;
    }
}
struct node *insert_at_pos(struct node *head, int data, int pos)
{
    struct node *temp = head;
    struct node *new_node = malloc(sizeof(struct node));
    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;
    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

struct node *delete_at_front(struct node *head)
{
    head = head->next;
    tail->next = head;
    return head;
}

struct node *delete_at_end(struct node *head)
{
    struct node *temp = head;
    while (temp->next != tail)
        temp = temp->next;
    temp->next = head;
    tail = temp;
    return head;
}

struct node *deletion_at_pos(struct node *head, int pos)
{
    struct node *temp = head;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;
    temp->next = temp->next->next;
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}