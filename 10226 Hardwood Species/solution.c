#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int count;
} Species;

int binarySearch(Species *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        int cmp = strcmp(array[mid].name, key);
        if(cmp == 0)
            return mid;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    int cases;
    scanf("%d ", &cases);
    char buffer[32];
    while(cases--) {
    	Species *tree = NULL;
        int speciesCount = 0;
        while(fgets(buffer, sizeof(buffer), stdin) && buffer[0] != '\n') {
            buffer[strcspn(buffer, "\n")] = '\0';
            int pos = binarySearch(tree, speciesCount, buffer);
            if(pos < speciesCount && strcmp(tree[pos].name, buffer) == 0)
                ++tree[pos].count;
            else {
                tree = (Species*)realloc(tree, (speciesCount + 1) * sizeof(Species));
                for(int i = speciesCount++; i > pos; --i)
                    tree[i] = tree[i - 1];
                tree[pos].name = strdup(buffer);
                tree[pos].count = 1;
            }
        }
        int treeSize = 0;
        for(int i = 0; i < speciesCount; ++i)
            treeSize += tree[i].count;
        for(int i = 0; i < speciesCount; ++i) {
            printf("%s %.4f\n", tree[i].name, 100.0 * tree[i].count / treeSize);
            free(tree[i].name);
        }
        free(tree);
        if(cases)
    		putchar('\n');
    }
    return 0;
}
