#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int count;
} Species;

int binarySearch(Species *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
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
    scanf("%d", &cases);
    getchar();
    getchar();
    bool firstCase = true;
    while(cases--) {
    	if(!firstCase)
    		puts("");
    	Species *tree = NULL;
    	char *buffer = NULL;
    	size_t bufsize = 0;
        int speciesCount = 0;
        while(getline(&buffer, &bufsize, stdin) != -1 && strcmp(buffer, "\n") != 0) {
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
        free(buffer);
        int treeSize = 0;
        for(int i = 0; i < speciesCount; ++i)
            treeSize += tree[i].count;
        for(int i = 0; i < speciesCount; ++i) {
            printf("%s %.4f\n", tree[i].name, 100.0 * tree[i].count / treeSize);
            free(tree[i].name);
        }
        free(tree);
        firstCase = false;
    }
    return 0;
}
