#include "ex5.h"
//Write a program to get 5 elements in an array and get a number to be multiplied with the array elements
void mission1Menu() {
    int i = 0, num = 0;
    int arr[ARR_SIZE];
    while (i < ARR_SIZE) {
        printf("enter %d element:\n",i + 1);
        scanf("%d", (arr + i));
        i++;
    }
    printf("enter num to be multiplied with:");
    scanf("%d", &num);
    for (int j = 0; j < 6; j ++ ) {
        mult(&arr[j], num);
    }
    printArr(arr);
}
void mult(int* num, int multWithNum) {
    *num = *num * multWithNum;
}
void printArr(int* arr) {
    for (int i = 0; i < ARR_SIZE ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


//Write a program that lets the user enter the total rainfall for each of 12 months in an array.
// The program should calculate and display the total rainfall for the year, the average monthly rainfall, and the months with the highest and lowest amount of rainfall
void mission2Menu() {
    int highest =  0, lowest = 0;
    int rainFall[MONTHS];
    setArr(rainFall, &highest, &lowest);
}
void setArr(int *arrptr, int *highest, int *lowest) {
    int i = 0;
    for (; i < MONTHS; i++) {

        printf("enter rainfall metere for month ");
        switch (i) {
            case Jan:
                printf("Jan:");
                break;
            case Feb:
                printf("Feb:");
                break;
            case Mar:
                printf("Mar:");
                break;
            case Apr:
                printf("Apr:");
                break;
            case May:
                printf("May:");
                break;
            case Jun:
                printf("Jun:");
                break;
            case Jul:
                printf("Jul:");
                break;
            case Aug:
                printf("Aug:");
                break;
            case Sep:
                printf("Sep:");
                break;
            case Oct:
                printf("Oct:");
                break;
            case Nov:
                printf("Nov:");
                break;
            case Dec:
                printf("Dec:");
                break;
        }
        do {
            scanf("%d", arrptr + i);
        } while (arrptr[i] < 0);
        if(*highest < arrptr[i]) {
            *highest = arrptr[i];
        }
        if (i == 0 || *lowest > arrptr[i] ) {
            *lowest = arrptr[i];
        }
    }
    printResformission2(arrptr, highest, lowest);
}
void printResformission2(int *arrptr, int *highest, int *lowest) {
    int i = 0, total = 0;
    double avg = 0;
    while (i < MONTHS) {
        total += arrptr[i];
        i++;
    }
    avg = (total / (double)MONTHS);
    printf("total is %d, avg is %f, highest is %d, lowest is %d\n", total, avg, *highest, *lowest);
}
//Write a program to find the similar elements in an array and find its occurrence. Display the array element, index of the element and its number of occurrence.
void mission3Menu() {
    char *buffer;
    size_t siz = 255;
    DataBase* db = NULL;
    buffer = (char *)malloc(siz * sizeof(char));
    getchar(); //dummy
    printf("enter elements one by one seperated wiht spaces, press \"enter\" to finish: \n");
    getline(&buffer, &siz, stdin);
    db = initializeDB();
    db = EnterNumbersToDB(db, buffer);
    clearString(buffer);
}
void clearString(char *str) {
    free(str);
    str = NULL;
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
      db->initialArr = initializeArr(&count, db->initialArr);
      db -> initialArr[count] = num;
      token = strtok(NULL, delim);
   }
   db->finalArr = initializeArr(&count, db->finalArr);
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
    return db;
}
int* initializeArr(size_t *arrSize, int* arr) {
    arr = (int*)realloc(arr, (*arrSize)*sizeof(int));
    return arr;
}


