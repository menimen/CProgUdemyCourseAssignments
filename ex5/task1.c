//Write a program to get 5 elements in an array and get a number to be multiplied with the array elements
#include "../include/task1.h"
#include "../include/ex5.h"
void mission1Menu() {
    int i = 0, num = 0;
    int arr[ARR_SIZE];
    while (i < ARR_SIZE) {
        printf("enter %d element:\n",i + 1);
        scanf("%d", (arr + i));
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