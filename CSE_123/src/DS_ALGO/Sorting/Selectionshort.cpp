# include <stdio.h>
# include <iostream>

using namespace std;

void selection_sort(int *array, int size){
    int select, temp;
    for(int i = 0; i < size - 1; i++){
        select = i;
        for(int j = i + 1; j < size; j++){
            if(array[select] > array[j]){
                select = j;
            }
        }

        if (select != i){
            temp = array[i];
            array[i] = array[select];
            array[select] = temp;
        }
    }
}

void print_array(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    cout << endl;
}

int main(){
    int array[] = {4, 1, 9, 13, 4, 2, 1, 57, 57, 5, 99, 76, 45, 56, 3, 10};

    int size = sizeof(array) / sizeof(array[0]);
    print_array(array, size);
    selection_sort(array, size);
    print_array(array, size);
}