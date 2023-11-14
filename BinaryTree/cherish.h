#pragma once
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct TreeNode* createBinaryTree() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    return root;
}


void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}


void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}


void freeBinaryTree(struct TreeNode* root) {
    if (root != NULL) {
        freeBinaryTree(root->left);
        freeBinaryTree(root->right);
        free(root);
    }
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printBinaryTree(struct TreeNode* root, int space) {
 
    if (root == NULL) {
        return;
    }

    space += 5;

    printBinaryTree(root->right, space);

    printf("\n");
    printSpaces(space);
    printf("%d\n", root->data);

    printBinaryTree(root->left, space);
}

struct TreeNode* createBinaryTreeManual() {
    int data;
    printf("输入根节点数据（-1 表示空节点）: ");
    scanf_s("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct TreeNode* root = createNode(data);

    printf("输入节点 %d 的左子节点数据（-1 表示空节点）: ", data);
    root->left = createBinaryTreeManual();

    printf("输入节点 %d 的右子节点数据（-1 表示空节点）: ", data);
    root->right = createBinaryTreeManual();

    return root;
}
