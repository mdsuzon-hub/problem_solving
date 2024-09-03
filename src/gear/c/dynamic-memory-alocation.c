#include <stdio.h>
#include <stdlib.h>

int operate_task(int *sum, int *subpoints, int *dynamic_array){ //operate task after scaning data array
    for(int i = 0; i < *subpoints; i++){
        if (i % 2 != 0) {
            *sum -= dynamic_array[i];
        } else {
            *sum += dynamic_array[i];
        }
    }
}

int main() {
    int *dynamic_array;

    int testcase, subpoints;
    int sum = 0;

    scanf("%d", &testcase);
    for(int i = 0; i < testcase; i++){
        scanf("%d", &subpoints);
        for(int j = 0; j < subpoints; j++){
           if(j != 0){
                dynamic_array = (int *)realloc(dynamic_array, subpoints * sizeof(int));
           }else{
                dynamic_array = (int *)calloc(subpoints, sizeof(int));
           }

           scanf("%d", &dynamic_array[j]);
        }

        operate_task(&sum, &subpoints, dynamic_array);

        printf("%d\n", sum);

        sum = 0;
    }

    free(dynamic_array);

    return 0;
}