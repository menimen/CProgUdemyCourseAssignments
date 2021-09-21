#ifndef task10Structs_H
#define task10Structs_H
typedef enum Type{
    eggs,
    sides,
    drink
}Type;
typedef struct Ittem
{
    double Price;
    char* description;
}Ittem;
typedef struct Order {
    int amount;
    Ittem* item;
}Order;

typedef struct menuItemType
{
    Type type;
    Ittem** items;
}menuItemType;
typedef struct BreakFastMenu{
    menuItemType** menuList;
    Order** order;
}BreakFastMenu;
#endif