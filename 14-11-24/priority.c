#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
void check(int);
void display();

int pri[MAX];
int front =-1 , rear = -1;

bool isEmpty(){
    return front ==-1;
}

bool isFull(){
    return rear==MAX-1;
}

void insert(int a){
    if(isFull()){
        printf("OVerflow");
        return ;
    }
    if(isEmpty()){
        front = rear =0;
        pri[rear]=a;
    }
    else{
        check(a);
        rear++;
        display();

    }
}

void check(int a ){
    int i;
    for( i= 0 ; i<rear ; i++){
        if(a<=pri[i]){
            for(int j=rear+1;j>i;j--){
                pri[j]=pri[j-1];
            }
            pri[i]=a;
            return ;
        }
       
    }
    pri[i]=a;

}

void delete(int a){
    int i , j;
    if(isEmpty()) {
        printf("Empty \n");
        return ;
    }
    for( i= 0 ; i<rear ; i++){
        if(a==pri[i]){
            for( j=i;j<rear;j++){
                pri[j]=pri[j+1];
            }
        pri[j] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
        printf("\n%d not found in queue to delete", a);

}

void display(){
    for(int i=front ; i<=rear ; i++){
        printf("%d -->" , pri[i]);
    }
}

void main()
{
    int n, ch;
 
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");
 
    //create();
 
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1: 
            printf("\nEnter value to be inserted : ");
            scanf("%d",&n);
            insert(n);
            break;
        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d",&n);
            delete(n);
            break;
        case 3: 
            display();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}