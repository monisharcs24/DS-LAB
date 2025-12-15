#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

int main() {
    int m, n, i, key, index, startIndex;

    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);

    int hashTable[m];

    for (i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter 4-digit employee key: ");
        scanf("%d", &key);

        index = hash(key, m);
        startIndex = index;

        while (hashTable[index] != EMPTY) {
            index = (index + 1) % m;

            if (index == startIndex) {
                printf("Hash Table is full. Cannot insert key %d\n", key);
                break;
            }
        }

        if (hashTable[index] == EMPTY) {
            hashTable[index] = key;
            printf("Key %d inserted at address %d\n", key, index);
        }
    }

    printf("\nHash Table Contents:\n");
    for (i = 0; i < m; i++) {
        if (hashTable[i] == EMPTY)
            printf("Address %02d : EMPTY\n", i);
        else
            printf("Address %02d : %d\n", i, hashTable[i]);
    }

    return 0;
}
