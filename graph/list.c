#include<stdio.h>
#include<stdlib.h>

struct vertex {
    int data ;
    struct vertex * next;
};
struct vertex * adj[50];
struct vertex * tail[50];
int n ;

void read(){
    int ad;
    printf("Enter no of verticed : \n");
    scanf("%d",&n);
    for(int i=1 ; i<=n;i++){
        adj[i]=NULL;
        tail[i]=NULL;
        printf("Enter elemtns linked :: -1 to stop \n");
        while(1){
            scanf("%d",&ad);
            if(ad==-1)break;
            struct vertex * newNode = (struct vertex *)malloc(sizeof(struct vertex));
            newNode->data=ad;
            newNode->next=NULL;
            if(adj[i]==NULL){
                adj[i]=tail[i]=newNode;
            }else{
                tail[i]->next=newNode;
                tail[i]=newNode;
            }

        }
    }
}

void disp(){
    for(int i=1;i<=n;i++){
        printf("For %5d : \n",i);
        struct vertex * temp = adj[i];
        while(temp!=NULL){
            printf("%d --> ",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
read();
disp();
return 0;
}