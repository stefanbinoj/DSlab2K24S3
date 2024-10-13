#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front=0;
int rear=-1;

bool IsEmpty(){
    return front>rear;
}

bool IsFull(){
    return rear==MAX_SIZE-1;
}

void Push(){
    if(rear==MAX_SIZE-1){
        printf("Queue Overflow \n");
        return ;
    }
    int n;
    printf("Enter the element to push : ");
    scanf("%d",&n);
    rear++;
    queue[rear]=n;
}
void Pop(){
     if(front>rear){
        printf("Queue Underflow \n");
        return ;
    }
    front++;
    printf("Element popped\n");

}
void Peek(){
    if(IsEmpty()){
        printf("Queue Underflow \n");
        return ;
    }
    printf("Last Element is %d\n",queue[rear]);
}

void View(){
    if(IsEmpty()){
        printf("Queue Underflow \n");
        return;
    }
    printf("Queue contents are\n");
    for(int i=front;i<=rear;i++){
        printf("  %d  -> ",queue[i]);
    }
    
}
void display(){
    do{
        printf("\nThe Options are :\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        int n ;
        printf("Enter the opetions : ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            View();
            break;
        case 5:
            exit(0);
            break;
        
        default:
            printf("\nNo such an option\n");
            break;
        }
    }while(1);


}
int main(){
    
    display();
    return 0;
    
}