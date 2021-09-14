#include "../include/task8.h"
//Write a program that replaces two or more consecutive blanks in a string by a single blank
void mission8Menu() {
    char *str;
    str = getstring();
    clearSpaces(str);
    printString(str);
    clearString(str);
}
void clearSpaces(char* str) {
    int start = 0, end = 0;
    //char c;
    // Sanity checks
    if(str == NULL) {
        return;
    }
    while (str[end] != '\0') {
        //if you encounter multiple spaces then do this
        if(str[end] == ' ' && str[end + 1] != '\0' && str[end + 1] == ' ') {
            end = end + 2;
            //keep incrementing end until you pass the spaces segment
            while(str[end] != '\0' && str[end] == ' ') {
                end++;
            }
            //take on space and put it at start index, then increment start
            str[start] = str[end-1];
            start++;
        }
        //overwrite the value at start index with value at end index
        str[start] = str[end];
        if(str[end] != '\0') {
            end++;
        }
        if(str[start] != '\0') {
            start++;
        }
    }
    str[start] = '\0';
}