#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *ptr;
    ptr = head;

    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr->next != head->next);
}

void insertionAtIndex(struct Node *head, int index, struct Node *node)
{
    int count = 0;
    while (count != index - 1)
    {
        head = head->next;
        count++;
    }
    node->next = head->next;
    head->next = node;
}

void deletionAtIndex(struct Node *head, int index, int size)
{
    struct Node *ptr;
    ptr = head;
    int count = 0;
    if (index - 1 < 0)
    {
        while (count != size-1)
        {
            head = head->next;
            ptr = ptr->next;
            count++;
        }
        ptr = head->next;
        head->next = ptr->next;
        free(ptr);
        return;
    }
    while (count != index - 1)
    {
        head = head->next;
        ptr = ptr->next;
        count++;
    }
    ptr = head->next;
    head->next = ptr->next;
    free(ptr);
}

int main()
{
    struct Node *node1, *node2, *node3, *node4, *node5;

    node1 = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));
    node4 = (struct Node *)malloc(sizeof(struct Node));
    node5 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 2;
    node1->next = node2;
    node2->data = 55;
    node2->next = node3;
    node3->data = 11;
    node3->next = node4;
    node4->data = 90;
    node4->next = node1;

    node5->data = 19;
    traversal(node1);

    insertionAtIndex(node1, 2, node5);
    printf("After insertion at Index\n");
    traversal(node1);
    deletionAtIndex(node1, 0, 5);
    printf("After indexed deletion\n");
    traversal(node2);
}