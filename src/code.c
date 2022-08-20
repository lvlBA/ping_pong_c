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
int count1 = 0;
int count2 = 0;
int main() {
    while (count1 != 21 && count2 != 21) {
        draw();
        getchar();
        switch (refresh(0, 0)) {
            case -1:
                count1++;
                break;
            case  1:
                count2++;
                break;
        }
    }
    draw();
    printf("The game is finished player number %d WIN", count1 > count2 ? 1 : 2);
    return 0;
}

void draw() {
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            if (i == 0 || i == height || j == 0 || j == width)
                printf("#");
            else if (i == ball_y && j == ball_x)
                printf("*");
            else if (j == 40 && i > 0 && i < height)
                printf("|");
            else if (i == 3 && j == 37)
                printf("%d", count1 / 10);
            else if (i == 3 && j == 38)
                printf("%d", count1 % 10);
            else if (i == 3 && j == 42)
                printf("%d", count2 / 10);
            else if (i == 3 && j == 43)
                printf("%d", count2 % 10);
            else if (i >= rocket1_y && rocket1_y + 2 >= i && j == rocket1_x) printf("|");
            else if (i >= rocket2_y && rocket2_y + 2 >= i && j == rocket2_x) printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
}

