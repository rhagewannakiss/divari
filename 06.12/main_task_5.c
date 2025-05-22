#include "task_5.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    TreeNode* root = NULL;

    root = InsertNode(root, 50);
    root = InsertNode(root, 30);
    root = InsertNode(root, 70);
    root = InsertNode(root, 20);
    root = InsertNode(root, 40);
    root = InsertNode(root, 60);
    root = InsertNode(root, 80);

    printf("Binary Tree:\n");
    PrintTree(root);

    printf("Tree Depth: %d\n", GetDepth(root));

    root = DeleteNode(root, 50);
    printf("Tree after deleting node 50:\n");
    PrintTree(root);

    DeleteTree(root);
    printf("Tree deleted.\n");

    return 0;
}
