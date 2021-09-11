#include "../include/task5.h"
//Write a program to take input for two arrays.
// First array with five elements and the second array with three elements and add both array elements and display the merged array.
void mission5Menu() {
    int arr1[FIRSTARRAYSIZEINTASK5] = {0};
    int arr2[SECONDARRAYSIZEINTASK5] = {0};
    printf("Input for the first array :");
    getElements(arr1);
    printf("Input for the second array :");
    getElements(arr2);
    AddArrays(arr1, arr2);
    printMergedArray(arr1);
}
void printMergedArray(int *arr) {
    int i = 0;
    printf("Added and Merged array: %d", arr[i]);
    i++;
    for(; i < FIRSTARRAYSIZEINTASK5; i++) {
        printf(", %d", arr[i]);
    }
    printf("\n");
}
//add values in both arrays in respected indexes
void AddArrays(int *arr1, int *arr2) {
    int i = 0;
    for(; i < SECONDARRAYSIZEINTASK5; i++) {
        arr1[i] = arr1[i] + arr2[i];
    }
}