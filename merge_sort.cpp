#include<iostream>

const int MAX_ARRAY_SIZE = 10000000;

void merge_sort(double *array,uint16_t array_size){
    if(array_size <= 1) return; // critical to stop recursion

    int16_t middle = array_size / 2;
    double *left = array; 
    double *right = array + middle;// pointer to the middle of the array
    int16_t left_size = middle;
    int16_t right_size = array_size - middle;

    // recursion goes here
    merge_sort(left, left_size);
    merge_sort(right, right_size);

    // Merge these two already sorted halfs of the array
    double *buffer = new double[array_size];
    int16_t left_index = 0;
    int16_t right_index = 0;
    int16_t buffer_index = 0;
    while(left_index < left_size && right_index < right_size){
        if(left[left_index] <= right[right_index]){
            //taking the lesser from left part of array  
            buffer[buffer_index] = left[left_index];// copying to buffer
            left_index++;// moving to the next element
        } else {
            // taking the lesser from right part of array
            buffer[buffer_index] = right[right_index];
            right_index++;
        }
        buffer_index++;
    }

    while(left_index < left_size){// copying the rest of the left part of array (if there is left somethink)
        buffer[buffer_index] = left[left_index];
        left_index++;
        buffer_index++;
    }
    while(right_index < right_size){// copying the rest of the right part of array (if there is left somethink)
        buffer[buffer_index] = right[right_index];
        right_index++;
        buffer_index++;
    }

    // copying the sorted array from buffer to the original array
    for(int16_t i = 0; i < array_size; i++){
        array[i] = buffer[i];
    }

    delete[] buffer;
}

void print_array(double *Array, uint16_t array_size){
    for (uint16_t i = 0; i < array_size; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << std::endl;
}

void input_array(double *Array, uint16_t array_size){
    std::cout << "Введите элементы массива: ";
    for (uint16_t i = 0; i < array_size; i++){
        std::cin >> Array[i];
    }
}

int main(){
    uint16_t array_size = 0;
    std::cout << "Введите количество элементов массива: ";
    std::cin >> array_size;
    if (array_size < 1 or array_size > MAX_ARRAY_SIZE) {
        std::cout << "Некорректное количество элементов массива" << std::endl;
        return -1;
    }
    double *Array = new double[array_size];

    input_array(Array, array_size);
    merge_sort(Array, array_size);
    print_array(Array, array_size);

    delete[] Array;
    return 0;
}