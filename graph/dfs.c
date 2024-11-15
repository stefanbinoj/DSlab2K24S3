#include<stdio.h>
#include<stdlib.h>
void dfs(int vertex ,int visited[10],int adj[10][10],int numberOfVertices){
    printf("V%d ", vertex ); // Assuming vertex labels are 'V0', 'V1', 'V2', ...
    visited[vertex] = 1;

    // Recursively visit all unvisited neighbors
    for (int i = 0; i < numberOfVertices; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, visited, adj, numberOfVertices);
        }
    }


}

int main(){
    int numberOfVertices;
    int adj[10][10];
    int visited[10]={0};

    printf("Enter number : \n");
    scanf("%d",&numberOfVertices);

    for(int i=1;i<=numberOfVertices;i++){
        printf("Enter connection for %d \n",i);
        for(int j=1 ; j<=numberOfVertices;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("BDS : \n");
    for(int i=1;i<=numberOfVertices;i++){
        if(!visited[i] ) dfs(i,visited,adj,numberOfVertices);
    }
    return 0;
}