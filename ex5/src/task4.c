#include "../include/task4.h"
#include "../include/ex5.h"
//Write a program to get 10 integer inputs in an 
//array and select an element from the array and show the elements which are :
// bigger,smaller,divisible by the chosen element
void mission4Menu() {
    int arr[ArraySiZEFORTASK4] = {0};
    int BiggerthanCounter = 0, SmallerthanCounter = 0, DivisibleCounter = 0;
    getElements(arr); // get elements from input and place in array
    int index = RandIndex(ArraySiZEFORTASK4); 
    for (int i = 0; i < ArraySiZEFORTASK4; i++)
    {
        if ( i == index) {
            i++;
        }
        if(isSmaller(&arr[index], &arr[i])) {
            SmallerthanCounter++;
        }
        if(isBigger(&arr[index], &arr[i])) {
            BiggerthanCounter++;
        }
        if(isDividedBy(&arr[index], &arr[i])) {
            DivisibleCounter++;
        }
    }
    printf("the chosen number is : %d\n"
    "Number of elements which are greater than the selected element:%d\n"
    "Number of elements which are smaller than the selected element:%d\n"
    "Number of elements which are exactly divisible by the selected element:%d\n"
    ,arr[index],
    BiggerthanCounter,
    SmallerthanCounter,
    DivisibleCounter);
}
void getElements(int* arr) {
    char *buffer;
    int siz = 25;
    const char delim[2] =",";
    buffer = (char *)malloc(siz * sizeof(char));
    if (buffer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    printf("enter elements one by one seperated with commas, press \"enter\" to finish: \n");
    fgets(buffer, siz, stdin);
    AssignElementsToArr(arr,buffer,delim);
    clearString(buffer);
}
// place elements in array from buffer string 
void AssignElementsToArr(int* arr, char *buffer, const char *delim) {
    char* token;
    int i = strlen(buffer), index = 0;
    int num = 0;
    buffer[i-1] = '\0';
    token = strtok(buffer, delim);
   
   /* walk through other tokens */
    while( token != NULL ) {
        if(isNumber(token) == 0) {
            printf("%s not a number, moving on...", token);
        } else {
        num = atoi(token);
        arr[index] = num;
        index++;
        }
        token = strtok(NULL, delim);
   }
}
// randomize index in arr to choose which element is the pivot
int RandIndex(int upperBound) {
    int r = (rand()%upperBound+upperBound)%upperBound;
    return r;
}
//is element smaller than pivot
int isSmaller(int* pivot, int *element) {
    return (*pivot > *element) ? 1 : 0;
}
//is element bigger than pivot
int isBigger(int* pivot, int *element) {
    return (*element > *pivot) ? 1 : 0;
}
//is element divided by pivot
int isDividedBy(int* pivot, int *element) {
    int piv = *pivot;
    int elem = *element;
    if (*element == 0) {
        return 0;
    } else {
    return ( ( ( piv % elem)+ elem) % elem == 0 ) ? 1 : 0;
    }
}