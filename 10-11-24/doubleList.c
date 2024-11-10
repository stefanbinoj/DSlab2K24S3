#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data ; 
    struct node * prev;
    struct node * next;
};
struct node * front = NULL;
struct node * rear = NULL;
int n ;
bool isEmpty(){
    return front == NULL;
}

void insertFront(){
    printf("Enter data to add to front ");
    scanf("%d",&n);
    struct node * temp = (struct node * ) malloc(sizeof (struct node ));
    temp->data=n;
    temp->prev=NULL;
    temp->next = NULL;
    if(front==NULL){
        front = temp;
        rear = temp;
    }
    else {
        temp->next = front ;
        front ->prev = temp;
        front = temp;
    }
}
void insertBack(){
    printf("Enter data to add to front ");
    scanf("%d",&n);
    struct node * temp = (struct node * ) malloc(sizeof (struct node ));
    temp->data=n;
    temp->prev=NULL;
    temp->next = NULL;
    if(front==NULL){
        front = temp;
        rear = temp;
    }
    else {
        temp->prev = rear ;
        rear ->next = temp;
        rear = temp;
    }
}

int deleteFront(){
    struct node * temp = (struct node * ) malloc(sizeof (struct node ));
    temp=front;
    if(temp==NULL){
        printf("Nothig to felete \n");
        return -1;
    }
    else {
        int data = front->data;
        front = temp->next ;
        if(front==NULL){
            rear=NULL;
        }
        front ->prev = NULL;
        temp->next = NULL;
        return data;

    }

}
int deleteBack(){
    struct node * temp = (struct node * ) malloc(sizeof (struct node ));
    temp=rear;
    if(temp==NULL){
        printf("Nothig to felete \n");
        return -1;
    }
    else {
        int data = rear->data;
        rear = temp->prev ;
        if(rear==NULL){
            front=NULL;
        }
        rear ->next = NULL;
        temp->prev = NULL;
        return data;
    }

}

void display(){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp=front;
    while(temp!=NULL){
        printf("%d --> ",temp->data);
        temp=temp->next;
    }
}

int main() 
{
     int choice,item;
        while(1)
        {
                printf("\n\n1.Insert at the front end\n");
                printf("2.Insert at the rear end\n");
                printf("3.Delete from front end\n");
                printf("4.Delete from rear end\n");
                printf("5.Display\n");
                printf("6.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
 
                switch(choice)
                {
                case 1:
                        
                        insertFront();
                        break;
                case 2:
                        
                        insertBack();
                        break;
                 case 3:
                        item=deleteFront();
                        if(item!=-1)
                        printf("\nElement deleted from front end is : %d\n",item);
                        break;
                 case 4:
                        item=deleteBack();
                        if(item!=-1)
                        printf("\nElement deleted from rear end is : %d\n",item);
                        break;
                 case 5:
                        display();
                        break;
                 case 6:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }/*End of switch*/
               
        }/*End of while*/
}