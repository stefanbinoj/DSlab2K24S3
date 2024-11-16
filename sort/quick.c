#include <stdio.h>
#include<stdlib.h>

int partition(int arr[],int lb,int ub){
    int pivot =arr[lb];
    int start = lb;
    int end = ub;
    while(start<end){
        while(arr[start]<=pivot)start++;
        while(arr[end]>pivot)end--;
        if(start<end){
            int temp = arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    int temp = arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;

    return end;
}

void quickstart(int arr[],int start , int end){
    if(start<end){
        int loc = partition(arr,start,end);
        quickstart(arr,start,loc-1);
        quickstart(arr,loc+1,end);
    }
}

int main() {
    int n;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the quickSort function to sort the array
    quickstart(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}