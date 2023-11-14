#include "cherish.h"
#include <stdio.h>

void displayMenu() {
    printf("\n======== 二叉树操作菜单 ========");
    printf("\n1. 创建二叉树（示例数据）");
    printf("\n2. 手动输入二叉树数据");
    printf("\n3. 前序遍历");
    printf("\n4. 中序遍历");
    printf("\n5. 后序遍历");
    printf("\n6. 打印二叉树");
    printf("\n7. 退出程序");
    printf("\n请输入菜单选项： ");
}

int main() {
    struct TreeNode* root = NULL;
    int choice = 0; 

    do {
        displayMenu();
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:

            if (root != NULL) {
                printf("\n二叉树已经存在，请先释放内存再创建新的二叉树。\n");
            }
            else {
                root = createBinaryTree();
                printf("\n二叉树创建成功。\n");
            }
            break;

        case 2:

            if (root != NULL) {
                printf("\n二叉树已经存在，请先释放内存再手动输入数据。\n");
            }
            else {
                printf("\n请按照前序顺序输入二叉树数据（输入-1表示空节点）：\n");
                root = createBinaryTreeManual();
                printf("\n手动输入数据成功。\n");
            }
            break;

        case 3:

            if (root == NULL) {
                printf("\n请先创建二叉树。\n");
            }
            else {
                printf("\n前序遍历结果：");
                preOrderTraversal(root);
                printf("\n");
            }
            break;

        case 4:

            if (root == NULL) {
                printf("\n请先创建二叉树。\n");
            }
            else {
                printf("\n中序遍历结果：");
                inOrderTraversal(root);
                printf("\n");
            }
            break;

        case 5:

            if (root == NULL) {
                printf("\n请先创建二叉树。\n");
            }
            else {
                printf("\n后序遍历结果：");
                postOrderTraversal(root);
                printf("\n");
            }
            break;

        case 6:

            if (root == NULL) {
                printf("\n请先创建二叉树。\n");
            }
            else {
                printf("\n二叉树结构：\n");
                printBinaryTree(root, 0);
                printf("\n");
            }
            break;

        case 7:

            printf("\n程序已退出。\n");
            break;

        default:
            printf("\n无效的菜单选项，请重新输入。\n");
        }

    } while (choice != 7);


    freeBinaryTree(root);

    return 0;
}
