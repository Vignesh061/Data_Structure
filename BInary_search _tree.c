#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
void insert(struct Node** node);
void search(struct Node* root);
void deleteNode(struct Node** root);
void inorder(struct Node* root);
void preorder(struct Node* root);
void postorder(struct Node* root);
void display(struct Node* root);

// Main function
int main() {
    struct Node* root = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Display Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(&root);  // Calls insert
                break;
            case 2:
                search(root);  // Calls search
                break;
           // case 3:
           //     deleteNode(&root);  // Calls deleteNode
                break;
            case 4:
                inorder(root);  // Calls inorder
                break;
            case 5:
                preorder(root);  // Calls preorder
                printf("\n");
                break;
            case 6:
                postorder(root);  // Calls postorder
                printf("\n");
                break;
            case 7:
                display(root);  // Calls display
                printf("\n");
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

// Insert function
void insert(struct Node** node) {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (*node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        *node = newNode;  // Set the new node
    } else {
        if (value < (*node)->data) {
            insert(&((*node)->left));  // Recur left
        } else {
            insert(&((*node)->right));  // Recur right
        }
    }
}

// Search function
void search(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);

    struct Node* current = root;
    while (current != NULL) {
        if (value == current->data) {
            printf("Value %d found in the tree.\n", value);
            return;
        } else if (value < current->data) {
            current = current->left;  // Move left
        } else {
            current = current->right;  // Move right
        }
    }
    
    printf("Value %d not found in the tree.\n", value);
}


// In-order traversal function
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);  // Print data during traversal
        inorder(root->right);
    }
    printf("\n");  // Print newline after in-order traversal
}

// Pre-order traversal function
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Print data during traversal
        preorder(root->left);        // Recur left
        preorder(root->right);       // Recur right
    }
}

// Post-order traversal function
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);       // Recur left
        postorder(root->right);      // Recur right
        printf("%d ", root->data);   // Print data during traversal
    }
    printf("\n");  // Print newline after post-order traversal
}

// Display function to show the current state of the tree
void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);         // Recur left
        printf("%d ", root->data);   // Print the current node
        display(root->right);        // Recur right
    }
}
