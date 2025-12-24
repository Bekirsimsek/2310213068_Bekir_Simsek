
#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Disk %d: %c -> %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main(void) {
    int n = 3;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
