#include <stdio.h>

int main() {
    int testcase;
    scanf("%d", &testcase);

    int sample, sample_st2, sample_rest, rest_leangth, temp_rest, temp, sample_leangth, devisor;

    for(int t = 0; t < testcase; t++) {
        scanf("%d", &sample);

        // get sample leangth
        temp = sample;
        sample_leangth = 0;

        while(temp != 0){
            temp /= 10;
            sample_leangth++;
        }

        // get 1st 2 number
        devisor = 1;
        for(int i = 0; i < sample_leangth - 2; i++){
            devisor *= 10;
        }

        sample_st2 = sample / devisor;

        // get the rest nubers
        sample_rest = sample % devisor;

        if(sample_st2 == 10){
            if(sample_rest >= 2){
                rest_leangth = 0;
                temp_rest = sample_rest;

                while(temp_rest != 0){
                    temp_rest /= 10;
                    rest_leangth++;
                }

                if((sample_leangth - 2) == rest_leangth){
                    printf("YES\n");
                }else{
                    printf("NO\n");
                }

            }else{
                printf("NO\n");
            }
        }else{
            printf("NO\n");
        }


        // debug
        // printf("Sampel: %d\n", sample);
        // printf("Sampel leangth: %d\n", sample_leangth);
        // printf("Sampel 1st 2: %d\n", sample_st2);
        // printf("Sampel rest: %d\n", sample_rest);

    }


    return 0;
}