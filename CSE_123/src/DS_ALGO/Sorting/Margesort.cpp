# include <stdio.h>
# include <iostream>

using namespace std;

void merge(int *array, int start, int sub_start, int end, int size){
    int temp[size];

    int i, j, k;
        i = start;
        j = start + sub_start;
        k = 0;

        while(i < start + sub_start  && j < end){
            if(array[i] < array[j]){
                temp[k] = array[i];
                k++;
                i++;
            }else{
                temp[k] = array[j];
                k++;
                j++;
            }
        }

        while(i < start + sub_start){
            temp[k] = array[i];
            k++;
            i++;
        }

        while(j < end){
            temp[k] = array[j];
            k++;
            j++;
        }

    for(int m = 0, n = start; m < k; m++, n++){
        array[n] = temp[m];
    }
}

void merge_sort(int *array, int start, int end, int size){
    if (size <= 1) return;

    int sub_size_1, sub_size_2;

    if(size % 2 == 0){
        sub_size_1 = sub_size_2 = size / 2;
    }else{
        sub_size_1 = size / 2;
        sub_size_2 = size - sub_size_1;
    }

    merge_sort(array, start, start + sub_size_1, sub_size_1);   // 1st half
    merge_sort(array, start + sub_size_1, end, sub_size_2);   // 2nd half

    merge(array, start, sub_size_1, end, size);
}

void print_array(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    cout << endl;
}

int main(){
    // int array[] = {4, 1, 9, 13, 4, 2, 1, 57, 57, 5, 99, 76, 45, 56, 3, 10};
    int array[] = {4, 1, 9, 13, 4};
    // int array[] = {4, 9, 2, 13};
    

    int size = sizeof(array) / sizeof(array[0]);
    int start = 0, end = size; 

    print_array(array, size);
    merge_sort(array, 0, size, size);
    print_array(array, size);
}