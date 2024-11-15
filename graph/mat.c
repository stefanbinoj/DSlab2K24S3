#include <stdio.h>
int mat[50][50];
int n;

void read(){
    int ad;
    printf("Enter no . of vertices : \n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter enter vertices adj to %d : : -1 to stop",i);
        while(1){
            scanf("%d",&ad);
            if(ad==-1)break;
            mat[i][ad]=1;
        }
    }
}

void disp(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
}

void calculateDegree(){
    int deg;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j]==1)deg++;
        }
    }
    printf("deg is : %d",deg);
}

int main()
{
read();
disp();
calculateDegree();
return 0;
}