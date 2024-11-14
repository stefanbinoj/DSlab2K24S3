#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data ;
    struct node * left;
    struct node * right;
};

void preorder(struct node * root){
    if(root==NULL)return ;
    printf("%d --> ",root->data);
    preorder(root->left);
    preorder(root->right);

}
void inorder(struct node * root){
    if(root==NULL)return ;
    inorder(root->left);
    printf("%d --> ",root->data);
    inorder(root->right);

}
void postorder(struct node * root){
    if(root==NULL)return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d --> ",root->data);

}

struct node * createNode (int a){
    struct node * temp = (struct node * )malloc(sizeof(struct node));
    temp->data=a;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node * insertLeft(struct node * root , int a){
    root->left=createNode(a);
    return root->left;
}

struct node * insertRight(struct node * root , int a){
    root->right=createNode(a);
    return root->right;
}

int main() {
struct node * root = createNode(50);
insertLeft(root, 20);
insertRight(root, 30);
insertLeft(root->left, 40);
insertRight(root->left, 10);
printf("Inorder traversal \n");
inorder(root);
printf("\nPreorder traversal \n");
preorder(root);
printf("\nPostorder traversal \n");
postorder(root);
}