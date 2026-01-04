
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int x){
    Node* n=(Node*)malloc(sizeof(Node));
    if(!n) exit(1);
    n->data=x; n->left=n->right=NULL;
    return n;
}


Node* buildTree(int a[], int n, int i){
    if(i >= n) return NULL;
    Node* root = newNode(a[i]);
    root->left  = buildTree(a, n, 2*i+1);
    root->right = buildTree(a, n, 2*i+2);
    return root;
}

void preorder(Node* r){ if(!r) return; printf("%d ", r->data); preorder(r->left); preorder(r->right); }
void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
void postorder(Node* r){ if(!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->data); }

void freeTree(Node* r){
    if(!r) return;
    freeTree(r->left);
    freeTree(r->right);
    free(r);
}

int main(void){
    int a[] = {1,2,3,4,5,6,7};
    int n = (int)(sizeof(a)/sizeof(a[0]));

    Node* root = buildTree(a, n, 0);

    printf("Preorder : "); preorder(root);  printf("\n");
    printf("Inorder  : "); inorder(root);   printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    freeTree(root);
    return 0;
}
