#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int coeff , exp;
    struct node *  next;
};

struct node * head1 = NULL;
struct node * head2 = NULL;

struct node * tail1 = NULL;
struct node * tail2 = NULL;

struct node * head3 = NULL;
struct node * tail3 = NULL;

void createpoly (struct node ** head ,struct node **tail, int n){
    for(int i = 0 ; i<n ; i++){
        struct node * temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coeff and exp : \n");
        scanf("%d",&temp->coeff);
        scanf("%d",&temp->exp);
        if(*head == NULL){
            *head=*tail=temp;
        }
        else{
            (*tail)->next=temp;
            *tail=temp;
        }
    }
    
}

void display(struct node **head){
    struct node * temp = *head;
    while((temp)!=NULL){
        if(!(temp==*head)){
            printf(" + ");
        }
        printf("%d ^^ %d",(temp)->coeff,(temp)->exp);
        temp=temp->next;
    }
    printf("\n");
}

void polyadd(struct node ** head1 ,struct node ** head2){
    struct node * temp1 = *head1;
    struct node * temp2 = *head2;
    while(temp1!=NULL || temp2!=NULL){
        struct node * temp = (struct node * )malloc(sizeof(struct node));
        if(temp1 != NULL && temp2 != NULL && temp1->exp == temp2->exp){
            if(head3==NULL){
                head3=tail3=temp;
                temp->coeff=temp1->coeff+temp2->coeff;
                temp->exp=temp1->exp;
                temp->next=NULL;
            }
            else{
                tail3->next=temp;
                tail3=temp;
                temp->coeff=temp1->coeff+temp2->coeff;
                temp->exp=temp1->exp;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1 != NULL && (temp2 == NULL || temp1->exp > temp2->exp)){
            if(head3==NULL){
                head3=tail3=temp;
                temp->coeff=temp1->coeff;
                temp->exp=temp1->exp;
                temp->next=NULL;
            }
            else{
                tail3->next=temp;
                tail3=temp;
                temp->coeff=temp1->coeff;
                temp->exp=temp1->exp;
                temp->next=NULL;
            }
            temp1=temp1->next;
        }
        else if (temp2 != NULL && (temp1 == NULL || temp2->exp > temp1->exp)){
            if(head3==NULL){
                head3=tail3=temp;
                temp->coeff=temp2->coeff;
                temp->exp=temp2->exp;
                temp->next=NULL;
            }
            else{
                tail3->next=temp;
                tail3=temp;
                temp->coeff=tail2->coeff;
                temp->exp=tail2->exp;
                temp->next=NULL;
            }
            temp2=temp2->next;
        }
    }
}

int main(){
    int n1,n2;
    printf("Enter terms of Poly 1 : \n");
    scanf("%d",&n1);
    printf("Enter terms of Poly 2 : \n");
    scanf("%d",&n2);

    printf("Creating Poly1 : \n");
    createpoly(&head1,&tail1,n1);

    printf("Creating Poly2 : \n");
    createpoly(&head2,&tail2,n2);

    printf("The poly 1 is like : \n");
    display(&head1);


    printf("The poly 2 is like : \n");
    display(&head2);


    polyadd(&head1,&head2);

    
    printf("SUm is like : \n");
    display(&head3);



    return 0;
    
}
