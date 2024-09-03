#include <stdio.h>
#include <stdlib.h>

int main() {
    int testcase;
    int passengers;
    int temp;
    int *ptr; // create a pointer

    scanf("%d", &testcase);
    for(int i = 0; i < testcase; i++){
        int error_count = 0;
        scanf("%d", &passengers);

        ptr = (int*)calloc((passengers + 1), sizeof(int)); // create a pointer array (calloc difult-0)
        
        if(ptr == NULL){ // cheack if memory alocated
            return 1;
        }

        for(int j = 1; j <= passengers; j++){
            scanf("%d", &temp);

            if(j == 1){
                ptr[temp] = temp; // when 1st person
            }else if(j > 1){
                // Check if adjacent positions are non-zero
                if ((temp > 1 && ptr[temp - 1] != 0) || (temp < passengers && ptr[temp + 1] != 0)) {
                    ptr[temp] = temp;
                } else {
                    error_count++;
                    continue;
                }
            }
        }

        if(error_count == 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

        free(ptr);
    }


    return 0;
}


