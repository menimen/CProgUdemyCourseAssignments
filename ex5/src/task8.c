#include "../include/task8.h"
//
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
        if(str[end] == ' ' && str[end + 1] != '\0' && str[end + 1] == ' ') {
            end = end+2;
            while(str[end] != '\0' && str[end] == ' ') {
                end++;
            }
            str[start] = str[end-1];
            start++;
        }
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