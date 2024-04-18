/*
a. Write a C program, that realizes algorithm bellow:
Step 1: Start;
Step 2: Read array a[] with n elements; 
Step 3: Initialize pointer to the array;
Step 4: If i<n go to next step, otherwise go to the step 7;
Step 5: Print array element using pointer and print element address;
Step 6: i=i+1 go to step 4;
Step 7: Stop;
*/
#include <stdio.h>

void printArrEl(int *arr, int n){
    printf("Printing array elements using pointer:\n");
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}

void printArrElAdr(int *arr, int n){
    printf("Printing array elements address using pointer:\n");
    for(int i = 0; i < n; i++){
        printf("%p\n", (void*)&arr[i]);
    }
}

int main() {
    int n, i;
    printf("Enter the number of values for arr: ");
    scanf("%d", &n);
    int *arr= malloc(n * sizeof(int));
    printf("Enter %d elements for the array:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }
    printArrEl(arr,n);
    printArrElAdr(arr,n);
   
    return 0;
}