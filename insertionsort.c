// WAP to do insertion sort

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
    for(i=1; i<=n-1; i++){
        int key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("After Sorting Array Elements : \n");
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}