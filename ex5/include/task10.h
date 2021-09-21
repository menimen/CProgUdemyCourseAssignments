#ifndef task10_H
#define task10_H
#define QUANTITYOFDIFFERENTTYPES 3
#define TAX 0.05
#define QUANTITYOFEGGS 2
#define QUANTITYOFSIDES 4
#define QUANTITYOFDRINKS 2
#include "ex5.h"
#include "task10Structs.h"
void mission10Menu();
double CalcTax(double *check);
void printCheck(Order** finalOrder);
void ShowMenu(BreakFastMenu* breakfast, Type type);
BreakFastMenu* getData();
void clearMenu(menuItemType*** menu);
void clearOrder(Order*** order);
void clearSidesMenu(Ittem*** menutype);
void clearEggsMenu(Ittem*** menutype);
void clearDrinkMenu(Ittem*** menutype);
void clearBreakfastMenu(BreakFastMenu** breakfast);
void placeOrder(BreakFastMenu* breakfast, Type type);
#endif