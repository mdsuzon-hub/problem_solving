#include <stdio.h>

int main() {
    int height_width = 8;

    // Basic Pattern Programs

    printf("     _______       __   __\n");
    printf("    |   _   .---.-|  |_|  |_.-----.----.-----.\n");
    printf("    |.  1   |  _  |   _|   _|  -__|   _|     |\n");
    printf("    |.  ____|___._|____|____|_____|__| |__|__|\n");
    printf("    |:  |  \n");
    printf("    |::.|\n");
    printf("    `---'\n");

    printf("Please enter the desired pattern dimensions as a single integer (e.g., '10' for a 10x10 pattern): ");
    scanf("%d", &height_width);

/*
    ****
    ****
    ****
    ****
*/
    for(int i = 0; i < height_width; i++){
        for(int j = 0; j < height_width; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n\n");

/*
    ****
    ***
    **
    *
*/
    for(int i = height_width; i > 0; i--){
        for(int j = i; j > 0; j--){
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n\n");

/*
    *
    **
    ***
    ****
*/
    for(int i = 0; i < height_width + 1; i++){
        for(int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n\n");

/*
    ****
     ***
      **
       *
*/
    for(int i = 0; i < height_width; i++){
        for(int k = 0; k < i; k++){
            printf(" ");
        }
        for(int j = i; j < height_width; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n\n");

/*
       *
      **
     ***
    ****
*/

    for(int i = height_width; i > 0; i--){
        for(int k = i - 1; k > 0; k--){
            printf(" ");
        }
        for(int j = height_width + 1; j > i; j--){
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n\n");

}