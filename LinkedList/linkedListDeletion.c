#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void deleteFirstNode(struct Node *head)
{
    struct Node *ptr;
    head = head->next;
    free(ptr);
}

void deleteLastNode(struct Node *head)
{
    struct Node *ptr;
    while(head->next->next != NULL){
        head = head->next;
    }
    ptr = head->next;
    free(ptr);
    head->next = NULL;
}

void deleteInBetween(struct Node *head, int index){
    int count=0;
    struct Node *ptr;
    while(count != index-1){
        head = head->next;
        count++;
    }
    ptr = head->next;
    head->next = ptr->next;
    free(ptr);
}

void deleteAfterNode(struct Node *head, struct Node *nodeToDeleteAfter){
    struct Node *ptr;
    while(head->next != nodeToDeleteAfter->next){
        head = head->next;
    }
    ptr = head->next;
    head->next = ptr->next;
    free(ptr);
}

void linkedListTraversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main()
{
    struct Node *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8,*node9, *node10;
    node1 = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));
    node4 = (struct Node *)malloc(sizeof(struct Node));
    node5 = (struct Node *)malloc(sizeof(struct Node));
    node6 = (struct Node *)malloc(sizeof(struct Node));
    node7 = (struct Node *)malloc(sizeof(struct Node));
    node8 = (struct Node *)malloc(sizeof(struct Node));
    node9 = (struct Node *)malloc(sizeof(struct Node));
    node10 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 34;
    node1->next = node2;
    node2->data = 11;
    node2->next = node3;
    node3->data = 90;
    node3->next = node4;
    node4->data = 2;
    node4->next = node5;
    node5->data = 54;
    node5->next = node6;
    node6->data = 87;
    node6->next = node7;
    node7->data = 21;
    node7->next = node8;
    node8->data = 93;
    node8->next = node9;
    node9->data = 61;
    node9->next = node10;
    node10->data = 5;
    node10->next = NULL;
    linkedListTraversal(node1);
    deleteFirstNode(node1);
    printf("After deleting the first node\n");
    linkedListTraversal(node2);
    deleteLastNode(node2);
    printf("After deleting last node\n");
    linkedListTraversal(node2);
    deleteInBetween(node2,3);
    printf("After deleting in between\n");
    linkedListTraversal(node2);
    deleteAfterNode(node2,node6);
    printf("After deleting after a node\n");
    linkedListTraversal(node2);
}