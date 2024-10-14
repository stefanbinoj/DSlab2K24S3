#include<stdio.h>
#include<stdlib.h>

void create(int a[] , int n){
    int i = 0;
    for(i = n ; i>=0 ; i--){
        printf("%d ^^ term : ",i);
        scanf("%d",&a[i]);
    }
}

void display(int a[] ,int n){
    printf("\nThe polynomials are  : \n");
    for( int i= n ; i>=0;i--){
        if(a[i]==0){
            continue;
        }
         if(i!=n && a[i]>0)
        {
             printf("+"); 
        }
        printf(" %d ^^ %d ",a[i],i);
    }
}

void sum(int a[] , int b[],int c[] ,int d3){
    printf("The sum is : \n" );
    for(int i =d3 ; i>=0;i--){
        c[i]=a[i]+b[i];
    }
}

int main(){
    int d1,d2,d3;
    int a[50],b[50],c[50];
    printf("Enter the highest degree of first polynomial : ");
    scanf("%d",&d1);
    printf("Enter the highest degree of second polynomial : ");
    scanf("%d",&d2);
    if(d1>=d2)d3=d1;
    else d3=d2;
    
    printf("Enter the coefficients for first poly  : \n");
    create(a,d1);
    printf("Enter the coefficients for second poly  : \n");
    create(b,d2);

    display(a,d1);
    display(b,d2);

    sum(a,b,c,d3);

    printf("The sum is : \n");
    display(c,d3);
}