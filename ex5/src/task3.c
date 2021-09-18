#include "../include/task3.h"
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
    //getchar(); //dummy
    printf("enter elements one by one seperated with spaces, press \"enter\" to finish: \n");
    fgets(buffer, siz, stdin);
    db = initializeDB();
    db = ParseRequest(db, buffer);
    printRes(db);
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
    Item *item = (Item*)malloc(sizeof(Item));
    item->num = *key;
    item->occurences = 1;
    item->indices = (int*)malloc(sizeof(int));
    item->indices[(item->occurences) - 1] = *index;
    return item;
}
DataBase* ParseRequest(DataBase* db, char *str) {
    char* token;
    int i = strlen(str), index = 0;
    size_t count = 0;
    int num = 0;
    const char delim[2] = " ";
    str[i-1] = '\0';
    token = strtok(str, delim);
   
   /* walk through other tokens */
    while( token != NULL ) {
        if(isNumber(token) == 0) {
            printf("%s not a number, moving on...", token);
        } else {
        num = atoi(token);
        EnterNumbersToHash(&db, &num, &index);
        index++;
        }
        count++;
        token = strtok(NULL, delim);
   }

   return db;
}
void EnterNumbersToHash(DataBase** db, int *num, int* index) {
    Item* item = NULL;
    if((*db)->table == NULL) {
        (*db)->table = (HashTable*)malloc(sizeof(HashTable));
        if((*db)->table == NULL) { 
            printf("Memory not allocated.\n");
            exit(0);
        }
        (*db)->table->list = (LinkedList**)malloc(10 * sizeof(LinkedList*));
        for(int j =0; j < 10; j++) {
            ((*db)->table->list)[j] = NULL;
        }
    }
        int hashcode = generateHashCode(*num);
        item = FindItemInHash(((*db)->table->list)[hashcode], num);
        if(item == NULL) {
            item = createItem(num, index);
            if((*db)->table->list[hashcode]  == NULL) {
                (*db)->table->list[hashcode] = (LinkedList*)malloc(sizeof(LinkedList));
                if((*db)->table->list[hashcode] == NULL) {
                    printf("Memory not allocated.\n");
                    exit(0);
                }
                ((*db)->table->list)[hashcode]->next = NULL;
                ((*db)->table->list)[hashcode]->item = item;
            } else {
                InsertItem(&(*db)->table->list[hashcode], &item);
            }
        } else {
            updateValueInList(&item, index);
            SyncWithFinalArr(db, &item);
        }
}
Item* FindItemInHash(LinkedList* list, int *num) {
    while (list != NULL)
    {
        if(list->item->num == *num) {
            return list->item;
        }
        list = list->next;
    }
    return NULL;
    
}
void SyncWithFinalArr(DataBase** db, Item **item) {
    int flag= 0;
    if((*db)->sizeofFinalArray == 0) {
        (*db)->finalArr = (Item**)malloc(sizeof(Item*));
        if((*db)->finalArr == NULL) { 
            printf("Memory not allocated.\n");
            exit(0);
        }
        ((*db)->sizeofFinalArray)++;
        (*db)->finalArr[(*db)->sizeofFinalArray - 1] = *item;
    } else {
        for (int i =0; i < (*db)->sizeofFinalArray && flag == 0; i++) {
            if( (*item)->num == (*db)->finalArr[i]->num ) {
                flag = 1;
            }
        }
        if(flag == 0) {
            ((*db)->sizeofFinalArray)++;
            Item** tmp = (Item**)realloc((*db)->finalArr, (*db)->sizeofFinalArray * sizeof(Item*));
            if(tmp == NULL) { 
                printf("Memory not allocated.\n");
                exit(0);
            }
            (*db)->finalArr = tmp;
            (*db)->finalArr[(*db)->sizeofFinalArray - 1] = *item;
        }
    }
}
void InsertItem(LinkedList** list, Item **item) {
    while((*list)->next != NULL) {
        (*list) = (*list)->next;
    }
    LinkedList *temp =(LinkedList*)malloc(sizeof(LinkedList));
    if(temp == NULL) { 
        printf("Memory not allocated.\n");
        exit(0);
    }
    temp->next = NULL;
    temp->item = *item;
    (*list)->next =  temp;
}
void updateValueInList(Item** item, int* index) {
    int *tmp = (int*)realloc((*item)->indices, (((*item)->occurences) + 1) * sizeof(int));
    if(tmp == NULL) {
        printf("Memory not allocated.\n");
            exit(0);
    }
    int j = (*item)->occurences;
    tmp[j] = *index;
    (*item)->indices = tmp;
    (*item)->occurences ++;
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
    db->finalArr = NULL;
    db->table = NULL;
    db->sizeofFinalArray = 0;
    return db;
}
DataBase* initializeArr(size_t *arrSize,DataBase *db) {
    Item** arrn = NULL;
    arrn = (Item**) realloc(db->finalArr,(*arrSize)*sizeof(Item*));
    if(arrn == NULL) {
        printf("memory allocation failed");
        exit(0);
    }
    db->finalArr = arrn;
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
}
int generateHashCode(int num) {
    return (num%10+10)%10;
}
void printRes(DataBase *db) {
    int i = 0;
    if(db->finalArr == NULL) {
        printf("no duplicates given\n");
    } else {

        for (; i < db->sizeofFinalArray; i++) {
            printf("the number : %d ", db->finalArr[i]->num);
            printf("has shown %d times ", db->finalArr[i]->occurences);
            printf("in indeces:" );
            printIndeces(&(db->finalArr[i]->occurences), db->finalArr[i]->indices);
        }
    }
}
void printIndeces(const short unsigned *occurences, int* indeces) {
    int i =0;
    printf("%d", indeces[i]);
    i++;
    while (i < (*occurences) ) {
        printf(", %d", *(indeces + i));
        i++;
    }
    printf("\n");
}
void freeHash(DataBase** db) {
    if((*db)->table != NULL) {
        int i = 0;
        for (i = 0; i < 10; i++) {
            deleteList(&(*db)->table->list[i]);
        }
        free((*db)->table->list);
        (*db)->table->list = NULL;
    }
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
    free(current->item->indices);
    current->item->indices = NULL;
    free(current->item);
    current->item = NULL;
    free(*head);
    *head = NULL;
}
void clearString(char *str) {
    free(str);
    str = NULL;
}