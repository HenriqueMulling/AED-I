#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    
    if (root == NULL) { //testamos pra ver se root é vazia
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); //alocamos memoria para esse novo valor (nó)
        newNode->val = val; 
        newNode->left = NULL; // novo nó começa tudo em NULL
        newNode->right = NULL;
        return newNode;
    }

    
    if (val > root->val) { // Se o val for maior que o atual, iserimos na direita
        root->right = insertIntoBST(root->right, val);
    } else { // Se o val for menor inserimos na esquerda
        root->left = insertIntoBST(root->left, val);
    }

    return root; //retorna a root
}

//////////////////////////////////////////////////////////////////////////

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

void printInOrder(struct TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->val);
        printInOrder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 7);

    printf("Arvore antes da nova insercao (In-order): ");
    printInOrder(root);
    printf("\n");

    int novoValor = 5;
    root = insertIntoBST(root, novoValor);

    printf("Arvore apos inserir o %d (In-order): ", novoValor);
    printInOrder(root);
    printf("\n");

    // LIBERANDO A MEMÓRIA ANTES DE SAIR
    freeTree(root);

    return 0;
}