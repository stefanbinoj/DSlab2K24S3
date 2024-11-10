#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 50
int que[MAX];
int front =-1,rear=-1;

bool isEmpty(){
    return front==-1;
}
bool isFull(){
    return (rear+1)%MAX==front;
}
void insert(){
    int n;
    if(isFull()){
        printf("Fukl");
        return ;
    }
    printf("Enter : \n");
    scanf("%d",&n);
    if(isEmpty()){
        front=rear=1;
        que[rear]=n;
    }
    else{
        rear = (rear+1)%MAX;
        que[rear]=n;
    }

}

int peek(){
    if (isEmpty())return -1;
    return (que[rear]);
}

int delete(){
    if(isEmpty()){
        printf("Underflow\n");
        return -1;
    }
    
    else{
        printf("Element deleted is : %d \n",que[front]);
        if(front = rear){
            front=rear=-1;
        }
        else{
            front = (front+1)%MAX;
            

        }
    }
}

void display(){
    if(isEmpty()){
        printf("Underflow \n");
        return ;
    }
    if(rear==front) printf(que[rear]);
    else { 
    for(int i =front ; i!=rear ; i=(i+1)%MAX){
        printf("%d --> ",que[i]);
    }
    }
}

int main(){
    int choice;
    while (1){
    printf("\n1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of queue \n");
    printf("4.Peek \n");
    printf("5.Size of the queue\n");
    printf("6.Quit \n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice){
case 1:
    insert();
    break;
case 2:
    delete();
    break;
case 3:
    display();
    break;
case 4:
    int x=peek();
    if(x!=-1) printf("\nfront element is=%d\n",x);
    break;
case 6:
    exit(1);

default:

printf("\nWrong choice \n");
}
}
}