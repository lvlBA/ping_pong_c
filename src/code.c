
#include <stdio.h>
#include <refresh_state.c>
 
#define width 80
#define height 25
rocket1_x = 10;
rocket2_x = 70; 
 
int main(){
    char a, b;
    int plus, minus;
    scanf ("%c%c", &a, &b);
    if (a == 'a'|| b =='k') {
        
    }
   for (int i = 0; i< height; i++) {
       for (int j = 0; j < width; j++) {
           if (i == rocket1_y && j == rocket1_x) printf("|");
       }
       printf("\n");
   }
    
    return 0;
}
