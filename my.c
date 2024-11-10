#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node * l;
    struct node * r ;
    
} ; 
struct node * root = NULL;

struct node * create(val){
    struct node * temp = (struct node * )malloc(sizeof(struct node));
    temp->l = temp->r=NULL;
    temp->key=val;
    return temp;
}

struct node  *  insert(struct node *  node ,int  val){
    if(node==NULL){
        return create(val);
    }
    else if(val<node->key){
        node->l =insert(node->l,val);
    }
    else {
        node->r = insert(node->r,val);
    }
    return node;
}

void inorder(struct node * node){
    if(node!=NULL){
    inorder(node->l);
    printf("%d--",node->key);
    inorder(node->r);
    }
}

struct node  * search(struct node * node , int key){
    if(node->key == key || node == NULL){
        return node;
    }
    else if (node->key<key){
        return search (node->r,key);    }
    else{
        return search(node->l,key);
    }




}

struct node * delete (struct node * node , int val){

}