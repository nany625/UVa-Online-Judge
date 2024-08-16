#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left, *right;
} TreeNode;

TreeNode *createNode(int data) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode *insertNode(TreeNode *root, int data) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(!root)
        return createNode(data);
    if(root->data > data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

void postorderTraversal(TreeNode *root) {
    if(root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\n", root->data);
        free(root);
    }
}

int main() {
    TreeNode *root = NULL;
    int num;
    while(scanf("%d", &num) == 1)
        root = insertNode(root, num);
    postorderTraversal(root);
    return 0;
}
