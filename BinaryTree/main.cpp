#include "cherish.h"
#include <stdio.h>

void displayMenu() {
    printf("\n======== �����������˵� ========");
    printf("\n1. ������������ʾ�����ݣ�");
    printf("\n2. �ֶ��������������");
    printf("\n3. ǰ�����");
    printf("\n4. �������");
    printf("\n5. �������");
    printf("\n6. ��ӡ������");
    printf("\n7. �˳�����");
    printf("\n������˵�ѡ� ");
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
                printf("\n�������Ѿ����ڣ������ͷ��ڴ��ٴ����µĶ�������\n");
            }
            else {
                root = createBinaryTree();
                printf("\n�����������ɹ���\n");
            }
            break;

        case 2:

            if (root != NULL) {
                printf("\n�������Ѿ����ڣ������ͷ��ڴ����ֶ��������ݡ�\n");
            }
            else {
                printf("\n�밴��ǰ��˳��������������ݣ�����-1��ʾ�սڵ㣩��\n");
                root = createBinaryTreeManual();
                printf("\n�ֶ��������ݳɹ���\n");
            }
            break;

        case 3:

            if (root == NULL) {
                printf("\n���ȴ�����������\n");
            }
            else {
                printf("\nǰ����������");
                preOrderTraversal(root);
                printf("\n");
            }
            break;

        case 4:

            if (root == NULL) {
                printf("\n���ȴ�����������\n");
            }
            else {
                printf("\n������������");
                inOrderTraversal(root);
                printf("\n");
            }
            break;

        case 5:

            if (root == NULL) {
                printf("\n���ȴ�����������\n");
            }
            else {
                printf("\n������������");
                postOrderTraversal(root);
                printf("\n");
            }
            break;

        case 6:

            if (root == NULL) {
                printf("\n���ȴ�����������\n");
            }
            else {
                printf("\n�������ṹ��\n");
                printBinaryTree(root, 0);
                printf("\n");
            }
            break;

        case 7:

            printf("\n�������˳���\n");
            break;

        default:
            printf("\n��Ч�Ĳ˵�ѡ����������롣\n");
        }

    } while (choice != 7);


    freeBinaryTree(root);

    return 0;
}
