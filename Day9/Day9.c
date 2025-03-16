#include <stdio.h>
#include <malloc.h>

//#define TEST_MODE 1

#ifdef TEST_MODE
#define DATA_FILE "testData.txt"
#endif

#ifndef TEST_MODE
#define DATA_FILE "realData.txt"
#endif

typedef struct Pos {
    int x;
    int y;
}Pos;

typedef struct NodeData {
    Pos pos;
    struct NodeData *next;
} Node;

Node *newNode (int x, int y){
    Node *ptr = malloc (sizeof(Node));

    ptr -> next = NULL;
    ptr ->pos.x = x;
    ptr ->pos.y = y;
}

void addIfUnique (int x, int y, Node * root){
    if (root ->pos.x != x || root ->pos.y != y){
        if (root ->next != NULL) {
            addIfUnique (x, y, root ->next);
        } else {
            printf ("New position added to list! (%d, %d)\n", x, y);
            root -> next = newNode(x,y);
        }
    }
}

int countNodes (Node *root){
    int count = 0;
    Node *ptr = root;

    while (ptr != NULL) {
        count++;
        ptr = ptr -> next;
    }

    return count;
}

int isTouching (Pos *head, Pos *tail){
    int xDiff = abs(head -> x - tail -> x);
    int yDiff = abs(head -> y - tail -> y);

    if (xDiff > 1 || yDiff > 1) {
        return 0;
    } else {
        return -1;
    }
}

void followOn (Pos *head, Pos *tail){
    int xDiff;
    int yDiff;

     if (!isTouching(head, tail)){
         xDiff = head -> x - tail -> x;
         yDiff = head -> y - tail -> y;
         if (yDiff > 0){
             tail -> y += 1;
         }
         if (yDiff < 0){
             tail -> y -= 1;
         }

         if (xDiff > 0){
             tail -> x += 1;
         }
         if (xDiff < 0){
             tail -> x -= 1;
         }
     }

}


int main() {
    int distance;
    char direction;
    Pos rope [10];
    Node *visitedList;
    FILE *fp = fopen (DATA_FILE, "r");
    int counter;
    int ropeCounter;

    visitedList = newNode(0,0);
    for (counter = 0; counter<10; counter++){
        rope[counter].x = 0;
        rope[counter].y = 0;
    }

    while (fscanf (fp, "%c %d\n", &direction, &distance) > 0){
        printf("instructions = %c %d\n", direction, distance);

        for (counter = 0; counter < distance; counter++){
            switch (direction){
                case 'U':
                    rope[0].y += 1;
                    break;

                case 'D':
                    rope[0].y -= 1;
                    break;

                case 'L':
                    rope[0].x -= 1;
                    break;

                case 'R':
                    rope[0].x += 1;
                    break;
            }

            for (ropeCounter = 0; ropeCounter < 9; ropeCounter++) {
                followOn(&rope[ropeCounter], &rope[ropeCounter+ 1]);
            }

            addIfUnique(rope[9].x, rope[9].y, visitedList);
        }
    }

    printf ("Unique positions = %d\n", countNodes(visitedList));

    return 0;
}
