# include <stdio.h>
# include <iostream>

using namespace std;

void quick_sort(int *array, int start, int end){        // Quick Short O(n^2)
    if (start >= end) return;

    int pevot = array[start];
    int left = start + 1;
    int right = end;
    int temp;

    while(left <= right){
        while (left <= right && array[left] <= pevot) left++;
        while (left <= right && array[right] > pevot) right--;

        if(left < right){
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    temp = array[start];
    array[start] = array[right];
    array[right] = temp;
    
    quick_sort(array, start, right - 1);    // Left sub array
    quick_sort(array, right + 1, end);      // Right sub array
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
    int start = 0, end = size;

    print_array(array, size);
    quick_sort(array, start, end);
    print_array(array, size);
}