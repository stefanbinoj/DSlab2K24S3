#include<stdio.h>
int linearsearch(int arr[],int n ,int e){
    for (int i =0;i<n;i++){
        if(arr[i]==e){
            return i;
            break;
        }
    }
    return -1;
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

    printf("\nEnter the element to search : ");
    int e;
    scanf("%d",&e);

    int result = linearsearch(arr,n,e);
    if (result != -1){
        printf("\nFound the elemet at %d\n",result);
    }
    else{
        printf("\nCouldnot find the element\n");
    }
    return 0;
    
}