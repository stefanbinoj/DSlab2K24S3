#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 10

int cqueue[MAX_SIZE];
int front=-1;
int rear=-1;

bool IsEmpty(){
    return front==-1;
}

bool IsFull(){
    return (rear+1)%MAX_SIZE==front;
}

void Insert(){
    if(IsFull()){
        printf("Queue Overflow \n");
        return ;
    }
    else{
        int n;
        printf("Enter the element to push : ");
        scanf("%d",&n);
        if(IsEmpty()){
            front=rear=0;
        }
        else{
            rear=(rear+1)%MAX_SIZE;
        }
        cqueue[rear]=n;
    }
    
    
}
void Delete(){
     if(IsEmpty()){
        printf("Queue Underflow \n");
        return ;
    }
    else{
        printf("\nElement deleted from queue is : %d\n", cqueue[front]);
        if(rear==front){
            rear=front=-1;
        }
        else{
            front=(front+1)%MAX_SIZE;
        }

    }
    

}
void Peek(){
    if(IsEmpty()){
        printf("Queue Underflow \n");
        return ;
    }
    printf("First Element is %d\n",cqueue[front]);
}

void View(){
    int i;
    if(IsEmpty()){
        printf("Queue Underflow \n");
        return;
    }
    printf("Queue contents are\n");
    for(i=front;i!=rear;i=(i+1)%MAX_SIZE){
        printf("  %d  -> ",cqueue[i]);
    }
    printf("%d ", cqueue[i]); //print the element at rear
    printf("\n");

    
}
void size() {
    if (IsEmpty()) {
        printf("Empty queue \n");
        return ;
    } else {
        if (rear >= front ) printf("%d", rear - front + 1);
        else printf("%d", MAX_SIZE-front+rear-0+1);
    }
}
void display(){
    do{
        printf("\nThe Options are :\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Size\n");
        printf("5.Quit\n");
        int n ;
        printf("Enter the opetions : ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Peek();
            break;
        case 4:
            View();
            break;
        case 6:
            exit(0);
            break;
        case 5 :
            size();
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