#include "../include/task3.h"
#include "../include/ex5.h"
//Write a program to find the similar elements in an array and find its occurrence. Display the array element, index of the element and its number of occurrence.
void mission3Menu() {
    char *buffer;
    int siz = 255;
    DataBase* db = NULL;
    buffer = (char *)malloc(siz * sizeof(char));
    if (buffer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    getchar(); //dummy
    printf("enter elements one by one seperated wiht spaces, press \"enter\" to finish: \n");
    fgets(buffer, siz, stdin);
    db = initializeDB();
    db = EnterNumbersToDB(db, buffer);
    printMisision(db);
    clearString(buffer);
    clearDB(&db);
    free(db);
    db = NULL;
    
    
    
    
    /*DataBase* db = (DataBase*)malloc(sizeof(DataBase));
    db->initialArr = (int*)malloc(sizeof(int));
    db->table = (HashTable*)malloc(sizeof(HashTable));
    db->table->size = 1;
    db->table->list = (LinkedList**)malloc(sizeof(LinkedList*));
    db->table->list[0] = (LinkedList*)malloc(sizeof(LinkedList));
    db->table->list[0]->item = (Item*)malloc(sizeof(Item));
    db->table->list[0]->next = NULL;
    db->table->list[0]->item->val = (Value*)malloc(sizeof(Value));
    db->table->list[0]->item->val->indices = (int*)malloc(sizeof(int));
    db->table->list[0]->item->val->indices[0] = 3;
    db->table->list[0]->item->val->occurences = 1;
    db->finalArr = (Item**)malloc(1*sizeof(Item*));
    db->sizeofFinalArray = 1;
    db->finalArr[0] = (db->table->list[0]->item);
    clearDB(&db);
    free(db);
    db = NULL;*/
}
Item* createItem(int *key, int *index) {
    return NULL;
}
DataBase* EnterNumbersToDB(DataBase* db, char *str) {
    char* token;
    int i = strlen(str);
    size_t count = 0;
    int num = 0;
    const char delim[2] = " ";
    str[i-1] = '\0';
    token = strtok(str, delim);
   
   /* walk through other tokens */
   while( token != NULL ) {
      num = atoi(token);
      count++;
      //todo
      token = strtok(NULL, delim);
   }
   return db;
}
int isNumber(char *n) {
  int i = strlen(n);
  int isnum = (i>0);
  while (i-- && isnum) {
    if (!((n[i] >= '0' && n[i] <= '9') || (n[0] == '-') )) {
      isnum = 0;
    }
  }
  return isnum;
}
DataBase* initializeDB(){
    DataBase *db = (DataBase*)malloc(sizeof(DataBase));
    if (db == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    return db;
}
DataBase* initializeArr(size_t *arrSize,DataBase *db, etype element_type) {
    Item** arrn = NULL;
    int* arr = NULL;
    switch(element_type) {
        case e_int :
            arr = (int*)realloc(db->initialArr, (*arrSize)*sizeof(int));
            if(arr == NULL) {
                printf("memory allocation failed");
                exit(0);
            }
            db->initialArr = arr;
            break;
        case e_item:
            arrn = (Item**) realloc(db->finalArr,(*arrSize)*sizeof(Item*));
            if(arrn == NULL) {
                printf("memory allocation failed");
                exit(0);
            }
            db->finalArr = arrn;
            break;
        default:
            printf("problem occured. exiting....");
            exit(0);
    }
    return db;
}
void clearDB(DataBase** db) {
    freeHash(db);
    free((*db)->table);
    (*db)->table = NULL;
    if((*db)->finalArr !=NULL) {
        //clearFinalArr(db);
        free((*db)->finalArr);
        (*db)->finalArr =NULL;
    }
    free((*db)->initialArr);
    (*db)->initialArr = NULL;
}
void clearFinalArr(DataBase** db) {
    int i = 0;
    Item** ptr = (*db)->finalArr;
    /*for(; i < (*db)->sizeofFinalArray; i++) {
        if((*db)->finalArr[i] != NULL){
            free((*db)->finalArr[i]);
            (*db)->finalArr[i] = NULL;
        }
    }*/
}
DataBase* CheckIfInHash(DataBase* db, int *num, int index) {
    return NULL;//todo
}
int generateHashCode(int num) {
    int n = num % 10;
    return n;
}
DataBase* initializeTable(DataBase* db, size_t size) {
    HashTable* tmp = NULL;
    tmp = (HashTable*)realloc(db->table, size * sizeof(HashTable));
    if(tmp == NULL) {
        printf("allocation failed");
        exit(0);
    } else {
        db->table = tmp;
        db->table->size = size;
    }
    return db;
}
void printMisision(DataBase *db) {
    int i = 0;
    if(db->finalArr == NULL) {
        printf("no duplicates given\n");
    } else {
        for (; i < db->sizeofFinalArray; i++) {
            printf("the number : %d", db->finalArr[i]->key);
            printf("has shown %d times ", db->finalArr[i]->val->occurences);
            printf("in indeces:" );
            printIndeces(&(db->finalArr[i]->val->occurences), db->finalArr[i]->val->indices);
        }
    }
}
void printIndeces(const short unsigned *occurences, int* indeces) {
    int i =0;
    printf("%d", indeces[i]);
    i++;
    while (i < *occurences - 1) {
        printf(", %d", indeces[i]);
        i++;
    }
    printf("\n");
}
void freeHash(DataBase** db) {
    int i = 0;
    for (i = 0; i< (*db)->table->size; i++) {
        deleteList(&(*db)->table->list[i]);
    }
    free((*db)->table->list);
    (*db)->table->list = NULL;
    //return db;
}
void deleteList(LinkedList** list) {
    LinkedList* head = *list, *current = NULL;
    current = head;
    while(current != NULL) {
        current = current->next;
        clearNode(&head);
        head = current;
    }
}
void clearNode(LinkedList** head) {
    LinkedList* current = *head;
    free(current->item->val->indices);
    current->item->val->indices = NULL;
    free(current->item->val);
    current->item->val = NULL;
    free(current->item);
    current->item = NULL;
    free(*head);
    *head = NULL;
}
void clearString(char *str) {
    free(str);
    str = NULL;
}