// WAP to do selection sort

#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter Array Size : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elememts : ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n-1; i++){
        int min=i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min]){  // Condition for descending order if (arr[j]>arr[min])
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    printf("After Sorting Array Elements : \n");
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}