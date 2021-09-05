#ifndef ex5_H_   /* Include guard */
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
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
typedef struct Value{ 
    short unsigned int occurences;
    char indices[127] ; 
} Value; 
typedef struct{ 
    int key;
    Value val; 
} Item;
typedef struct{
    // Contains an array of pointers
    // to items
    Item** items;
    int size;
    int count;
}HashTable;
typedef struct{
    int *initialArr;
    HashTable* table;
    int *finalArr;
}DataBase;
Value getItemVal(HashTable* hash, int key);
void addItem(HashTable* hash, Item* item);
Item* create_item(int key, int index);
DataBase* initializeDB();
int isNumber(char *n);
int* initializeArr(size_t *arrSize, int* arr);
void clearString(char *str);
DataBase* EnterNumbersToDB(DataBase* db, char *str);
#endif // ex5_H_