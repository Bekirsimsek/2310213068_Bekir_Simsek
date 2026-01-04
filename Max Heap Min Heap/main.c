
#include <stdio.h>

#define MAX 100

void swap(int *a, int *b){ int t=*a; *a=*b; *b=t; }


void maxHeapifyDown(int h[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && h[l] > h[largest]) largest = l;
    if (r < n && h[r] > h[largest]) largest = r;
    if (largest != i) { swap(&h[i], &h[largest]); maxHeapifyDown(h, n, largest); }
}
void maxHeapifyUp(int h[], int i) {
    while (i > 0) {
        int p = (i-1)/2;
        if (h[p] >= h[i]) break;
        swap(&h[p], &h[i]);
        i = p;
    }
}
void maxInsert(int h[], int *n, int x) {
    if (*n >= MAX) return;
    h[*n] = x;
    maxHeapifyUp(h, *n);
    (*n)++;
}
int maxDeleteRoot(int h[], int *n) {
    if (*n <= 0) return -1;
    int root = h[0];
    h[0] = h[*n - 1];
    (*n)--;
    maxHeapifyDown(h, *n, 0);
    return root;
}


void minHeapifyDown(int h[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && h[l] < h[smallest]) smallest = l;
    if (r < n && h[r] < h[smallest]) smallest = r;
    if (smallest != i) { swap(&h[i], &h[smallest]); minHeapifyDown(h, n, smallest); }
}
void minHeapifyUp(int h[], int i) {
    while (i > 0) {
        int p = (i-1)/2;
        if (h[p] <= h[i]) break;
        swap(&h[p], &h[i]);
        i = p;
    }
}
void minInsert(int h[], int *n, int x) {
    if (*n >= MAX) return;
    h[*n] = x;
    minHeapifyUp(h, *n);
    (*n)++;
}
int minDeleteRoot(int h[], int *n) {
    if (*n <= 0) return -1;
    int root = h[0];
    h[0] = h[*n - 1];
    (*n)--;
    minHeapifyDown(h, *n, 0);
    return root;
}

void printArr(int a[], int n){ for(int i=0;i<n;i++) printf("%d ", a[i]); printf("\n"); }

int main(void) {
    int maxH[MAX], minH[MAX];
    int nMax = 0, nMin = 0;

    int nums[] = {4, 10, 3, 5, 1, 8};
    int m = (int)(sizeof(nums)/sizeof(nums[0]));

    for (int i = 0; i < m; i++) {
        maxInsert(maxH, &nMax, nums[i]);
        minInsert(minH, &nMin, nums[i]);
    }

    printf("MaxHeap: "); printArr(maxH, nMax);
    printf("MinHeap: "); printArr(minH, nMin);

    printf("Max root sil: %d\n", maxDeleteRoot(maxH, &nMax));
    printf("MaxHeap: "); printArr(maxH, nMax);

    printf("Min root sil: %d\n", minDeleteRoot(minH, &nMin));
    printf("MinHeap: "); printArr(minH, nMin);

    return 0;
}
