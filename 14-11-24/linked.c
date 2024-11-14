#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data ;
    struct node * next;
};

struct node * createList(struct node ** head , int n ){
    struct node * tail = NULL;
    
    for(int i=0;i<n;i++){
        printf("Enter : \n");
        int a ;
        scanf("%d",&a);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data=a;
        temp->next=NULL;
        if(*head==NULL){
            *head = tail =temp;
            
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    return tail;
}

void display(struct node ** head){
    struct node * temp = *head;
    while(temp!=NULL){
        printf("%d -->",temp->data);
        temp=temp->next;
    }
    printf(" NULL\n");
}

void createAndDisplay(struct node ** head1,struct node ** head2,struct node **head3,int n){
    struct node * temp1 = *head1;
    struct node * temp2 = *head2;
    struct node * tail = NULL;

    for(int i=0;i<n;i++){
        struct node * temp = (struct node * )malloc(sizeof(struct node));
        if(i%2!=0 && temp1!=NULL){
            temp->data=temp1->data;
            if(*head3==NULL){
                *head3=tail=temp;
            }else{
                tail->next=temp;
                tail=temp;
            }
            temp1=temp1->next;
        }
        else if(i%2==0 && temp2!=NULL){
            temp->data=temp2->data;
            if(*head3==NULL){
                *head3=tail=temp;
            }else{
                tail->next=temp;
                tail=temp;
            }
        temp2=temp2->next;
        }
    }
    display(head3);
}

int main(){
    struct node * head1=NULL;
    struct node * head2=NULL;
    struct node * head3=NULL;
    int n1,n2;
    printf("Enter no of element of 1st : \n");
    scanf("%d",&n1);
    struct node * tail1 = createList(&head1,n1);

    printf("Enter no of element of 2st : \n");
    scanf("%d",&n2);
    struct node * tail2 = createList(&head2,n2);

    printf("First is : \n");
    display(&head1);

    printf("second is : \n");
    display(&head2);

    int n = n1+n2;
    createAndDisplay(&head1,&head2,&head3,n);
    
    return 0;
}

