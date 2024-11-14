#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node {
    int data , priority;
    struct node * next;
};
struct node * head = NULL;

void insert(int a , int p){
    struct node * temp = (struct node * )malloc(sizeof(struct node));
    if(head==NULL || head->priority<p){
        temp->data =a ;
        temp->next = head;
        head =temp;
    }
    else{
        struct  node * trav = head;
        while(trav->next != NULL && trav->priority<=p){
            trav=trav->next;
        }
        temp->data=a;
        temp->next=trav->next;
        trav->next=temp;
        
    }
}

void delete(){
     struct node* temp = head;
        printf("Deleted item: %d\n", temp->data);
        head = head->next;
        free(temp);
}
void display(){
    struct  node * trav = head;
        while(trav->next!=NULL){
            printf("%d --> ",trav->data);
            trav=trav->next;
        }
       
}

int main() {
    
    insert(4, 2);
    insert(2, 3);
    insert(5, 4);
    insert(3, 1);
    insert(1, 5);
    display();
    delete();
    display();
    return 0;
}