#ifndef task3_H
#define task3_H
#include "task3Structs.h"
#include "ex5.h"
#define _GNU_SOURCE
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
void mission3Menu();
DataBase* ParseRequest(DataBase* db, char *str);
DataBase* initializeDB();
DataBase* initializeArr(size_t *arrSize,DataBase *db);
DataBase* ParseRequest(DataBase* db, char *str);
void EnterNumbersToHash(DataBase** db, int *num, int* index);
void clearDB(DataBase** db);
Item* createItem(int *key, int *index);
int generateHashCode(int num);
void printRes(DataBase *db);
void freeHash(DataBase** db);
void deleteList(LinkedList** node);
void clearNode(LinkedList** head);
void printIndeces(const short unsigned *occurences, int* indeces);
void InsertItem(LinkedList** list, Item **item);
void updateValueInList(Item** item, int* index);
Item* FindItemInHash(LinkedList* list, int *num);
void SyncWithFinalArr(DataBase** db, Item **item);
#endif