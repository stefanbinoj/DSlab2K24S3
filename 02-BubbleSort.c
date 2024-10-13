#include<stdio.h>
void swap(int*x,int*y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubblesort(int arr[],int n){
    int swapped = 1;
    while(swapped){
        swapped=0;
        for(int i = 0 ;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1]);
                swapped=1;
            }
        }
    }

}
int main(){
    int n;
    printf("Enter the elements in array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements : \n",n);
    for(int i = 0 ; i<n ;i++){
        scanf("%d",&arr[i]);
    }
    printf("The array is : \n");
    for (int i =0 ; i<n ;i++){
        printf("%d  ",arr[i]);
    }
    bubblesort(arr,n);

    printf("\nSorted elements: \n");
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);

    return 0;
    
    
}