#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

int dqueue[MAX];
int front =-1;
int rear =-1;

void InsertFront();
void InsertRear();
void DeleteFront();
void DeleteRear();
void Display();
bool IsFull();
bool IsEmpty();

bool IsFull(){
    return( (front==0 && rear==MAX-1) || (front==rear+1) );
}

bool IsEmpty(){
    return (front==-1);
}

void InsertFront(){
    if(IsFull()){
        printf("The queue is full\n");
        return;
    }
    printf("\nEnter the digit to Insert at Front  : ");
    int  n; 
    scanf("%d",&n);
    if(IsEmpty()){
        rear=front=0;
    }
    else if (front==0){
        front=MAX-1;
    }
    else{
        front=front-1;
    }
    dqueue[front]=n;

}

void InsertRear(){
    if(IsFull()){
        printf("The queue is full\n");
        return;
    }
    printf("\nEnter the digit to Insert at Front  : ");
    int  n; 
    scanf("%d",&n);
    if(IsEmpty()){
        rear=front=0;
    }
    else if (rear==MAX-1){
        rear=0;
    }
    else{
        rear=rear+1;
    }
    dqueue[rear]=n;
}

void DeleteFront(){
    if(IsEmpty()){
        printf("The queue is empty \n");
        return;
    }
    int item = dqueue[front];
    printf("The elment deleted is %d",item);
    if(front==MAX-1)front=0;
    else if(front==rear)front=rear=-1;
    else front=front+1;

}

void DeleteRear(){
    if(IsEmpty()){
        printf("The queue is empty \n");
        return;
    }
    int item = dqueue[rear];
    printf("The elment deleted is %d",item);
    if(rear==0)rear=MAX-1;
    else if(front==rear)front=rear=-1;
    else rear=rear-1;
}

void Display(){
    if(IsEmpty()){
        printf("The queue is empty \n");
        return;
    }
    printf("\nQueue elements :\n");
    int i=front;
    if( front<=rear )
    {
            while(i<=rear)
                    printf("%d --> ",dqueue[i++]);
    }
    else
    {
            while(i<=MAX-1)
                    printf("%d --> ",dqueue[i++]);
            i=0;
            while(i<=rear)
                    printf("%d -->",dqueue[i++]);
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("\n\nEnter the Choice pls : \n");
        printf("1.InsertFront\n");
        printf("2.InsertRear\n");
        printf("3.DeleteFront\n");
        printf("4.DeleteRear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            InsertFront();
            break;
         case 2:
            InsertRear();
            break;
         case 3:
            DeleteFront();
            break;
         case 4:
            DeleteRear();
            break;
         case 5:
            Display();
            break;
         case 6:
            exit(1);
            break;
        
        
        default:
            printf("Enter a valid option pls \n");
            break;
        }
        printf("\nfront = %d, rear =%d\n", front , rear);
        Display();
    }
}

