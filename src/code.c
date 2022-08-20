
#include <stdio.h>

 
 #define width 80
 #define height 25
 
 
int main(){
    char a, b;
    int plus, minus;
    scanf ("%c%c", &a, &b);
    if (a == 'a'|| b =='k') {
        
    }
   for (int i = 0; i< height; i++) {
       for (int j = 0; j < width; j++) {
           if (i == 0||i == height-1|| j == 0 || j == width -1) {
           printf ("#");
           } else if  ((i == 10 && j == 10) ||(i == 11 && j == 10) || (i == 12 && j == 10) || (i == 10 && j == 70) ||(i == 11 && j == 70) || (i == 12 && j == 70)) {
               printf ("|");
           } else if (i == 11 && j == 40) {
               printf ("@");
           } else {
               printf (" ");
           }
       }
       printf("\n");
   }
    
    return 0;
}
