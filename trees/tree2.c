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

struct ndoe * root = NULL;

void insert(){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter digit \n");
    scanf("%d",&newNode->data);
    newNode->left=NULL;
    newNode->right=NULL;
    if(root==NULL){
        root=newNode;
    }
    else{
        struct node * pre;
        struct node * curr =root ;
        
        while(1){
            pre=curr;
            if(newNode->data<curr->data){
                curr=curr->left;
                if(curr==NULL);pre->left=newNode; break;
            }
            else if(newNode->data>curr->data){
                curr=curr->right;
                if(curr==NULL)curr->right=newNode; break;
            }
            else{
                printf("invalid\n");
                exit(0);
            }
        }
    }
}

void search(){
    printf("Entter value to search  :\n");
    int a ;
    scanf("%d",a);
    int pos=-1;
    int nc=0;
    struct node * temp =root;
    while(temp!=NULL){
        if(a==temp->data)pos=1;break;
        if(a>temp->data)temp=temp->right;
        else{
            temp=temp->left;
        }
        nc++;
    }
    if(pos==-1)printf("Not found");
    else{
        printf("Found in %d  iter",nc);
    }
}

void inorder(struct node * root){
    if (root==NULL)return ;
    inorder(root->left);
    printf("%d -- > ",root->data);
    inorder(root->right);
}

void preorder(struct node * root){
    if (root==NULL)return ;
    printf("%d -- > ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node * root){
    if (root==NULL)return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d -- > ",root->data);
}

int findMinimun(struct node * root){
    if (root==NULL)return -1;
    if(root->left!=NULL)return findMinimun(root->left);
    else if(root->left==NULL) return root->data;
}
int findMaximum(struct node * root){
    while(root->right !=NULL){
        root=root->right;
    }
    return root->data;
}
struct node * insuc(struct node * root){
    while(root->left!=NULL){
        root=root->left;
        
    }
    return root;
}
void delete(){
    printf("Enter value to seach : \n");
    int key ;
    int pos=-1;
    scanf("%d",&key);
    struct node * pre = NULL;
    struct node * trav =root;
    while(trav!=NULL){
    if(key==trav->data)pos=1;break;
    if(key<trav->data){pre=trav ; trav=trav->left;}
    else if(key>trav->data){pre = trav ;trav=trav->right;}}
    if(pos==-1)printf("not fpudn");
    else{
        struct node * curr = trav;
        if(curr->left==NULL && curr->right==NULL){
            if(pre->left==curr)pre->left=NULL;
            if(pre->right==curr)pre->right=NULL;
        }
        else if(curr->left==NULL){
            if(pre->left==curr)pre->left=curr->right;
            if(pre->right==curr)pre->right=curr->right;
        }
        else if(curr->right==NULL){
            if(pre->left==curr)pre->left=curr->left;
            if(pre->right==curr)pre->right=curr->left;
        }
        else{
            struct node * in = curr->right;
            if (in->left == NULL) {
                curr->data = in->data;
                curr->right = in->right;
            }
            else {
                in = insuc(curr->right);
                curr->data = in->data;
            }
        }
    
    }
    
}

int main() {
    int op;
    do {
        printf("\n.menu\n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.delete\n6.search\n7.exit\nenter option\n");
        scanf("%d", &op);
        switch(op) {
            case 1: insert(); break;
            case 2: preorder(root); break;
            case 3: postorder(root); break;
            case 4: inorder(root); break;
            case 5: delete(); break;
            case 6: search(); break;
        }
    } while (op != 7);
}
