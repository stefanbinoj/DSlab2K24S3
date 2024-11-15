#include<stdio.h>
#define MAX 10

void bfs(int startIndex , int visited[MAX],int adjacentMatrix[MAX][MAX],int numberOfVertices){
    int que[MAX];
    int front=-1 , rear =-1;
    visited[startIndex]=1;
    que[++rear]=startIndex;
    printf("BFS traversal starting from V%d: ", startIndex);
    while(front!=rear){
        int currentIndex = que[++front];
        printf(" V%d : ",currentIndex);

        for(int j =1 ; j<=numberOfVertices ; j++){
            if(adjacentMatrix[currentIndex][j]==1 && !visited[j]){
                que[++rear]=j;
                visited[j]=1;
            }
        }
        printf("\n");

    }
}

int main(){
    int numberOfVertices ; 
    printf("Enter no of vertices  : \n");
    scanf("%d",&numberOfVertices);

    int adjacentMatrix[MAX][MAX];
    int visited[MAX]={0};

    for(int i = 1 ; i<=numberOfVertices;i++){
        printf("Enter relation of V%d : ",i);
        for(int j =1 ; j<=numberOfVertices ; j++){
            scanf("%d",&adjacentMatrix[i][j]);
        }
    }

    for(int i=1 ; i<=numberOfVertices;i++){
        if(!visited[i])bfs(i,visited,adjacentMatrix,numberOfVertices);
    }
    return 0;
}