 #include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    struct ListNode* twohead = head; //"segunda" cabeça
    struct ListNode* threehead = head; //"terceira" cabeça
    int tam = 1; //tamanho da lista

    if (head == NULL || head->next == NULL || k == 0){
        return head;
    } //Teste para ver se não está vazia;
    
    while (threehead->next) {
        threehead = threehead->next;
        tam++;
    } //descobrindo o tamanho da lista

    k = k % tam; //resto da divisão
    if(k == 0){
        return head;
    }

    for(int i = 0; i < k; i++){ 
        struct ListNode *anterior, *atual;
        anterior = twohead; //anterior vira a cabeça
        atual = twohead->next; //atual vira o próximo da cabeça

        while(atual->next != NULL){
           anterior = atual; //percorrendo a lista
           atual = atual->next; //atual aponta para o proximo
        }

        anterior->next = NULL; //corto o ultimo nó
        atual->next = twohead; // faço o ultimo elemento apontar para cabeça
        twohead = atual; // faço a cabeça virar esse elemento

    }
    return twohead;
}

struct ListNode* create_list(const int *vals, int n) {
    if (n <= 0) return NULL;
    struct ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; ++i) {
        struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
        if (!node) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        node->val = vals[i];
        node->next = NULL;
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

//* cria lista encadeada a partir de um array (aloca com malloc) */
struct ListNode* createList(const int *arr, int n) {
    if (n <= 0) return NULL;
    struct ListNode *head = malloc(sizeof(struct ListNode));
    if (!head) { perror("malloc"); exit(EXIT_FAILURE); }
    head->val = arr[0];
    head->next = NULL;
    struct ListNode *cur = head;
    for (int i = 1; i < n; ++i) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        if (!node) { perror("malloc"); exit(EXIT_FAILURE); }
        node->val = arr[i];
        node->next = NULL;
        cur->next = node;
        cur = node;
    }
    return head;
}

/* imprime a lista de forma segura (usa %d para int) */
void printList(const struct ListNode *head) {
    const struct ListNode *p = head;
    while (p) {
        printf("%d", p->val);
        if (p->next) printf(" -> ");
        p = p->next;
    }
    printf("\n");
}

/* libera a lista (evita memory leaks) */
void freeList(struct ListNode *head) {
    while (head) {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
}

/* main de teste — altere arr/k conforme precisar */
int main(void) {
    int arr[] = {1, 2, 3, 4, 5}; /* exemplo do LeetCode 61 */
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    struct ListNode *head = createList(arr, n);

    printf("Original: ");
    printList(head);

    struct ListNode *rot = rotateRight(head, k);

    printf("Rotated by %d: ", k);
    printList(rot);

    freeList(rot);
    return 0;
}