#include "../include/task2.h"
#include "../include/ex5.h"
//Write a program that lets the user enter the total rainfall for each of 12 months in an array.
// The program should calculate and display the total rainfall for the year, the average monthly rainfall, and the months with the highest and lowest amount of rainfall
void mission2Menu() {
    int highest =  0, lowest = 0;
    int rainFall[MONTHS];
    setArr(rainFall, &highest, &lowest);
}
void setArr(int *arrptr, int *highest, int *lowest) {
    int i = 0;
    for (; i < MONTHS; i++) {

        printf("enter rainfall metere for month ");
        switch (i) {
            case Jan:
                printf("Jan:");
                break;
            case Feb:
                printf("Feb:");
                break;
            case Mar:
                printf("Mar:");
                break;
            case Apr:
                printf("Apr:");
                break;
            case May:
                printf("May:");
                break;
            case Jun:
                printf("Jun:");
                break;
            case Jul:
                printf("Jul:");
                break;
            case Aug:
                printf("Aug:");
                break;
            case Sep:
                printf("Sep:");
                break;
            case Oct:
                printf("Oct:");
                break;
            case Nov:
                printf("Nov:");
                break;
            case Dec:
                printf("Dec:");
                break;
        }
        do {
            scanf("%d", arrptr + i);
        } while (arrptr[i] < 0);
        if(*highest < arrptr[i]) {
            *highest = arrptr[i];
        }
        if (i == 0 || *lowest > arrptr[i] ) {
            *lowest = arrptr[i];
        }
    }
    printResformission2(arrptr, highest, lowest);
}
void printResformission2(int *arrptr, int *highest, int *lowest) {
    int i = 0, total = 0;
    double avg = 0;
    while (i < MONTHS) {
        total += arrptr[i];
        i++;
    }
    avg = (total / (double)MONTHS);
    printf("total is %d, avg is %f, highest is %d, lowest is %d\n", total, avg, *highest, *lowest);
}