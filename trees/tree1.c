#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

struct node {
    int data ;
    struct node * left ;
    struct node * right ;
};
struct node * root = NULL;
struct node * temp = NULL;

struct node * createNode(int key){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data=key;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node * insert(struct node * root , int key){
    if (root==NULL)return createNode(key);
    
    if(key<root->data){
        root->left=insert(root->left,key);
    }else if(key>root->data){
        root->right=insert(root->right,key);
    }
    return root;
    
}

void inOrderTraversal(struct node * root){
    if (root==NULL) return ;
    inOrderTraversal(root->left);
    printf("%d --> ",root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(struct node * root){
    if (root==NULL) return ;
    printf("%d --> ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct node * root){
    if (root==NULL) return ;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d --> ",root->data);
}

struct node * search(struct node * root ,int key){
    if(root == NULL || root->data==key)return root;
    if(key>root->data){
        return search(root->right,key);
    }else if(key<root->data){
        return search(root->left,key);
    }

}

int findMinimum(struct node * root ){
    if (root == NULL) return -1;  // Check for NULL root
    if(root->left!=NULL)return findMinimum(root->left);
    else if(root->left==NULL)return root->data;
}

int findMaximum(struct node * root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

struct node * inordersucc(struct node * root){
    if (root == NULL) return NULL;  // Check for NULL root
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node * deleteNode(struct node * root , int key){
    if(root==NULL) return root;
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        // Case 1: Node has only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node has two children
        struct node * temp = inordersucc(root->right);  // Get the in-order successor
        if (temp != NULL) {
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        }
return root;
}

int main()

{
int op,key;
do
{
printf("\n.menu\n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.delete\n6.search\n7.Minimum\n8.Maximum\n9.exit\nenter option\n");
scanf("%d",&op);
switch(op)
{
case 1:printf("Enter the key:");
            scanf("%d",&key);
            if (root==NULL)
                root=insert(root,key);
            else
            insert(root,key);
            break;
case 2:printf("Preorder Traversal\n");
           preOrderTraversal(root);
           break;
case 3:printf("Postorder Traversal\n");
           postOrderTraversal(root);
            break;
case 4:
           printf("Inorder traversal\n");
           inOrderTraversal(root);
           break;
case 5:
    printf("Enter the key to delete:");
    scanf("%d",&key);
    root = deleteNode(root, key);
    printf("In-Order Traversal after deleting %d: ", key);
    inOrderTraversal(root);
    break;
case 6:
    printf("Enter the key to search:");
    scanf("%d",&key);
    temp=search(root,key);
    if (temp==NULL)
        printf("Key not Found \n");
    else
        printf("key found \n");
    break;
case 7:printf("Minimum key element is =%d\n",findMinimum(root));
           break;
case 8:printf("Maximum key element is =%d\n",findMaximum(root));
            break;
}
}
while(op!=9);
return 0;
}
