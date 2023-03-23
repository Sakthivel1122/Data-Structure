#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
} *head, *temp, *tail, *newnode;
void display()
{
    temp = head;
    while (temp->next != head)
    {
        printf("\n%d ", temp->data);
        temp = temp->next;
    }
    printf("\n%d", temp->data);
}
void create()
{
    // printf("*creation**");
    int n;
    printf("ENTER SIZE: ");
    scanf("%d", &n);
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        scanf("\n%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = temp = tail = newnode;
            newnode->prev = tail;
            newnode->next = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            tail->next = head;
            head->prev = tail;
        }
    }
    display();
}
void ins_beg()
{
    // create(n);
    int val;
    printf("\n enter val to ins at the front: ");
    scanf("%d", &val);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    head->prev = newnode;
    newnode->next = head;
    newnode->prev = tail;
    tail->next = newnode;
    head = newnode;
    // printf("%d\n", head->next->next);
    // printf("%d\n", head);
    // display();
}
void ins_end()
{
    int val;
    printf("enter the end val to ins: ");
    scanf("%d", &val);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    newnode->prev = tail;
    tail->next = newnode;
    head->prev = newnode;
    tail = newnode;
}
void ins_mid()
{
    int val;
    printf("enter value: ");
    scanf("%d", &val);
    int pos;
    printf("enter pos: ");
    scanf("%d", &pos);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    temp->next->next->prev = newnode;
}
void main()
{
    int c = 1;
    while (c)
    {
        printf("\n ***circular doubly****");
        printf("\n 1.create\n 2.display\n 3.ins_beg\n 4.ins_end\n 5.ins_mid\n");
        int ch;
        printf("enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            ins_beg();
            break;
        case 4:
            ins_end();
            break;
        case 5:
            ins_mid();
            break;
        default:
            exit(0);
        }
    }
    printf("\nenter your operation(0/1): ");
    scanf("%d", &c);
}