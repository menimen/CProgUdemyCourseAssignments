#include "../include/ex5.h"
#include "../include/task1.h"
#include "../include/task2.h"
#include "../include/task3.h"
#include "../include/task3Structs.h"
int main(){

    int missionNum = 1;
    while(missionNum >=1 && missionNum<=6) {
        printf("choose mission 1-6. other digit terminates the program\n");
        scanf("%d", &missionNum);
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
            //mission4Menu();
            break;
        default:
            break;
        }
    }
    return 0;
}