# include <stdio.h>
# include <iostream>

using namespace std;

void bubble_sort(int *array, int size){     // Bubble Sort O(n^2)
    int temp, exc = 0, pass_count = 0;

    for(int i = 0; i < size - 1; i++){
        exc = 0;
        for(int j = 0; j < size - 1 - i; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                exc ++;
            }
        }
        if(exc == 0){
           break;
        }
        pass_count ++;
    }
    cout << "Pass_count " << pass_count << "." << endl;
    return;
}

void print_array(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    cout << endl;
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 9, 8};

    int size = sizeof(array) / sizeof(array[0]);
    print_array(array, size);
    bubble_sort(array, size);
    print_array(array, size);
}
