#include "ex5.h"
//Write a program to get 5 elements in an array and get a number to be multiplied with the array elements
#define ARR_SIZE 5
void mission1Menu() {
    int i = 1, num = 0;
    int arr[ARR_SIZE];
    while (i < 6) {
        printf("enter %d element:\n",i);
        scanf("%d", &arr[i-1]);
        i++;
    }
    printf("enter num to be multiplied with:");
    scanf("%d", &num);
    for (int j = 0; j < 6; j ++ ) {
        mult(&arr[j], num);
    }
    printArr(arr);
}
void mult(int* num, int multWithNum) {
    *num = *num * multWithNum;
}
void printArr(int* arr) {
    for (int i = 0; i < ARR_SIZE ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}