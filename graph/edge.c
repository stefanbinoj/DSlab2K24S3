#include<stdio.h>
int mat[50][50];
int nv,ne;
void read(){
    printf("Enter vertices and edges : \n");
    scanf("%d",&nv);
    scanf("%d",&ne);
    for(int i=1;i<=nv;i++){
        printf("Enter realation of %d : \n",i);
        for(int j=1;j<=ne;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
void display(){
   
    for(int i=1;i<=nv;i++){
        for(int j=1;j<=ne;j++){
            printf("%5d",mat[i][j]);

        }
        printf("\n");
    }
}

void incoming (){
     printf("Enter whicch \n ");
    int n;
    int total=0;
    scanf("%d",&n);
    for(int j=1;j<=ne;j++){
        if(mat[n][j]==-1)total++;
    }
    printf("total %d : \n",total);
}
void outcoming (){
     printf("Enter whicch \n ");
    int n;
    int total=0;
    scanf("%d",&n);
    for(int j=1;j<=ne;j++){
        if(mat[n][j]==1)total++;
    }
    printf("total out %d : \n",total);
}

int main() {
    read();
    display();
    incoming();
    outcoming();
    return 0;
}
