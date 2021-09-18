#include "../include/task9.h"
//Write a program to arrange a set of fruit names given below in lexicographically sorted order
//Mango, Banana, Apple, Orange, Grapes, Coconut, Watermelon , Papaya
void mission9Menu() {
    char * str = NULL;
    char **arr = NULL;
    int arr_size = 0;
    LinkedListForTask9** list = NULL;
    list = initializeLinkedListForTask9();
    str = getstring();
    ParseLine(&arr, &arr_size, str, ", ");
    //printCharPointerArray(arr,&arr_size);
    AssignPointersToNodes(arr,&arr_size, list);
    printTask9Res(list,1);
    clearCharPointerArr(&arr, &arr_size);
    clearLinkedListArray(list);
    free(list);
    clearString(str);
}
void clearLinkedListArray(LinkedListForTask9** list) {
    for (int i = 0; i < ALPHABETSIZE; i++) {
        if(list[i] != NULL) {
            clearLinkedList(&(list[i])); 
            list[i] = NULL;
        }
    }
}
void clearLinkedList(LinkedListForTask9** head) {
    LinkedListForTask9* cur = NULL;
    while((*head) != NULL) {
        cur = (*head) -> next;
        free(*head);
        *head = cur;
    }
}
void AssignPointersToNodes(char **arr, int *arr_size, LinkedListForTask9** list) {
    char *str;
    int AsciiVal = 0;
    LinkedListForTask9* tmp;
    for(int i = 0; i < *arr_size; i++) {
        str = arr[i];
        AsciiVal = (int)(str[0]) - 97;
        tmp = createNode(&(arr[i]));
        insertNode(&(list[AsciiVal]), &tmp);
    }    
}
void printCharPointerArray(char** arr, int * arr_size) {
    int i = 0;
    for(; i < *arr_size; i++) {
        printf("%s\n", arr[i]);
    }
}
LinkedListForTask9* createNode(char** str) {
    LinkedListForTask9* tmp = (LinkedListForTask9*)malloc(sizeof(LinkedListForTask9));
    if(tmp == NULL) {
        printf("allocation of node failed\n");
        exit(0);
    }
    tmp->str = *str;
    tmp->next  = NULL;
    return tmp;
}
//parse given string with known delimeter and assign sub string from line into char pointer array
void ParseLine(char ***arr, int* arr_size, char *str, const char* delim) {
    char* token;
    int index = 0;
    token = strtok(str, delim);
   
   /* walk through other tokens */
    while( token != NULL ) {
        //num = atoi(token);
        //EnterNumbersToHash(&db, &num, &index);
        AllocateStringandAssignPointerToitFromCharPointerArray(arr, arr_size, token, &index);
        index++;
        token = strtok(NULL, delim);
   }
}
void AllocateStringandAssignPointerToitFromCharPointerArray(char ***arr,int *arr_size,  char *substring, int *index) {
    if( *index >= *arr_size) {
        *arr_size = initializecharPointerArray(arr, arr_size);
    }
    int i = strlen(substring);
    //arr = (char**)malloc(5*sizeof(char));
    (*arr)[*index] = (char*)malloc((i+1) * sizeof(char));
    if((*arr)[*index] == NULL) {
        printf("allocation of string failed\n");
        exit(0);
    } else {
        strcpy((*arr)[*index], substring);
        char *ptr = (*arr)[*index];
        ptr[i] = '\0';
    }
}
//initialize char pointer array with extra 5 spaces ahead
int initializecharPointerArray(char ***arr, int *arr_size) {
    char **tmp = (char**)realloc(*arr, ((*arr_size) + 1) * sizeof(char*) );
    if(tmp == NULL) {
        printf("allocation of char pointer array failed\n");
        clearCharPointerArr(arr,arr_size);
        exit(0);
    }
    *arr = tmp;
    return ((*arr_size) + 1);
}
void insertNode(LinkedListForTask9** head, LinkedListForTask9** node) {
    int flag = 0;
    LinkedListForTask9** cur = head;
    LinkedListForTask9** prev = head;
    if(*cur == NULL) {
        *head = *node;
    } else {
        while((*cur) != NULL && flag == 0) {
            int res = strcmp((*cur)->str,(*node)->str);
            if(res > 0 ) {
                if(*cur == *head) {
                    (*node)->next = (*cur);
                    *head = *node;
                } else {
                    (*node)->next = (*cur);
                    (*prev)->next = *node;
                }
                flag = 1;
            }
            prev = cur;
            cur = &((*cur)->next);
        }
        if(flag == 0) {
            (*prev)->next = *node;
        }
    }
}
void clearCharPointerArr(char*** arr, int *arr_size) {
    for(int i = 0; i < *arr_size; i++) {
        free((*arr)[i]);
    }
    free(*arr);
    *arr = NULL;
}
LinkedListForTask9** initializeLinkedListForTask9() {
    LinkedListForTask9** tmp = (LinkedListForTask9**)malloc(ALPHABETSIZE * sizeof(LinkedListForTask9*));
    if(tmp == NULL) {
        printf("allocation failed at initialization of linked list array\n");
        exit(0);
    } else {
        for (int i = 0; i < ALPHABETSIZE; i++) {
            tmp[i] = NULL;
        }
    }
    return tmp;
}
//print the contents of LinkedList according to given order. 1 is from A to Z, 0 otherwise
void printTask9Res(LinkedListForTask9** list, int direction) {
    if(direction) {
        printfromAtoZ(list);
    } else {
        printfromZtoA(list);
    }
}
void printfromAtoZ(LinkedListForTask9** list) {
    LinkedListForTask9* head = NULL;
    for(int i = 0; i < ALPHABETSIZE; i++) {
        head = list[i];
        while(head != NULL) {
            printf("%s ", head->str);
            head = head->next;
        }
    }
    printf("\n");
}
void printfromZtoA(LinkedListForTask9** list) {
    LinkedListForTask9* head = NULL;
    for(int i = ALPHABETSIZE - 1; i >= 0; i--) {
        head = list[i];
        while(head != NULL) {
            printf("%s ", head->str);
            head = head->next;
        }
    }
    printf("\n");
}

