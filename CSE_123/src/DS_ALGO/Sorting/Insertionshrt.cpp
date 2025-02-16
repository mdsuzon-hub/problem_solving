# include <stdio.h>
# include <iostream>

using namespace std;

void insertion_sort(int *array, int size){      // Insertion Sort O(n^2)
    int temp;
    for(int i = 1; i < size; i++){
        for(int j = size - (size - i); j > 0; j--){
            if(array[j] < array[j - 1]){
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
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
    insertion_sort(array, size);
    print_array(array, size);
}