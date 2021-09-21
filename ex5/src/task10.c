#include "../include/task10.h"
/*Write a program to help a local restaurant automate its breakfast billing system. The program should do the following:
a. Show the customer the different breakfast items offered by the restaurant.
b. Allow the customer to select more than one item from the menu.
c. Calculate and print the bill.
Assume that the restaurant offers the following breakfast items (the price
of each item is shown to the right of the item):
Plain Egg $1.45
Bacon and Egg $2.45
Muffin $0.99
French Toast $1.99
Fruit Basket $2.49
Cereal $0.69
Coffee $0.50
Tea $0.75
Use an array, menuList, of the struct menuItemType,
Your program must contain at least the following functions:
• Function getData: This function loads the data into the array menuList.
• Function showMenu: This function shows the different items offered by the restaurant and tells the user how to select the items.
• Function printCheck: This function calculates and prints the check.
(Note that the billing amount should include a 5% tax.)
A sample output is:
Welcome to Johnny's Restaurant
Bacon and Egg $2.45
Muffin $0.99
Coffee $0.50
Tax $0.20
Amount Due $4.14
Format your output with two decimal places. The name of each item in the
output must be left justified. You may assume that the user selects only one item of a particular type.
The customer can select multiple items of a particular type. A sample output in this case is:
Welcome to Johnny's Restaurant
1 Bacon and Egg $2.45
2 Muffin $1.98
1 Coffee $0.50
Tax $0.25
Amount Due $5.18*/
void mission10Menu(){
    BreakFastMenu* BreakFastmenu = getData();
    printf("Welcome to Johnny's Restaurant.\n");
    printf("Choose Eggs option number: \n");
    ShowMenu(BreakFastmenu, eggs);
    placeOrder(BreakFastmenu, eggs);
    printf("Choose Side option number: \n");
    ShowMenu(BreakFastmenu, sides);
    placeOrder(BreakFastmenu, sides);
    printf("Choose Drink option number: \n");
    ShowMenu(BreakFastmenu, drink);
    placeOrder(BreakFastmenu, drink);
    printCheck(BreakFastmenu->order);
    clearBreakfastMenu(&BreakFastmenu);
}
void placeOrder(BreakFastMenu* breakfast, Type type) {
    int option = 0;
    int amount = 0;
    scanf("%d", &option);
    printf("choose amount: ");
    scanf("%d", &amount);
    switch (type)
    {
    case eggs:
        breakfast->order[eggs]->item = breakfast->menuList[eggs]->items[option - 1];
        breakfast->order[eggs]->amount = amount;
        break;
    case sides:
        breakfast->order[sides]->item = breakfast->menuList[sides]->items[option - 1];
        breakfast->order[sides]->amount = amount;
        break;
    case drink:
        breakfast->order[drink]->item = breakfast->menuList[drink]->items[option - 1];
        breakfast->order[drink]->amount = amount;
        break;
    default:
        break;
    }
}
double CalcTax(double *check) {
    return (*check)*TAX;
}
void printCheck(Order** finalOrder) {
    double Check = 0 , midCheck = 0;
    for (int i = 0; i < QUANTITYOFDIFFERENTTYPES; i++) {
        midCheck = (finalOrder[i]->item->Price)*(finalOrder[i]->amount);
        printf("%d %s $%.2f\n", finalOrder[i]->amount, finalOrder[i]->item->description, midCheck);
        Check += midCheck;
    }
    printf("Tax: %.2f\n", CalcTax(&Check));
    printf("Amount Due $%.2f\n", Check+CalcTax(&Check));
}
void ShowMenu(BreakFastMenu* breakfast, Type type) {
    int i = 0, j = 0;
    switch (type)
    {
    case eggs:
        j = 0;
        for(; i < QUANTITYOFEGGS; i++) {
            printf("%d-%s %.2f\n",i+1, breakfast->menuList[j] ->items[i]->description, breakfast->menuList[j] ->items[i]->Price);
        }
        break;
    case sides:
        j = 1;
        for(; i < QUANTITYOFSIDES; i++) {
            printf("%d-%s %.2f\n",i+1, breakfast->menuList[j] ->items[i]->description, breakfast->menuList[j] ->items[i]->Price);
        }
        break;
    case drink:
        j = 2;
        for(; i < QUANTITYOFDRINKS; i++) {
            printf("%d-%s %.2f\n",i+1, breakfast->menuList[j] ->items[i]->description, breakfast->menuList[j] ->items[i]->Price);
        }
        break;
    default:
        break;
    }
}
BreakFastMenu* getData() {
    BreakFastMenu* tmp = (BreakFastMenu*)malloc(sizeof(BreakFastMenu));
    tmp->menuList = (menuItemType**)malloc(QUANTITYOFDIFFERENTTYPES * sizeof(menuItemType*));
    for (int i = 0; i < QUANTITYOFDIFFERENTTYPES; i++) {
        (tmp->menuList)[i] = (menuItemType*)malloc(sizeof(menuItemType));
    }
    (tmp->menuList)[0]->type = eggs;
    (tmp->menuList)[0]->items = (Ittem**)malloc(QUANTITYOFEGGS * sizeof(Ittem*));

    ((tmp->menuList)[0]->items[0]) = (Ittem*)malloc(sizeof(Ittem));
    ((tmp->menuList)[0]->items[0]) ->Price = 1.45;
    (tmp->menuList)[0]->items[0] ->description = "Plain Egg";
    ((tmp->menuList)[0]->items[1]) = (Ittem*)malloc(sizeof(Ittem));
    (tmp->menuList)[0]->items[1] ->Price = 2.45;
    (tmp->menuList)[0]->items[1] ->description = "Bacon And Egg";

    (tmp->menuList)[1]->type = sides;
    (tmp->menuList)[1]->items = (Ittem**)malloc(QUANTITYOFSIDES * sizeof(Ittem*));

    ((tmp->menuList)[1]->items[0]) = (Ittem*)malloc(sizeof(Ittem));
    (tmp->menuList)[1]->items[0] ->Price = 0.99;
    (tmp->menuList)[1]->items[0] ->description = "Muffin";

    ((tmp->menuList)[1]->items[1]) = (Ittem*)malloc(sizeof(Ittem));
    (tmp->menuList)[1]->items[1] ->Price = 1.99;
    (tmp->menuList)[1]->items[1] ->description = "French Toast";

    ((tmp->menuList)[1]->items[2]) = (Ittem*)malloc(sizeof(Ittem));
    (tmp->menuList)[1]->items[2] ->Price = 2.49;
    (tmp->menuList)[1]->items[2] ->description = "Fruit Basket";

    ((tmp->menuList)[1]->items[3]) = (Ittem*)malloc(sizeof(Ittem));
    (tmp->menuList)[1]->items[3] ->Price = 0.69;
    (tmp->menuList)[1]->items[3] ->description = "Cereal";


    (tmp->menuList)[2]->type = drink;
    (tmp->menuList)[2]->items = (Ittem**)malloc(QUANTITYOFDRINKS * sizeof(Ittem*));

    ((tmp->menuList)[2]->items[0]) = (Ittem*)malloc(sizeof(Ittem));
    (tmp->menuList)[2]->items[0] ->Price = 0.5;
    (tmp->menuList)[2]->items[0] ->description = "Coffee";

    ((tmp->menuList)[2]->items[1]) = (Ittem*)malloc(sizeof(Ittem));
    (tmp->menuList)[2]->items[1] ->Price = 0.75;
    (tmp->menuList)[2]->items[1] ->description = "Tea";


    tmp->order = (Order**)malloc(QUANTITYOFDIFFERENTTYPES * sizeof(Order*));
    if(tmp->order == NULL) {
        printf("allocation of order array has failed\n");
        exit(0);
    }
    tmp->order[eggs] = (Order*)malloc(sizeof(Order));
    if(tmp->order[eggs] == NULL) {
        printf("allocation of order array has failed\n");
        exit(0);
    }
    tmp->order[sides] = (Order*)malloc(sizeof(Order));
    if(tmp->order[sides] == NULL) {
        printf("allocation of order array has failed\n");
        exit(0);
    }
    tmp->order[drink] = (Order*)malloc(sizeof(Order));
    if(tmp->order[drink] == NULL) {
        printf("allocation of order array has failed\n");
        exit(0);
    }


    return tmp;
}
void clearOrder(Order*** order) {
    for(int i =0; i < QUANTITYOFDIFFERENTTYPES; i++) {
        free((*order)[i]);
        (*order)[i] = NULL;
    }
}
void clearMenu(menuItemType*** menu) {
    Type type = eggs;
    clearEggsMenu(&((*menu)[type]->items));
    free((*menu)[type]->items);
    (*menu)[type]->items =NULL;
    free((*menu)[type]);
    (*menu)[type] = NULL;

    type = sides;
    clearSidesMenu(&((*menu)[type]->items));
    free((*menu)[type]->items);
    (*menu)[type]->items =NULL;
    free((*menu)[type]);
    (*menu)[type] = NULL;

    type = drink;
    clearDrinkMenu(&((*menu)[type]->items));
    free((*menu)[type]->items);
    (*menu)[type]->items =NULL;
    free((*menu)[type]);
    (*menu)[type] = NULL;
}
void clearDrinkMenu(Ittem*** menutype) {
    for(int i = 0; i < QUANTITYOFDRINKS; i++) {
        free((*menutype)[i]);
        (*menutype)[i] = NULL;
    }
}
void clearEggsMenu(Ittem*** menutype) {
    for(int i = 0; i < QUANTITYOFEGGS; i++) {
        free((*menutype)[i]);
        (*menutype)[i] = NULL;
    }
}
void clearSidesMenu(Ittem*** menutype) {
    for(int i = 0; i < QUANTITYOFSIDES; i++) {
        free((*menutype)[i]);
        (*menutype)[i] = NULL;
    }
}
void clearBreakfastMenu(BreakFastMenu** breakfast) {
    /*free( (*breakfast)->order[0]);
    (*breakfast)->order[0] = NULL;
    free( (*breakfast)->order[1]);
    (*breakfast)->order[1] = NULL;
    free( (*breakfast)->order[2]);
    (*breakfast)->order[2] = NULL;

    free( (*breakfast)->order );


    free((*breakfast)->menuList[0]->items[0]);
    (*breakfast)->menuList[0]->items[0] = NULL;
    free((*breakfast)->menuList[0]->items[1]);
    ((*breakfast)->menuList[0]->items[1]) = NULL;
    free((*breakfast)->menuList[1]->items[0]);
    ((*breakfast)->menuList[1]->items[0]) = NULL;
    free((*breakfast)->menuList[1]->items[1]);
    ((*breakfast)->menuList[1]->items[1]) = NULL;
    free((*breakfast)->menuList[1]->items[2]);
    ((*breakfast)->menuList[1]->items[2]) = NULL;
    free((*breakfast)->menuList[1]->items[3]);
    ((*breakfast)->menuList[1]->items[3]) = NULL;
    free((*breakfast)->menuList[2]->items[0]);
    ((*breakfast)->menuList[2]->items[0]) = NULL;
    free((*breakfast)->menuList[2]->items[1]);
    ((*breakfast)->menuList[2]->items[1]) = NULL;

    free((*breakfast)->menuList[0]->items);
    (*breakfast)->menuList[0]->items =NULL;
    free((*breakfast)->menuList[1]->items);
    (*breakfast)->menuList[1]->items = NULL;
    free((*breakfast)->menuList[2]->items);
    (*breakfast)->menuList[2]->items =NULL;
    
    
    
    free((*breakfast)->menuList[0]);
    (*breakfast)->menuList[0] =NULL;
    free((*breakfast)->menuList[1]);
    (*breakfast)->menuList[1] = NULL;
    free((*breakfast)->menuList[2]);
    (*breakfast)->menuList[2] =NULL;

    free((*breakfast)->menuList);
    (*breakfast)->menuList = NULL;

    free((*breakfast));*/
    
    
    clearOrder(&((*breakfast)->order)) ;
    free((*breakfast)->order);
    (*breakfast)->order =NULL;
    clearMenu(&((*breakfast)->menuList)) ;
    free((*breakfast)->menuList);
    (*breakfast)->menuList = NULL;
    free(*breakfast);
    *breakfast = NULL;
}
