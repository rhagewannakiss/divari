#include "task_5.h"

#include <stdio.h>
#include <stdlib.h>

TreeNode* DeleteNodeWithoutSubtree(TreeNode* root, int data);

//6.	удаление узла из бинарного дерева без удаления его поддерева;


int main() {
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

    root = DeleteNodeWithoutSubtree(root, 30);

    printf("Tree after deleting node 30 (without subtree):\n");

    PrintTree(root);

    DeleteTree(root);

    printf("Tree deleted.\n");

    return 0;
}

TreeNode* DeleteNodeWithoutSubtree(TreeNode* root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNodeWithoutSubtree(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNodeWithoutSubtree(root->right, data);
    }
    else {
        TreeNode* temp = root->right ? root->right : root->left;

        free(root);

        return temp;
    }

    return root;
}
