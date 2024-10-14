#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct poly{
    int exp;
    int coeff;
};

void create(struct poly a[] ,int n){
    for(int i =n ; i>=0 ; i--){
        printf("Enter the term at %d^^",i);
        scanf("%d",&a[i].coeff);
        a[i].exp=i;
    }
}

void display(struct poly a[] , int n){
    for(int i =n ; i>=0 ; i--){
         if(a[i].coeff==0){
            continue;
        }
        if(i!=n && a[i].exp>0)
        {
             printf("+"); 
        }
        printf(" %d ^^ %d ",a[i].coeff,a[i].exp);

    }
    printf("\n");
}

void sum(struct poly a[],struct poly b[],struct poly c[],int n,int d1,int d2){
    for(int i = 0 ;i<=n ; i++){
        c[i].exp=i;
        c[i].coeff=(i<=d1?a[i].coeff:0)+(i<=d2?b[i].coeff:0);
    }
}

int main(){
    struct poly a[50],b[50],c[50];
    int d1,d2,d3;
    printf("Enter the highest degree of first polynomial : ");
    scanf("%d",&d1);
    create(a , d1);
    printf("Enter the highest degree of second polynomial : ");
    scanf("%d",&d2);
    create(b , d2);

    printf("Displaying 1st poly : \n");
    display(a,d1);
    printf("Displaying 2nd poly : \n");
    display(b,d2);

    d3=(d1>d2)?d1:d2;
    sum(a,b,c,d3,d1,d2);

    printf("Displaying sum poly : \n");
    display(c,d3);
}