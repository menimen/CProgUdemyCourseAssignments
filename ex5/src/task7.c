#include "../include/task7.h"
//Write a program that converts all lowercase characters
//in a given string to its equivalent uppercase character.
void mission7Menu() {
    char *str = NULL;
    str = getstring();
    changeToUpper(str);
    printString(str);
    clearString(str);
}
void changeToUpper(char * str) {
    while (*str != '\0') {
        if (*str >='a' && *str <='z') {
            *str = *str - 32;
        }
        str++;
    }
}