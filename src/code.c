#include <stdio.h>
#include <unistd.h>
#include "refresh_state.h"

void draw();
const int width = 80;
const int height = 25;
const int rocket1_x = 10;
const int rocket2_x = 70;
int rocket1_y = 12;
int rocket2_y = 12;
int ball_x = 40;
int ball_y = 13;

int main() {
    while(1) {
        draw();
        refresh(0, 0;
        getchar();
    }
    
    return 0;
}

void draw() {
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            if (i == 0||i == height|| j == 0 || j == width )
                printf ("#");
            else if (i >= rocket1_y && rocket1_y + 2 >= i && j == rocket1_x) printf("|");
            else if (i >= rocket2_y && rocket2_y + 2 >= i && j == rocket2_x) printf("|");
            else if (i == ball_y && j == ball_x) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}

