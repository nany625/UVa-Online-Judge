// 我暫時不會寫
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUM 200000
#define MAX_NAME_LEN 21
#define HASH_TABLE_SIZE 262144

typedef struct Node {
    char name[MAX_NAME_LEN];
    int id;
    struct Node* next;
} Node;

int root[MAX_NUM], depth[MAX_NUM], friend_count;
Node* hashTable[HASH_TABLE_SIZE];

unsigned int hash(char* str) {
    unsigned int hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++;
    }
    return hash % HASH_TABLE_SIZE;
}

int findRoot(int child) {
    if (root[child] == child) return child;
    return root[child] = findRoot(root[child]);
}

Node* createNode(char* name, int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

int addOrGetID(char* name) {
    unsigned int index = hash(name);
    Node* current = hashTable[index];

    // Search for the name in the linked list
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current->id;
        }
        current = current->next;
    }

    // Not found, add a new entry
    Node* newNode = createNode(name, friend_count);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    root[friend_count] = friend_count;
    depth[friend_count] = 1;
    return friend_count++;
}

void freeHashTable() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    int cases;
    scanf("%d", &cases);

    while (cases-- > 0) {
        int F;
        friend_count = 0;
        memset(hashTable, 0, sizeof(hashTable)); // Reset hash table

        scanf("%d", &F);

        while (F-- > 0) {
            char name1[MAX_NAME_LEN], name2[MAX_NAME_LEN];
            scanf("%s %s", name1, name2);

            int id1 = addOrGetID(name1);
            int id2 = addOrGetID(name2);

            int root1 = findRoot(id1);
            int root2 = findRoot(id2);

            if (root1 != root2) {
                depth[root1] += depth[root2];
                root[root2] = root1;
            }

            printf("%d\n", depth[root1]);
        }

        freeHashTable();
    }

    return 0;
}
