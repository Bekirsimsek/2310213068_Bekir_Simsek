#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int x){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n) exit(1);
    n->data=x; n->next=n;
    return n;
}

void pushFront(Node** head, int x){
    Node* n = newNode(x);
    if(!*head){ *head = n; return; }

    Node* tail = *head;
    while(tail->next != *head) tail = tail->next;

    n->next = *head;
    tail->next = n;
    *head = n;
}

void pushBack(Node** head, int x){
    if(!*head){ *head = newNode(x); return; }
    Node* tail = *head;
    while(tail->next != *head) tail = tail->next;

    Node* n = newNode(x);
    n->next = *head;
    tail->next = n;
}

int insertAfter(Node* head, int target, int x){
    if(!head) return 0;
    Node* t = head;
    do {
        if(t->data == target){
            Node* n = newNode(x);
            n->next = t->next;
            t->next = n;
            return 1;
        }
        t = t->next;
    } while(t != head);
    return 0;
}

int deleteValue(Node** head, int x){
    if(!*head) return 0;

    Node* cur = *head;
    Node* prev = NULL;


    if(cur->next == cur){
        if(cur->data == x){
            free(cur);
            *head = NULL;
            return 1;
        }
        return 0;
    }


    do {
        if(cur->data == x) break;
        prev = cur;
        cur = cur->next;
    } while(cur != *head);

    if(cur->data != x) return 0;

    if(cur == *head){

        Node* tail = *head;
        while(tail->next != *head) tail = tail->next;
        *head = cur->next;
        tail->next = *head;
        free(cur);
        return 1;
    }

    prev->next = cur->next;
    free(cur);
    return 1;
}

void traverse(Node* head){
    if(!head){ printf("Liste bos\n"); return; }
    Node* t = head;
    do {
        printf("%d -> ", t->data);
        t = t->next;
    } while(t != head);
    printf("(Bas)\n");
}

void freeList(Node** head){
    if(!*head) return;
    Node* cur = (*head)->next;
    while(cur != *head){
        Node* nx = cur->next;
        free(cur);
        cur = nx;
    }
    free(*head);
    *head = NULL;
}

int main(void){
    Node* head = NULL;
    pushFront(&head, 10);
    pushBack(&head, 20);
    pushBack(&head, 30);
    insertAfter(head, 20, 25);

    traverse(head);

    deleteValue(&head, 10);
    deleteValue(&head, 25);

    traverse(head);

    freeList(&head);
    return 0;
}
