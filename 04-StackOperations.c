#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top=-1;

void Push(){
    if(top==MAX_SIZE-1){
        printf("Stack Overflow \n");
        return ;
    }
    int n;
    printf("Enter the element to push : ");
    scanf("%d",&n);
    top++;
    stack[top]=n;
}
void Pop(){
     if(top==-1){
        printf("Stack Underflow \n");
        return ;
    }
    top--;
    printf("Element popped\n");

}
void Peek(){
    if(top==-1){
        printf("Stack Underflow \n");
        return ;
    }
    printf("Last Element is %d\n",stack[top]);
}
bool IsEmpty(){
    return top==-1;
}
void View(){
    if(IsEmpty()){
        printf("Stack Underflow \n");
        return;
    }
    printf("Stack contents are\n");
    for(int i=top;i>=0;i--){
        printf(" | %d |\n",stack[i]);
    }
    printf(" __ \n");
    
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