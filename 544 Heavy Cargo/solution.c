// by ChatGPT
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_CITIES 200
#define MAX_EDGES 19900
#define HASH_SIZE 1031

typedef struct {
    int parent, child, weight;
} Edge;

typedef struct HashNode {
    char city[32];
    int id;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[HASH_SIZE];

int root[MAX_CITIES];
Edge edges[MAX_EDGES];
int cityCount;

unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + (*str++);
    }
    return hash % HASH_SIZE;
}

int getCityID(const char* city) {
    unsigned int index = hash(city);
    HashNode* node = hashTable[index];
    while (node) {
        if (strcmp(node->city, city) == 0) {
            return node->id;
        }
        node = node->next;
    }

    // Add new city to hash table
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    strcpy(newNode->city, city);
    newNode->id = cityCount++;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    return newNode->id;
}

void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = hashTable[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int findRoot(int child) {
    if (root[child] == child) return child;
    return root[child] = findRoot(root[child]);
}

int compareEdges(const void *a, const void *b) {
    return ((Edge *)b)->weight - ((Edge *)a)->weight;
}

int main() {
    int n, r, cases = 0;
    char city1[32], city2[32];

    while (1) {
        scanf("%d %d", &n, &r);
        if (n == 0) break;

        printf("Scenario #%d\n", ++cases);

        cityCount = 0;
        memset(hashTable, 0, sizeof(hashTable));

        int edgeCount = 0;
        for (int i = 0; i < r; i++) {
            int weight;
            scanf("%s %s %d", city1, city2, &weight);

            int id1 = getCityID(city1);
            int id2 = getCityID(city2);

            edges[edgeCount++] = (Edge){id1, id2, weight};
        }

        qsort(edges, edgeCount, sizeof(Edge), compareEdges);

        scanf("%s %s", city1, city2);

        int start = getCityID(city1);
        int end = getCityID(city2);

        for (int i = 0; i < cityCount; i++) root[i] = i;

        int limit = 10000;
        for (int i = 0; findRoot(start) != findRoot(end); i++) {
            int root1 = findRoot(edges[i].parent);
            int root2 = findRoot(edges[i].child);
            if (root1 != root2) {
                root[root2] = root1;
                if (edges[i].weight < limit) limit = edges[i].weight;
            }
        }

        printf("%d tons\n\n", limit);
        freeHashTable();
    }

    return 0;
}
