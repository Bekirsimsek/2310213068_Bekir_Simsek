
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* newNode(int x){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n) exit(1);
    n->data=x; n->prev=n->next=NULL;
    return n;
}

void pushFront(Node** head, int x){
    Node* n = newNode(x);
    n->next = *head;
    if(*head) (*head)->prev = n;
    *head = n;
}

void pushBack(Node** head, int x){
    Node* n = newNode(x);
    if(!*head){ *head = n; return; }
    Node* t = *head;
    while(t->next) t = t->next;
    t->next = n; n->prev = t;
}

int insertAfter(Node* head, int target, int x){
    Node* t = head;
    while(t && t->data != target) t = t->next;
    if(!t) return 0;
    Node* n = newNode(x);
    n->next = t->next;
    n->prev = t;
    if(t->next) t->next->prev = n;
    t->next = n;
    return 1;
}

int deleteValue(Node** head, int x){
    Node* t = *head;
    while(t && t->data != x) t = t->next;
    if(!t) return 0;

    if(t->prev) t->prev->next = t->next;
    else *head = t->next;

    if(t->next) t->next->prev = t->prev;

    free(t);
    return 1;
}

void printForward(Node* head){
    for(Node* t=head; t; t=t->next) printf("%d <-> ", t->data);
    printf("NULL\n");
}

void printBackward(Node* head){
    if(!head){ printf("NULL\n"); return; }
    Node* t = head;
    while(t->next) t = t->next;
    while(t){ printf("%d <-> ", t->data); t = t->prev; }
    printf("NULL\n");
}

void freeList(Node** head){
    Node* t = *head;
    while(t){
        Node* nx = t->next;
        free(t);
        t = nx;
    }
    *head = NULL;
}

int main(void){
    Node* head = NULL;

    pushFront(&head, 10);
    pushBack(&head, 20);
    pushBack(&head, 30);
    insertAfter(head, 20, 25);

    printf("Forward : "); printForward(head);
    printf("Backward: "); printBackward(head);

    deleteValue(&head, 25);
    deleteValue(&head, 10);

    printf("After delete: "); printForward(head);

    freeList(&head);
    return 0;
}
