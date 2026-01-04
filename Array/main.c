
#include <stdio.h>

#define CAP 20

void printArr(int a[], int n){
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
}

int insertAt(int a[], int *n, int idx, int x){
    if(*n >= CAP) return 0;
    if(idx < 0 || idx > *n) return 0;
    for(int i=*n; i>idx; i--) a[i] = a[i-1];
    a[idx] = x;
    (*n)++;
    return 1;
}

int deleteAt(int a[], int *n, int idx){
    if(*n <= 0) return 0;
    if(idx < 0 || idx >= *n) return 0;
    for(int i=idx; i<*n-1; i++) a[i] = a[i+1];
    (*n)--;
    return 1;
}

int main(void){
    int a[CAP] = {1,2,4,5};
    int n = 4;

    printf("Baslangic: "); printArr(a,n);

    insertAt(a,&n,0,0);
    printf("Basa ekle:  "); printArr(a,n);

    insertAt(a,&n,n,6);
    printf("Sona ekle:  "); printArr(a,n);

    insertAt(a,&n,3,3);
    printf("Araya ekle: "); printArr(a,n);

    deleteAt(a,&n,0);
    printf("Bastan sil: "); printArr(a,n);

    deleteAt(a,&n,n-1);
    printf("Sondan sil: "); printArr(a,n);

    deleteAt(a,&n,2);
    printf("Aradan sil: "); printArr(a,n);

    return 0;
}
