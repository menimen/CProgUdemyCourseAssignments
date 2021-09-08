#ifndef task3Structs_H
#define task3Structs_H
#include <stdio.h>
typedef struct Value{ 
    short unsigned int occurences;
    int *indices ; 
} Value; 
typedef struct{ 
    int key;
    Value *val; 
} Item;
typedef struct LinkedList {
    Item* item; 
    struct LinkedList* next;
}LinkedList;
typedef struct{
    LinkedList** list;
    int size;
}HashTable;
typedef struct{
    int *initialArr;
    HashTable* table;
    Item **finalArr;
    int sizeofFinalArray;
}DataBase;
typedef enum{

       e_int,

       e_item,
}etype;
#endif