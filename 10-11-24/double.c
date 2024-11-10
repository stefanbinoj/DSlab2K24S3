#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 50
int que[MAX];
int front =-1,rear=-1;

bool isEmpty(){
    return front==-1 ;
}
bool isFull(){
    return (front ==0 && rear == MAX-1 || front == rear-1);   
}
void insertFront(){
    int n;
    if(isFull()){
        printf("Fukl");
        return ;
    }
    printf("Enter : \n");
    scanf("%d",&n);
    if(isEmpty()){
        front=rear=0;
    }
    else if(front==0){
        front = MAX-1;
    }
    else{
        front = front -1;
    }
    que[front]=n;


}
void insertBack(){
    int n;
    if(isFull()){
        printf("Fukl");
        return ;
    }
    printf("Enter : \n");
    scanf("%d",&n);
    if(isEmpty()){
        front=rear=0;
    }
    else if(rear==MAX-1){
        rear = 0;
    }
    else{
        rear = rear + 1;
    }
    que[rear]=n;


}
int deleteFront(){
    if(isEmpty()){
        printf("Emptyy");
        return -1;
    }
    int item = que[front];
    if(front==rear){
        front=rear=-1;
    }
    else if(front==MAX-1){
        front = 0;
    }
    else{
        front = front +1 ;
    }
    return item;


}
int deleteBack(){
    if(isEmpty()){
        printf("Emptyy");
        return -1;
    }
    int item = que[rear];
    if(front==rear){
        front=rear=-1;
    }
    else if(rear==0){
        front = MAX-1;
    }
    else{
        rear = rear - 1 ;
    }
    return item;


}


void display(){
    if(isEmpty()){
        printf("Underflow \n");
        return ;
    }
    int i=front;
    if( front<=rear ){
        while(i<=rear)
                printf("%d ",que[i++]);
        }
    else{
        while(i<=MAX-1)
                printf("%d ",que[i++]);
                i=0;
        while(i<=rear)
                printf("%d ",que[i++]);
        }
        printf("\n");
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
                        printf("\nInput the element for adding in queue : ");
                        insertFront();
                        break;
                case 2:
                        printf("\nInput the element for adding in queue : ");
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
                printf("\nfront = %d, rear =%d\n", front , rear);
                display();
        }/*End of while*/
}