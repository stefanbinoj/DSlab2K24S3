#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * root = NULL;

void insert() {
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter digit: \n");
    scanf("%d", &newNode->data);
    newNode->left = NULL;
    newNode->right = NULL;
    
    if (root == NULL) {
        root = newNode;
    } else {
        struct node * pre;
        struct node * curr = root;
        
        while (1) {
            pre = curr;
            if (newNode->data < curr->data) {
                curr = curr->left;
                if (curr == NULL) {
                    pre->left = newNode; 
                    break;
                }
            } else if (newNode->data > curr->data) {
                curr = curr->right;
                if (curr == NULL) {
                    pre->right = newNode;
                    break;
                }
            } else {
                printf("Invalid input: Duplicate values not allowed.\n");
                exit(0);
            }
        }
    }
}

void search() {
    printf("Enter value to search: \n");
    int a;
    scanf("%d", &a);
    
    int pos = -1;
    int nc = 0;
    struct node * temp = root;
    
    while (temp != NULL) {
        nc++;
        if (a == temp->data) {
            pos = 1;
            break;
        }
        if (a > temp->data) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    
    if (pos == -1) {
        printf("Not found\n");
    } else {
        printf("Found in %d comparisons\n", nc);
    }
}

void inorder(struct node * root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d --> ", root->data);
    inorder(root->right);
}

void preorder(struct node * root) {
    if (root == NULL) return;
    printf("%d --> ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node * root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d --> ", root->data);
}

int findMinimum(struct node * root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1;  // Return a suitable value or error code
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMaximum(struct node * root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// In-order successor function
struct node * inOrderSuccessor(struct node * root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

void delete() {
    printf("Enter value to delete: \n");
    int key;
    scanf("%d", &key);
    
    struct node * pre = NULL;
    struct node * trav = root;
    
    // Find the node to delete
    while (trav != NULL) {
        if (key == trav->data) break;
        pre = trav;
        if (key < trav->data) {
            trav = trav->left;
        } else {
            trav = trav->right;
        }
    }
    
    if (trav == NULL) {
        printf("Key not found\n");
        return;
    }
    
    struct node * curr = trav;
    
    // Case 1: Node to be deleted has no children (leaf node)
    if (curr->left == NULL && curr->right == NULL) {
        if (pre == NULL) {
            root = NULL;  // Root node is being deleted
        } else if (pre->left == curr) {
            pre->left = NULL;
        } else {
            pre->right = NULL;
        }
        free(curr);
    }
    // Case 2: Node to be deleted has one child (either left or right child)
    else if (curr->left == NULL) {
        if (pre == NULL) {
            root = curr->right;  // Root node is being deleted
        } else if (pre->left == curr) {
            pre->left = curr->right;
        } else {
            pre->right = curr->right;
        }
        free(curr);
    }
    else if (curr->right == NULL) {
        if (pre == NULL) {
            root = curr->left;  // Root node is being deleted
        } else if (pre->left == curr) {
            pre->left = curr->left;
        } else {
            pre->right = curr->left;
        }
        free(curr);
    }
    // Case 3: Node to be deleted has two children
    else {
        struct node * in = curr->right;
        
        // Find the in-order successor
        struct node * succParent = curr;
        while (in->left != NULL) {
            succParent = in;
            in = in->left;
        }
        
        // Copy the in-order successor's data to the current node
        curr->data = in->data;
        
        // Delete the in-order successor
        if (succParent->left == in) {
            succParent->left = in->right;
        } else {
            succParent->right = in->right;
        }
        free(in);
    }
}

int main() {
    int op;
    do {
        printf("\nMenu\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder\n5.Delete\n6.Search\n7.Exit\nEnter option: ");
        scanf("%d", &op);
        switch (op) {
            case 1: insert(); break;
            case 2: preorder(root); break;
            case 3: postorder(root); break;
            case 4: inorder(root); break;
            case 5: delete(); break;
            case 6: search(); break;
            case 7: break;
            default: printf("Invalid option!\n");
        }
    } while (op != 7);
    
    return 0;
}
