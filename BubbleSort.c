// WAP to store the names of N students in an array and display all elements of array in ascending order using bubble sort

#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter Array Size : ");
    scanf("%d", &n);
    char arr[n];
    printf("Enter array elememts : ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j+1]<arr[j]){  // Condition for descending order if (arr[j+1]>arr[j])
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("After Sorting Array Elements : \n");
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}