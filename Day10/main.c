#include <stdio.h>
#include <malloc.h>
#include <string.h>

//#define TEST_MODE 1

#ifdef TEST_MODE
#define DATA_FILE "testData.txt"
#endif

#ifndef TEST_MODE
#define DATA_FILE "realData.txt"
#endif


int main() {
    int regX = 1;
    int isPending = 0;
    int pendingVal = 0;
    int cycleNum = 1;
    int total = 0;
    int nextCycleCheck = 20;
    char line[100];
    char instruction [20];
    int val;

    FILE *fp = fopen (DATA_FILE, "r");

    while (fgets(line, 100, fp) != NULL){


        cycleNum++;

        printf ("cycle %d, regX = %d\n", cycleNum, regX);

        if (cycleNum == nextCycleCheck){
            int newVal = regX * cycleNum;
            total += newVal;

            printf ("cycle %d, regX = %d, adding %d total = %d\n", cycleNum, regX, newVal, total);
            nextCycleCheck += 40;
        }

        if (strncmp(line, "addx", 4) == 0) {
            cycleNum++;
            regX += atoi(&line[5]);
            if (cycleNum == nextCycleCheck){
                int newVal = regX * cycleNum;
                total += newVal;

                printf ("cycle %d, regX = %d, adding %d total = %d\n", cycleNum, regX, newVal, total);
                nextCycleCheck += 40;
            }

        }


    }


    printf("val = %d", total);

    return 0;
}
