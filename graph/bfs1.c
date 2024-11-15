#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct vertex{
    int num;
    int visit;
};
struct vertex visited[MAX];
struct vertex que[MAX];
int front =-1,rear=-1;

int adjacentMatrix[MAX][MAX];

void addq(struct vertex v) {
    rear++;
    que[rear] = v;
}

struct vertex deleteq() {
    ++front;
    return(que[front]);
}

int qempty() {
    return front == rear;
}

