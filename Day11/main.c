#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

#define TEST_MODE 1

#ifdef TEST_MODE
#define DATA_FILE "testData.txt"
#define NUM_MONKEYS 4
#endif

#ifndef TEST_MODE
#define DATA_FILE "realData.txt"
#define NUM_MONKEYS 8
#endif

typedef struct Item_Queue {
    unsigned long long value;
    struct Item_Queue *next;
}Items;

typedef struct Monkey {
    Items *itemList;
    char operator;
    int opVal;
    int test;
    int trueMonkey;
    int falseMonkey;
    int inspectionCount;
} Monkey;

Items * enQueue (Items * head, unsigned long long val) {
    Items *newNode = malloc (sizeof(Items));
    Items *ptr;
    newNode ->next = NULL;
    newNode -> value = val;

    if (head != NULL) {
        ptr = head;
        while (ptr ->next != NULL){
            ptr = ptr -> next;
        }

        ptr -> next = newNode;
    }

    return newNode;
}


int main() {
    setbuf (stdout, NULL);
    Monkey monkeys [NUM_MONKEYS];
    int counter;
    char line[100];
    unsigned long long tmp;
    int offset;
    int round;
    int destMonkey;
    Items *ptr;
    unsigned long long max = 0;
    unsigned long long second = 0;

    FILE *fp = fopen(DATA_FILE, "r");

    for (counter = 0; counter < NUM_MONKEYS; counter++) {
        fgets (line, 100, fp);
        fgets (line, 100, fp);

        tmp = atoi (&line[18]);
        monkeys[counter].itemList = enQueue(NULL, tmp);
        offset = 18;
        while (line[offset] != '\0'){
            while (isdigit(line[offset]) || line[offset] == ','){
                offset++;
            }
            offset++;

            if (isdigit(line[offset])){
                tmp = atoi (&line[offset]);
                enQueue(monkeys[counter].itemList, tmp);
            }
        }

        fgets (line, 100, fp);
        monkeys[counter].operator = line[23];
        if (isdigit(line[25])) {
            monkeys[counter].opVal = atoi (&line[25]);
        } else {
            monkeys[counter].opVal = - 1;
        }

        fgets (line, 100, fp);
        monkeys[counter].test = atoi(&line[21]);

        fgets (line, 100, fp);
        monkeys[counter].trueMonkey = atoi(&line[29]);

        fgets (line, 100, fp);
        monkeys[counter].falseMonkey = atoi(&line[30]);

        monkeys[counter].inspectionCount = 0;

        fgets (line, 100, fp);
    }

    for (round = 1; round <= 10000; round++){
        for (counter = 0; counter < NUM_MONKEYS; counter++){
            while (monkeys[counter].itemList != NULL){
                monkeys[counter].inspectionCount++;

                long long ori = monkeys[counter].itemList -> value;

                if (monkeys[counter].opVal == -1){
                    tmp = monkeys[counter].itemList -> value;
                } else {
                    tmp = monkeys[counter].opVal;
                }
                if (monkeys[counter].operator == '+'){
                    tmp = tmp + monkeys[counter].itemList -> value;
                } else {
                    tmp = tmp * monkeys[counter].itemList -> value;
                }

                if (tmp < ori) {
                    printf ("!!! OVERFLOW round %d ori = %lldu, tmp = %lldu \n", round, ori, tmp);
                }

                //tmp /= 3;

                if (tmp % monkeys[counter].test == 0){
                    destMonkey = monkeys[counter].trueMonkey;
                } else {
                    destMonkey = monkeys[counter].falseMonkey;
                }

                if (monkeys[destMonkey].itemList == NULL){
                    monkeys[destMonkey].itemList = enQueue(NULL, tmp);
                } else {
                    enQueue (monkeys[destMonkey].itemList, tmp);
                }

                ptr = monkeys[counter].itemList;
                monkeys[counter].itemList = monkeys[counter].itemList->next;

                free(ptr);
            }
        }

        if (round % 1000 == 0 || round == 1 || round == 20){
            for (tmp = 0; tmp < NUM_MONKEYS; tmp++){
                printf("Round %d Monkey %lldu inspected %d times\n", round, tmp, monkeys[tmp].inspectionCount);
            }
            printf("\n");
        }
    }

    //I could have done this in the main loop, but hey ho
    for (counter = 0; counter < NUM_MONKEYS; counter++){
        if (monkeys[counter].inspectionCount > max){
            if (max > second) {
                second = max;
            }
            max = monkeys[counter].inspectionCount;
        } else {
            if (monkeys[counter].inspectionCount > second) {
                second = monkeys[counter].inspectionCount;
            }
        }
    }

    printf ("First = %lld, second = %lld, sum = %lld", max, second, max * second);

    return 0;
}
