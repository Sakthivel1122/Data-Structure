#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void main()
{
    int count = 0;
    int n;
    int no_of_nodes;
    int data;
    printf("Enter no of lists: ");
    scanf("%d", &n);
    struct node *lists = malloc(sizeof(struct node) * n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter no of nodes in list %d: ", i + 1);
        scanf("%d", &no_of_nodes);
        struct node *head = (lists + i);
        head = malloc(sizeof(struct node)*no_of_nodes);
        head = NULL;
        for (int j = 1; j <= no_of_nodes; j++)
        {
            printf("Enter data for node %d: ", j);
            scanf("%d", &data);
            struct node *new_node = malloc(sizeof(struct node));
            new_node->data = data;
            new_node->next = NULL;
            if (head == NULL)
            {
                head = new_node;
                printf("%d\n", head->data);
            }
            else
            {
                struct node *tail = head;
                while (tail->next != NULL)
                    tail = tail->next;
                tail->next = new_node;
                tail = new_node;
                tail->next = NULL;
                printf("%d\n", tail->data);
            }
        }
    }
    struct node *head = (lists);
    int num = lists->data;
    printf(">>%d\n",lists);
    printf("%d ", head->data);
    printf("%d", lists->next->data);
    // struct node *temp = (lists);
    // while (temp != NULL)
    // {
    //     printf("%d ", temp->data);
    //     temp = temp->next;
    // }
    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     struct node *temp = (lists + i);
    //     while(temp != NULL)
    //     {
    //         printf("%d ",temp->data);
    //         temp = temp->next;
    //     }
    //     printf("\n");
    // }
}