#ifndef ex5_H_   /* Include guard */
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
int isNumber(char *n);
void AssignElementsToArr(int* arr, char *buffer, const char *delim);
void clearString(char *str);
void printString(char *str);
void getElements(int* arr);
char* getstring();
#endif // ex5_H_