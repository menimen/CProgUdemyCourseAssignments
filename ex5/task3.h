#ifndef task3_H
#define task3_H
#include "task3Structs.h"
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
Item* create_item(int key, int index);
DataBase* initializeDB();
int isNumber(char *n);
DataBase* initializeArr(size_t *arrSize,DataBase *db, etype element_type);
void clearString(char *str);
DataBase* EnterNumbersToDB(DataBase* db, char *str);
void clearDB(DataBase** db);
Item* createItem(int *key, int *index);
DataBase* CheckIfInHash(DataBase* db, int *num, int index);
int generateHashCode(int num);
void printMisision(DataBase *db);
void freeHash(DataBase** db);
void deleteList(LinkedList** node);
void clearNode(LinkedList** head);
void printIndeces(const short unsigned *occurences, int* indeces);
void clearFinalArr(DataBase** db);
#endif