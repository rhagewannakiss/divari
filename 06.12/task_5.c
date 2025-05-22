#include "task_5.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


TreeNode* CreateNode(int data)
{
    assert(data != NULL);

    TreeNode* node = (TreeNode*)calloc(1, sizeof(TreeNode));
    assert(node != NULL);

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}ё

int IsEmpty(TreeNode* root)
{
    return root == NULL;
}

TreeNode* InsertNode(TreeNode* root, int data)
{
    assert(data != NULL);

    if (root == NULL)
    {
        return CreateNode(data);
    }

    if (data < root->data)
    {
        root->left = InsertNode(root->left, data);
    }
    else
    {
        root->right = InsertNode(root->right, data);
    }

    return root;
}

TreeNode* FindMin(TreeNode* root)
{
    assert(root != NULL);

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

TreeNode* DeleteNode(TreeNode* root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = DeleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = DeleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            TreeNode* temp = root->right;

            free(root);

            return temp;

        }
        else if (root->right == NULL)
        {
            TreeNode* temp = root->left;

            free(root);

            return temp;
        }

        TreeNode* temp = FindMin(root->right);
        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data);
    }

    return root;
}

int GetDepth(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = GetDepth(root->left);
    int rightDepth = GetDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

void PreOrder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);

    return;
}

void InOrder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);

    return;
}

void PostOrder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);

    return;
}


void PrintTree(TreeNode* root) {
    assert(root != NULL);

    printf("In-order: ");
    InOrder(root);

    printf("\nPre-order: ");
    PreOrder(root);

    printf("\nPost-order: ");
    PostOrder(root);

    printf("\n");

    return;
}

void DeleteTree(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    DeleteTree(root->left);
    DeleteTree(root->right);
    free(root);

    return;
}