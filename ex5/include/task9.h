#ifndef task9_H
#define task9_H
#include "ex5.h"
#include "task9structs.h"
#include<string.h>
#include<stdio.h>
#define ALPHABETSIZE 26
void mission9Menu();
void printfromZtoA(LinkedListForTask9** list);
void printfromAtoZ(LinkedListForTask9** list);
LinkedListForTask9** initializeLinkedListForTask9();
int initializecharPointerArray(char ***arr, int *arr_size);
void ParseLine(char ***arr, int* arr_size, char *str, const char* delim);
void clearCharPointerArr(char*** arr, int *arr_size);
void AllocateStringandAssignPointerToitFromCharPointerArray(char ***arr,int *arr_size,  char *substring, int *index);
void printCharPointerArray(char** arr, int * arr_size);
LinkedListForTask9* createNode(char** str);
void insertNode(LinkedListForTask9** head, LinkedListForTask9** node);
void AssignPointersToNodes(char **arr, int *arr_size, LinkedListForTask9** list);
void clearLinkedListArray(LinkedListForTask9** list);
void clearLinkedList(LinkedListForTask9** head);
void printTask9Res(LinkedListForTask9** list, int direction);


#endif