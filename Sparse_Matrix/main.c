
#include <stdio.h>

#define R 3
#define C 3

typedef struct {
    int row;
    int col;
    int val;
} Triple;

int countNonZero(int mat[R][C]) {
    int cnt = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (mat[i][j] != 0) cnt++;
    return cnt;
}

void printMatrix(int mat[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) printf("%3d ", mat[i][j]);
        printf("\n");
    }
}

int toSparse(int mat[R][C], Triple sparse[], int maxSize) {
    int nz = countNonZero(mat);
    if (maxSize < nz + 1) return -1; // yer yok

    // header
    sparse[0].row = R;
    sparse[0].col = C;
    sparse[0].val = nz;

    int k = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mat[i][j] != 0) {
                sparse[k++] = (Triple){i, j, mat[i][j]};
            }
        }
    }
    return k; // toplam satýr sayýsý (header dahil)
}

void toNormal(Triple sparse[], int sparseSize, int out[R][C]) {
    // sýfýrla
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            out[i][j] = 0;

    for (int i = 1; i < sparseSize; i++) {
        int r = sparse[i].row, c = sparse[i].col;
        out[r][c] = sparse[i].val;
    }
}

int main(void) {
    int mat[R][C] = {
        {0, 0, 5},
        {0, 8, 0},
        {2, 0, 0}
    };

    Triple sparse[100];
    int sparseSize = toSparse(mat, sparse, 100);
    if (sparseSize < 0) {
        printf("Sparse dizi boyutu yetersiz!\n");
        return 1;
    }

    printf("Normal Matris:\n");
    printMatrix(mat);

    printf("\nSparse (3'lu gosterim):\n");
    printf("row col val\n");
    for (int i = 0; i < sparseSize; i++)
        printf("%3d %3d %3d\n", sparse[i].row, sparse[i].col, sparse[i].val);

    int back[R][C];
    toNormal(sparse, sparseSize, back);

    printf("\nSparse -> Normal:\n");
    printMatrix(back);

    return 0;
}
