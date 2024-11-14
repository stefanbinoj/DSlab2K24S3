#include <stdio.h>


int binarysearch(int arr[] , int n , int target){
    int left =0,right=n-1,mid;
    while(left<=right){
        mid =left+(right- left )/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>n) {
            right = mid-1;
        }
        else{
            left=mid+1;
        }
    }
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
result = binarysearch(arr, n, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}