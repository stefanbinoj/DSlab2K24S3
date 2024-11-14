#include<stdio.h>
int binarySearch(int arr[],int left , int right , int target){
    if(left<=right){
    int mid = left+(right-left)/2;
    if(target==arr[mid]){
        return mid;
    }
    else if(target>arr[mid]){
        return binarySearch(arr,mid+1,right,target);
    }
    else{
        return binarySearch(arr,left,mid-1,target);
    }}
    return -1;
}

int main() {
    int i,n,arr[50],target,result;
printf("Enter number of elements :: ");
scanf("%d",&n);

printf("\nEnter %d elements in sorted order:: \n", n);
for ( i = 0 ; i < n ; i++ )
{
scanf("%d",&arr[i]);
}

printf("\nEnter key value to search :: ");
scanf("%d",&target);
result = binarySearch(arr, 0,n-1, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}