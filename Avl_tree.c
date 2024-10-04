#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
    int height; 
} AVLNode;

// Function prototypes
void createNode(AVLNode** newNode, int key);
void rightRotate(AVLNode** root);
void leftRotate(AVLNode** root);
int getBalance(AVLNode* node);
int height(AVLNode* node);
void insert(AVLNode** node);
AVLNode* minNode(AVLNode* node);
void deleteNode(AVLNode** node);
void display(AVLNode* node);

int main() {
    AVLNode* root = NULL;
    int choice;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(&root); 
                break;
            case 2:
                deleteNode(&root); 
                break;
            case 3:
                display(root); 
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void createNode(AVLNode** newNode, int key) {
    *newNode = (AVLNode*)malloc(sizeof(AVLNode));
    (*newNode)->key = key;
    (*newNode)->left = NULL;
    (*newNode)->right = NULL;
    (*newNode)->height = 1; 
}

int height(AVLNode* node) {
    return node ? node->height : 0;
}

void rightRotate(AVLNode** root) {
    AVLNode* y = *root;
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = height(y->left) > height(y->right) ? height(y->left) + 1 : height(y->right) + 1;
    x->height = height(x->left) > height(x->right) ? height(x->left) + 1 : height(x->right) + 1;

    *root = x;
}

void leftRotate(AVLNode** root) {
    AVLNode* x = *root;
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = height(x->left) > height(x->right) ? height(x->left) + 1 : height(x->right) + 1;
    y->height = height(y->left) > height(y->right) ? height(y->left) + 1 : height(y->right) + 1;

    *root = y;
}

int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

void insert(AVLNode** node) {
    int key;
    printf("Enter value to insert: ");
    scanf("%d", &key);

    if (*node == NULL) {
        createNode(node, key);
        return;
    }

    if (key < (*node)->key)
        insert(&((*node)->left));
    else if (key > (*node)->key)
        insert(&((*node)->right));
    else return; 

    (*node)->height = 1 + (height((*node)->left) > height((*node)->right) ? height((*node)->left) : height((*node)->right));

    int balance = getBalance(*node);

    if (balance > 1 && key < (*node)->left->key) {
        rightRotate(node);
        return;
    }
    
    if (balance < -1 && key > (*node)->right->key) {
        leftRotate(node);
        return;
    }
    
    if (balance > 1 && key > (*node)->left->key) {
        leftRotate(&((*node)->left));
        rightRotate(node);
        return;
    }
    
    if (balance < -1 && key < (*node)->right->key) {
        rightRotate(&((*node)->right));
        leftRotate(node);
        return;
    }
}

AVLNode* minNode(AVLNode* node) {
    AVLNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void deleteNode(AVLNode** node) {
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    if (*node == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (key < (*node)->key) {
        deleteNode(&((*node)->left));
    } else if (key > (*node)->key) {
        deleteNode(&((*node)->right));
    } else {
        if ((*node)->left == NULL) {
            AVLNode* temp = (*node)->right;
            free(*node);
            *node = temp;
        } else if ((*node)->right == NULL) {
            AVLNode* temp = (*node)->left;
            free(*node);
            *node = temp;
        } else {
            AVLNode* temp = minNode((*node)->right);
            (*node)->key = temp->key;
            deleteNode(&((*node)->right));
        }
    }

    if (*node == NULL) return;

    (*node)->height = 1 + (height((*node)->left) > height((*node)->right) ? height((*node)->left) : height((*node)->right));

    int balance = getBalance(*node);

    if (balance > 1 && getBalance((*node)->left) >= 0) {
        rightRotate(node);
        return;
    }
    
    if (balance > 1 && getBalance((*node)->left) < 0) {
        leftRotate(&((*node)->left));
        rightRotate(node);
        return;
    }
    
    if (balance < -1 && getBalance((*node)->right) <= 0) {
        leftRotate(node);
        return;
    }
   
    if (balance < -1 && getBalance((*node)->right) > 0) {
        rightRotate(&((*node)->right));
        leftRotate(node);
        return;
    }
}

void display(AVLNode* node) {
    if (node == NULL) {
        printf("The AVL tree is empty.\n");
        return;
    }

    display(node->left);
    printf("%d ", node->key);
    display(node->right);
    printf("\n"); // Newline for better readability
}
