/*
Author: Brian Jordan
Class: Computer Systems and Low Level Programming
Date: 3/3/2024
Lab 6: Race - Tortoise and the Hare
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RAND_MIN 1
#define RAND_MAX 10
#define END 70

void tortoisePosition(int *tPos);
void harePosition(int *hPos);
void winner (int *tPos, int *hPos);
void printBoard (int *tPos, int *hPos);

int main (void){
    srand((unsigned)time(NULL));

    char tortoise = 't';
    char hare = 'h';
    int tPosition = 1;
    int hPosition = 1;

    puts("\nON YOUR MARKS, GET SET\nBANG!!!\nAND THEY'RE OFF !!!\n");

    while (tPosition < 70 && hPosition < 70){
        sleep(1);
        tortoisePosition(&tPosition);

        harePosition(&hPosition);
        if (hPosition < 1){
            hPosition = 1;
        }

        if (tPosition == hPosition){
            puts("OUCH!!");
        }

        printBoard(&tPosition, &hPosition);
        puts("");
    }
    winner(&tPosition, &hPosition);

    return 0;
}


void tortoisePosition(int *tPos){
    int rng = rand() % (RAND_MAX) + RAND_MIN;
    int posMoved = 3; // automatically set for 3 squares to the right due to it being less checks

    if (rng == 6 || rng == 7){
        posMoved = 6;
    }
    if (rng == 8 || rng == 9 || rng == 10){
        posMoved = 1;
    }

    *tPos += posMoved;
}

void harePosition(int *hPos){
    int rng = rand() % (RAND_MAX) + RAND_MIN;
    int posMoved = 1; // automatically set for 1 squares to the right due to it being less checks

    if (rng == 4 || rng == 5){
        posMoved = 0;
    }
    if (rng == 6 || rng == 7){
        posMoved = 9;
    }
    if (rng == 8){
        posMoved = -12;
    }
    if (rng == 9 || rng == 10){
        posMoved = -2;
    }

    *hPos += posMoved;
}

void winner (int *tPos, int *hPos){
    if (*tPos > *hPos){
        puts ("\nTORTOISE WINS!!! YAY!!!\n");
    }
    else {
        puts("\nHare wins. YUCH\n");
    }
}

void printBoard (int *tPos, int *hPos){
    int difference = abs(*tPos - *hPos);

    if (*tPos > *hPos){
        for (int i = 1; i < *hPos; i++){
            printf("%s", " ");
        }
        printf("%s", "H");
        for (int i = 1; i < difference; i++){
            printf("%s", " ");
        }
            printf("%s", "T");

    }
    else {
        for (int i = 1; i < *tPos; i++){
            printf("%s", " ");
        }
        printf("%s", "T");
        for (int i = 1; i < difference; i++){
            printf("%s", " ");
        }
            printf("%s", "H");
    }
}

