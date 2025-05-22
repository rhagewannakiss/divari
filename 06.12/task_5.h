#ifndef TASK_5_H_
#define TASK_5_H

//5.	Создать библиотеку для работы с бинарными деревьями
//•	создание бинарного дерева;
//•	печать бинарного дерева (прямой, симметричный и обратный обход);
//•	обход бинарного дерева;
//•	вставка узла в бинарное дерево;
//•	удаление узла из бинарного дерева и его поддерева;
//•	проверка пустоты бинарного дерева;
//•	удаление бинарного дерева.
//•	определение глубины бинарного дерева

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* CreateNode(int data);
TreeNode* InsertNode(TreeNode* root, int data);
TreeNode* DeleteNode(TreeNode* root, int data);

int       IsEmpty(TreeNode* root);
TreeNode* FindMin(TreeNode* root);
void      DeleteTree(TreeNode* root);
int       GetDepth(TreeNode* root);
void      PreOrder(TreeNode* root);
void      InOrder(TreeNode* root);
void      PostOrder(TreeNode* root);
void      PrintTree(TreeNode* root);

#endif //TASK_5_H_