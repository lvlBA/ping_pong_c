#include <stdio.h>

extern const int width;
extern const int height;
extern const int rocket1_x;
extern int rocket1_y;
extern const int rocket2_x;
extern int rocket2_y;
extern int ball_x;
extern int ball_y;
// ball_direction : 0 - top-right, 1 - down-right, 2 - down-left, 3 - top-left
int ball_direction = 0;
void move_ball();

int refresh(int r1_offset, int r2_offset) {
    // first rocket
    rocket1_y += r1_offset;
    if (rocket1_y == 0 || rocket1_y + 2 == height) rocket1_y -= r1_offset;

    // second rocket
    rocket2_y += r2_offset;
    if (rocket2_y == 0 || rocket2_y + 2 == height) rocket2_y -= r2_offset;

    // check end of round
    switch (ball_direction) {
        case 0:
        case 1:
            if (ball_x + 1 == width) return -1;
            break;
        case 2:
        case 3:
            if (ball_x - 1 == 0) return 1;
            break;
    }

    move_ball();
    return 0;
}

void move_ball() {
    int old_x = ball_x, old_y = ball_y;
    switch (ball_direction) {
        // top-right
        case 0:
            ball_x += 1;
            ball_y -= 1;
            if (ball_x == rocket2_x && ball_y >= rocket2_y && ball_y <= rocket2_y + 2) ball_direction = 3;
            else if (ball_y == 0) ball_direction = 1;
            else
                return;
            break;
        // down-right
        case 1:
            ball_x += 1;
            ball_y += 1;
            if (ball_x == rocket2_x && ball_y >= rocket2_y && ball_y <= rocket2_y + 2) ball_direction = 2;
            else if (ball_y == height) ball_direction = 0;
            else
                return;
            break;
        // down-left
        case 2:
            ball_x -= 1;
            ball_y += 1;
            if (ball_x == rocket1_x && ball_y >= rocket1_y && ball_y <= rocket1_y + 2) ball_direction = 1;
            else if (ball_y == height) ball_direction = 3;
            else
                return;
            break;
        // top-left
        case 3:
            ball_x -= 1;
            ball_y -= 1;
            if (ball_x == rocket1_x && ball_y >= rocket1_y && ball_y <= rocket1_y + 2) ball_direction = 0;
            else if (ball_y == 0) ball_direction = 2;
            else
                return;
            break;
    }
    ball_x = old_x;
    ball_y = old_y;
    move_ball();
}
