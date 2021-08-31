#ifndef ex5_H_   /* Include guard */
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define ARR_SIZE 5
#define MONTHS 12
void mission1Menu();
void mission2Menu();
void mission3Menu();
void mission4Menu();
void mission5Menu();
void mission6Menu();
void printArr(int* arr);
void mult(int* num, int multWithNum);
enum month{Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
void setArr(int *arrptr, int *highest, int *lowest);
void printResformission2(int *arrptr, int *highest, int *lowest);
#endif // ex5_H_