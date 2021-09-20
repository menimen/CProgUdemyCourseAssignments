#include "../include/task1.h"
#include "../include/task2.h"
#include "../include/task4.h"
#include "../include/task3.h"
#include "../include/task3Structs.h"
#include "../include/task5.h"
#include "../include/task6.h"
#include "../include/task7.h"
#include "../include/task8.h"
#include "../include/task9.h"
#include "../include/task10.h"
#include "../include/task11.h"
int main(){
    int missionNum = 1;
    Library* lib = NULL;
    lib = InitializeLibrary();
    while(missionNum >=1 && missionNum<=11) {
        printf("choose mission 1-11. other digit terminates the program\n");
        scanf("%d", &missionNum);
        getchar(); //dummy
        switch (missionNum)
        {
        case 1:
            mission1Menu();
            break;
        case 2:
            mission2Menu();
            break;
        case 3:
            mission3Menu();
            break;
        case 4: 
            mission4Menu();
            break;
        case 5:
            mission5Menu();
            break;
        case 6:
            mission6Menu();
            break;
        case 7:
            mission7Menu();
            break;
        case 8:
            mission8Menu();
            break;
        case 9:
            mission9Menu();
            break;
        case 10:
            mission10Menu();
            break;
        case 11:
            mission11Menu(&lib);
            break;
        default:
            break;
        }
    }
    clearLibrary(&lib);
    return 0;
}