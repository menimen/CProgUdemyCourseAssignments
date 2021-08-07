#include "ex4header.h"
int main(){
    int missionNum = 0;
    int mission1Param = 0;
    printf("choose mission 1-6. other digit terminates the program\n");
    scanf("%d", &missionNum);
    switch (missionNum)
    {
    case 1:
        mission1Menu();
        break;
    case 2:
        mission2Menu();
    default:
        break;
    }
    return 0;
}

