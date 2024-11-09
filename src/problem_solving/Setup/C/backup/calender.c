#include <stdio.h>

int main() {
    int starting_year = 1970;
    int reference_year = 2023;

    int inmput_year;
    int year_stc[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year_row; //for 2023 sat starting
    int month_space_init, month_row = 0;

    // month_space_init = (reference_year - starting_year) / 4 

    scanf("%d", &inmput_year);

    // cheack if its leap YEAR
    if((inmput_year % 400 == 0) || (inmput_year % 4 == 0 && inmput_year % 100 != 0)){
        year_stc[1] = 29;
    }

    for(int i = 0; i < 12; i++){
        printf("Month %d\n", i+1);
        int prave_space_init = month_space_init;
        month_space_init = (year_stc[i] + month_space_init) - (7 * 4);

        if(month_space_init > 7){

            month_space_init = (year_stc[i] + prave_space_init) - (7 * 5);
            month_row += 6;
            printf("%d\n", 6);
        }else if(month_space_init == 0){
            month_row += 4;
            printf("%d\n", 4);
        }else{
            month_row += 5;
            printf("%d\n", 5);
        }

        if(month_space_init == 7){
            month_space_init = 0;
        }

        printf("%d\n", month_row);
        printf("%d\n\n\n", month_space_init);
    }

    return 0;
}
