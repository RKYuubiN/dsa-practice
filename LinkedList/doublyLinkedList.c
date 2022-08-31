#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void insertionAtIndex(struct Node *head, struct Node *node, int index)
{
    int count = 0;
    struct Node *ptr;
    while (count != index)
    {
        head = head->next;
        count++;
    }
    ptr = head->prev;
    if (index == 0)
    {
        node->prev = NULL;
    }
    else
    {
        node->prev = head->prev;
    }
    ptr->next = node;
    node->next = head;
    head->prev = node;
}

void deletionAtIndex(struct Node *head, int index, int size){
    struct Node *ptr;
    int count = 0;
    if(index == 0){
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
    }else if(index == size-1){
        while(index != count){
            head = head->next;
            count++;
        }
        head = head->prev;
        head->next = NULL;
    }else{
        while(index != count){
            head = head->next;
            count++;
        }
        ptr = head->prev;
        ptr->next = head->next;
        free(head);
    }
}

void main()
{
    struct Node *node1, *node2, *node3, *node4, *node5;

    node1 = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));
    node4 = (struct Node *)malloc(sizeof(struct Node));
    node5 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 11;
    node1->prev = NULL;
    node1->next = node2;

    node2->data = 2;
    node2->prev = node1;
    node2->next = node3;

    node3->data = 41;
    node3->prev = node2;
    node3->next = node4;

    node4->data = 24;
    node4->prev = node3;
    node4->next = NULL;

    node5->data = 90;
    traversal(node1);
    insertionAtIndex(node1, node5, 1);
    printf("After insertion\n");
    traversal(node1);
    deletionAtIndex(node1,0,5);
    printf("After deletion\n");
    traversal(node5);
}