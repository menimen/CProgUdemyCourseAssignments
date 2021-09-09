#ifndef task3Structs_H
#define task3Structs_H
#include <stdio.h>
typedef struct{ 
    int num;
    short unsigned int occurences;
    int *indices ; 
} Item;
typedef struct LinkedList {
    Item* item; 
    struct LinkedList* next;
}LinkedList;
typedef struct{
    LinkedList** list;
}HashTable;
typedef struct{
    HashTable* table;
    Item **finalArr;
    int sizeofFinalArray;
}DataBase;
#endif