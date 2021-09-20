#include "../include/task6.h"
// Write a C program to accept a string and perform the following operations without using any string functions:
// Print the length of the string
// Print the reverse of the string
// Copy the string to another new string
void mission6Menu() {
    char* str = NULL, *str2 = NULL;
    str = getstring();
    printString(str);
    printReverseString(str);
    str2 = StrCopy(str);
    printString(str2);
    clearString(str);
    clearString(str2);
}
char* getstring() {
    char *buffer;
    int siz = 100;
    buffer = (char *)malloc(siz * sizeof(char));
    if (buffer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    printf("enter string:");
    fgets(buffer, siz, stdin);
    char* ptr = buffer;
    while(*ptr != '\n') {
        ptr++;
    }
    *ptr = '\0';
    return buffer;
}
void printString(char* str) {
    int i = 0;
    while (*str != '\0') {
        printf("%c", *str);
        str++;
        i++;
    }
    printf("\n");
    printf("length of string is %d", i);
}
void printReverseString(char* str) {
    char* tmp = str;
    int count = 0;
    while (*tmp != '\0') {
        tmp++;
        count++;
    }
    while (count >= 0)
    {
        printf("%c",str[count]);
        count--;
    }
    printf("\n");
}
char* StrCopy(char *str) {
    char* tmp = str;
    int count = 0, i = 0;
    while (*tmp != '\0') {
        tmp++;
        count++;
    }
    char* dst = (char*)malloc((count+1) * sizeof(char));
    while(str[i] != '\0') {
        dst[i] = str[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}