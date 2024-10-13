#include<stdio.h>
int binarysearch(int arr[],int n ,int e){
    int left=0,right=n-1,mid;
    while(left<=right){
        mid = left + (right-left) /2;
        if(arr[mid]==e){
            return mid;
        }
        if(arr[mid]<e){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    printf("Enter the elements in array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d sorted elements : \n",n);
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

    int result = binarysearch(arr,n,e);
    if (result != -1){
        printf("\nFound the elemet at %d\n",result);
    }
    else{
        printf("\nCouldnot find the element\n");
    }
    return 0;
    
}