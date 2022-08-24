#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * insertAtBeginning(struct Node *linkedList, struct Node *head,int data){
    linkedList->data = data;
    linkedList->next = head;

}
void linkListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertInBetween(struct Node *nodeToAdd, int index, int data, struct Node *head){
    int count = 0;
    while(count < index-1){
        head = head->next;
        count++;
    }

    nodeToAdd->data = data;
    nodeToAdd->next = head->next;
    head->next = nodeToAdd;
}

struct Node * insertAtLast(struct Node *nodeToAdd, int data, struct Node *head){
    while(head->next != NULL){
        head = head->next;
    }
    head->next = nodeToAdd;
    nodeToAdd->data = data;
    nodeToAdd->next = NULL;
}

struct Node * insertAfterNode(struct Node *nodeToAdd, int data, struct Node *nodeToAddAfter){
    nodeToAdd->data = data;
    nodeToAdd->next = nodeToAddAfter->next;
    nodeToAddAfter->next = nodeToAdd;
}

int main()
{
    struct Node *node1,*node2,*node3;
    struct Node *nodeAtBeginning,*nodeInBetween, *nodeAtLast, *nodeAfterNode;

    node1 = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));


    node1->data = 33;
    node1->next = node2;
    node2->data = 12;
    node2->next = node3;
    node3->data = 1;
    node3->next = NULL;

    linkListTraversal(node1);

    nodeAtBeginning = (struct Node *)malloc(sizeof(struct Node));
    nodeInBetween = (struct Node *)malloc(sizeof(struct Node));
    nodeAtLast = (struct Node *)malloc(sizeof(struct Node));
    nodeAfterNode = (struct Node *)malloc(sizeof(struct Node));
    insertAtBeginning(nodeAtBeginning,node1,34);
    printf("After inserting at the beginning \n");
    linkListTraversal(nodeAtBeginning);
    insertInBetween(nodeInBetween,2,23,nodeAtBeginning);
    printf("After inserting in between \n");
    linkListTraversal(nodeAtBeginning);
    insertAtLast(nodeAtLast,65,nodeAtBeginning);
    printf("After inserting to last \n");
    linkListTraversal(nodeAtBeginning);
    insertAfterNode(nodeAfterNode,72,node2);
    printf("After inserting after a node \n");
    linkListTraversal(nodeAtBeginning);
}